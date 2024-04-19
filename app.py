from flask import Flask , render_template , request , redirect , url_for , session, send_file, jsonify , flash
# from flask_sqlalchemy import SQLAlchemy
# from flask_mysqldb import MySQL 
import mysql.connector
# import MySQLdb.cursors
# import hashlib
from backend.utils.encryption_scheme import is_password_valid, encrypt_password
from backend.utils.dashboard import get_wallet_data
from backend.utils.marketandp2p import get_market_data, get_fav_crypto_list, get_fav_page_data, get_p2p_buy_page_data, get_p2p_sell_page_data, form_graph , add_usdt_to_wallet_when_bought_from_p2p, deduct_usdt_from_wallet_when_released_in_p2p, update_p2p_trade_history, update_p2p_bid
from backend.utils.order_and_wallet import add_order, get_order_history, change_wallet
from backend.utils.userprofile import get_user_profile, change_pass_help , validate_user_while_login , check_email_exists , add_new_user
from backend.utils.transaction_history import get_transaction_history_data
from backend.utils.kyc_api import get_kyc_status,approve_kyc_status,is_single_face
from backend.utils.fetch_crypto_data_ccxt import fetch_market_page_data, fetch_specific_currency_data, fetch_all_currency_data
# import backend.utils.validate_fake_data
# import read_n_write_image_with_sql
from backend.utils.image import is_allowed_file, convert_to_writable
from backend.utils.otp import is_valid_domain, send_otp
# import mysql.connector
import pandas as pd
import matplotlib.pyplot as plt
from backend.utils.chat import update_chat_txt, get_chat_list
import json
from datetime import datetime, timedelta
import re 
import os
import base64
import io
from PIL import Image
from time import sleep
from flask import make_response

app = Flask(__name__, static_folder=os.path.join(os.getcwd(), 'frontend', 'static'), template_folder=os.path.join(os.getcwd(), 'frontend', 'templates'))

app.secret_key = 'Teamwork123'

db = mysql.connector.connect(
    host="localhost",
    user="root",
    password="Teamwork123",
    database="Coinfun_database",
    autocommit=True
)

@app.route('/')
def first():
    return render_template('login.html', msg = '')

@app.route('/login', methods =['POST'])
def login():
    cursor = db.cursor()
    try:
        message = ''
        if request.method == 'POST' and 'email' in request.form and 'password' in request.form:
            email_id = request.form['email']
            password = request.form['password']	
            account = validate_user_while_login(email_id, password)
            if(account == True):
                data = get_user_profile(email_id)
                session['loggedin'] = True
                session['id'] = data['email_id'].lower()
                session['username'] = data['username']
                message = 'Logged in successfully!'
                cursor.close()
                
                try:
                    fetch_market_page_data()
                except:
                    pass
                
                return redirect(url_for('dashboard',userid=session['id']))
            else:
                message = 'Invalid email id or password!'
    except Exception as e:
        message = str(e)
        if( message == "PasswordEncryptionFailed!"):
            message = "Invalid email id or password!"
    cursor.close()
    return render_template('login.html', msg = message)

@app.route('/register', methods=['POST','GET'])
def register():
    cursor = db.cursor()
    try:
        msg = ''
        if request.method == 'POST' and 'username' in request.form and 'email' in request.form and 'password' in request.form and 'confirm-password' in request.form and 'phone-number' in request.form:
            username = request.form['username']
            password = request.form['password']
            email_id = request.form['email'].lower()
            confirm_password=request.form['confirm-password']
            phone_number = request.form['phone-number']
            pic = ""

            if(check_email_exists(email_id) == True):
                raise Exception('Email Account already exists!')
            elif not re.match(r'[^@]+@[^@]+\.[^@]+', email_id):
                raise Exception('Invalid email address !')
            elif is_valid_domain(email_id)==False:
                raise Exception('Please use gmail, yahoo, outlook , hotmail or iitd.ac.in domain')
            elif not re.match( r'^[A-Za-z0-9]+$' , username):
                raise Exception('Username must contain only characters and numbers!')
            elif password!=confirm_password:
                raise Exception("Your password does not matches the confirm password !")
            elif is_password_valid(password) == False:
                raise Exception("Please enter a valid password, it should contain atleast 1 capital and 1 small alphabets and atleast 1 digit with length between 8-25")
            else:
                add_new_user( email_id, username, encrypt_password(password), phone_number)
                db.commit()
                data = get_user_profile(email_id)
                session['loggedin'] = True
                session['id'] = data['email_id']
                session['username'] = data['username']
                message = 'You have successfully registered !'
                cursor.close()
                
                try:
                    fetch_market_page_data()
                except:
                    pass
                
                return redirect(url_for('dashboard'))
        elif request.method == 'POST':
            cursor.close()
            raise Exception('Please fill all the blank columns !')
    except Exception as e:
        msg = str(e)
        if( msg == "PasswordEncryptionFailed!"):
            msg = "Please enter a valid password, it should contain atleast 1 capital and 1 small alphabets and atleast 1 digit with length between 8-25"
    cursor.close()
    return render_template('register.html', msg = msg)

@app.route('/dashboard')
def dashboard():
    msg = ''
    data = []
    cursor = db.cursor()
    try:
        data= get_wallet_data(session['id'])
        data_ = data['data']
        data_ = [{**d, 'price': str(round(float(d['price']), 2))} for d in data_]
        data_ = [{**d, 'amount': str(round(float(d['amount']), 4))} for d in data_]
        data_ = [{**d, 'est_balance': str(round(float(d['est_balance']), 3))} for d in data_]
        data['data'] = data_
    except Exception as e:
        msg = str(e)
    cursor.close()
    return render_template('dashboard.html',data=data,msg=msg)
    
@app.route('/transaction')
def transaction():
    cursor = db.cursor()
    data = []
    msg = ''
    try:
        data = get_transaction_history_data(session['id'])
    except Exception as e:
        msg = str(e)
    cursor.close()
    return render_template('transaction.html',data=data,msg=msg)

@app.route('/otp_verification', methods=['POST','GET'])
def otp_verification():
    msg=''
    try:
        cursor = db.cursor()
        if request.method == 'POST' and 'otp' in request.form:
            entered_otp = request.form['otp']
            if entered_otp == session['otp']:
                cursor.close()
                return redirect(url_for('reset_password'))
            else:
                cursor.close()
                return render_template('otp.html', msg='Invalid OTP. Please try again.')
        elif request.method == 'POST':
            cursor.close()
            return render_template('otp.html', msg='Please enter OTP.')
    except Exception as e:
        msg = str(e)
    cursor.close()
    return render_template('otp.html', msg = msg)

@app.route('/resend_otp')
def resend_otp():
    session['otp'] = send_otp(session['id'])
    return render_template('otp.html')

@app.route('/enter_email', methods=['POST','GET'])
def enter_email():
    cursor = db.cursor()
    msg = ''
    try:
        if request.method == 'POST' and 'email' in request.form:
            email = request.form['email']
            if (check_email_exists(email)==False):
                raise Exception('Account does not exists!')
            elif is_valid_domain(email)==False:
                raise Exception('Invalid email address domain, Please use gmail or iitd.ac.in :)!')
            else:
                try:
                    session['otp'] = str(send_otp(session['id']))
                    print(session['otp'])
                except Exception as e:
                    raise e
                msg = 'OTP sent successfully to your registered email ID'
                session['id'] = email
                cursor.close()
                return redirect(url_for('otp_verification'))
        elif request.method == 'POST':
            msg = 'Please enter the email !'
    except Exception as e:
        msg = str(e)
    cursor.close()
    return render_template('enter_email.html', msg = msg)

@app.route('/reset_password', methods=['POST','GET'])
def reset_password():
    msg = ''
    cursor = db.cursor()
    try:
        if request.method == 'POST' and 'new_password' in request.form and 'confirm_new_password' in request.form:
            newpass = request.form['new_password']
            newpass_confirm = request.form['confirm_new_password']
            if (newpass != newpass_confirm):
                msg = 'New Password does not matches the Confirm Password !' 
            else:
                cursor.execute('UPDATE userinfo SET password = %s where email_id = %s',(encrypt_password(newpass),session['id'],))
                db.commit()
                msg = 'Password updated successfully !'
                cursor.close()
                return redirect(url_for("first"))
        elif request.method == 'POST':
            msg = 'Please fill all the blank columns !'
    except Exception as e:
        msg = str(e)
    cursor.close()
    return render_template('newpassword.html',msg=msg)

@app.route('/market_allcrypto')
def market_allcrypto():
    json_data = []
    # data = []
    cursor = db.cursor()
    msg = ''
    try:
        json_data=get_market_data(session['id'])
        # cursor = mysql.connection.cursor(MySQLdb.cursors.DictCursor)
        # data = get_fav_crypto_list(session['id'])
    except Exception as e:
        msg = str(e)
        print(e)
    cursor.close()
    return render_template('market_allcrypto.html',jsondata=json_data,msg=msg)
    
@app.route('/mark_fav/<string:fav>')
def mark_fav(fav):
    try:
        cursor = db.cursor()
        cursor.execute('Select favourites from userinfo where email_id = %s',(session['id'],))
        favourite = cursor.fetchone()[0]
        favourites_list = favourite.split(",")
        if fav.strip() not in favourites_list:
            favourites_list.append(fav.strip())
            favourites_list = [x for x in favourites_list if x != '']
            new_favourites = ",".join(favourites_list)
            print(new_favourites)
            query = "UPDATE userinfo SET favourites = %s WHERE email_id = %s"
            cursor.execute(query, (new_favourites, session['id']))
            db.commit()
            cursor.close()
        return redirect(url_for('market_allcrypto'))
    except mysql.connector.Error as e:
        db.rollback()
        print(get_fav_crypto_list(session['id']), "list after mark fav is ending")
        print(str(e))
        cursor.close()
        return redirect(url_for('market_allcrypto'))
    except:
        print(1)
        cursor.close()
        return redirect(url_for('market_allcrypto'))

@app.route('/mark_unfav/<string:fav>')
def mark_unfav(fav):
    try:
        cursor = db.cursor()
        cursor.execute('Select favourites from userinfo where email_id = %s',(session['id'],))
        favourites = (cursor.fetchone()[0]).split(',')
        if fav in favourites:
            favourites = [x for x in favourites if x != fav]
            favourites = ",".join(favourites)
            print(favourites)
            cursor.execute("UPDATE userinfo SET favourites = %s WHERE email_id =%s",(favourites,session['id'],))
            db.commit()
        #print(get_fav_crypto_list(session['id']), "list after mark unfav is ending")
        cursor.close()
        print(2)
        return redirect(url_for('market_allcrypto'))
    except mysql.connector.Error as e:
        print(3)
        db.rollback()
        print(4)
        cursor.close()
        print(5)
        return redirect(url_for('market_allcrypto'))
    except Exception as e:
        msg = str(e)
        print(str(e), "6")
        cursor.close()
        print(7)
        return redirect(url_for('market_allcrypto'))

@app.route('/p2p_buy')
def p2p():
    list_ = []      # This is the code for p2p buy page
    msg = ''
    cursor = db.cursor()
    try:
        list_ = get_p2p_buy_page_data()
        list_ = sorted(list_, key=lambda x: x['price'])
    except Exception as e:
        msg = str(e)
    cursor.close()
    return render_template('p2p_buy.html',data=list_,msg=msg)

@app.route('/p2p_sell')
def p2p_sell():
    list_ = []    # This is the code for p2p sell page
    msg = ''
    cursor = db.cursor()
    try:
        list_ = get_p2p_sell_page_data()
        list_ = sorted(list_, key=lambda x: -x['price'])
    except Exception as e:
        msg = str(e)
    cursor.close()
    return render_template('p2p_sell.html',data=list_,msg=msg)
    
@app.route('/p2p_add_usdt/<float:balance>')  
def p2p_add_usdt(email_id, balance_to_add):
    try:
        #email_id = session['id']
        add_usdt_to_wallet_when_bought_from_p2p(email_id, balance_to_add)
        return redirect(url_for('p2p_buy'))
    except:
        return redirect(url_for('p2p_buy'))

@app.route('/p2p_deduct_usdt/<float:balance>')  
def p2p_deduct_usdt(email_id, balance_to_deduct):
    try:
        #email_id = session['id']
        deduct_usdt_from_wallet_when_released_in_p2p(email_id, balance_to_deduct)
        return redirect(url_for('p2p_sell'))
    except:
        return redirect(url_for('p2p_sell'))
        
@app.route('/change_password',methods = ['POST','GET'])
def change_password():
    msg = ''
    cursor = db.cursor()
    if request.method == 'POST' and 'password' in request.form and 'new_password' in request.form and 'confirm_new_password' in request.form:
        current_pass = request.form['password']
        newpass = request.form['new_password']
        newpass_confirm = request.form['confirm_new_password']
        try:
            msg =  change_pass_help(session['id'],current_pass,newpass,newpass_confirm)
        except Exception as e:
            msg = str(e)
    elif request.method == 'POST':
        msg = 'Please fill in all the blanks provided'
    cursor.close()
    return render_template('changepassword.html',msg=msg)
    
@app.route('/market_fav')
def market_fav():
    cursor = db.cursor()
    fav_details = []
    msg = ''
    try:
        print("in try of market_fav",session['id'])
        fav_details = get_fav_page_data(session['id'])
    except Exception as e:
        print("in except of market_fav")
        msg = str(e)
    print(msg)
    cursor.close()
    return render_template('market_fav.html',jsondata=fav_details,msg=msg)

@app.route('/user_profile')
def user_profile():
    cursor = db.cursor()
    data= {}
    msg = ''
    try:
        data = get_user_profile(session['id'])
        cursor.close()
        return render_template('user_profile.html', data=data,msg=msg)
    except Exception as e:
        msg = str(e)
        print(msg)
        cursor.close()
        return render_template('user_profile.html', data=data,msg=msg)

@app.route('/upload_pic',methods = ['GET','POST'])
def upload_pic():
    msg = ''
    cursor = db.cursor()
    if 'id' not in session:
        return redirect(url_for('login'))

    if request.method == "POST":
        try:
            print(request.files)
            if 'photo' in request.files:
                photo = request.files['photo']
                if photo.filename != '' and is_allowed_file(photo.filename): # Check if the file has an allowed image extension
                    # Read the binary data from the file
                    image_data = photo.read()
                    encoded_data = base64.b64encode(image_data) # Encode the binary data as base64
                    cursor.execute('UPDATE userinfo SET profile_pic = %s WHERE email_id = %s', (encoded_data.decode('UTF-8') , session['id']))
                    db.commit()
                    msg = 'IMAGE UPDATED SUCCESSFULLY!'
                    user_data= get_user_profile(session['id'])
                    user_data['profile_pic'] = encoded_data.decode("UTF-8")
                    cursor.close()
                    return jsonify({'msg':msg, 'profile_pic':user_data['profile_pic']})
                else:
                    raise Exception("Only png , jpg and jpeg format is allowed")
        except Exception as e:
            if(str(e)=='Only png , jpg and jpeg format is allowed'):
                msg = str(e)
            else:
                msg = "IMAGE CANNOT BE UPDATED!"
            user_data= get_user_profile(session['id'])
            cursor.close()
            return render_template('user_profile.html', data= user_data, msg=msg)


@app.route('/kyc', methods=['POST'])
def kyc():
    msg = ''
    if(get_kyc_status(session['id'])):
        return redirect(url_for('user_profile'))
    cursor = db.cursor()
    if 'id' not in session:
        return redirect(url_for('login'))
    if request.method == "POST":
        try:
            # print(request.files)
            if 'photo' in request.files:
                photo = request.files['photo']
                if photo.filename != '' and is_allowed_file(photo.filename): # Check if the file has an allowed image extension
                    # Read the binary data from the file
                    image_data = photo.read()
                    encoded_data = base64.b64encode(image_data) # Encode the binary data as base64
                    decoded_img = encoded_data.decode("UTF-8")
                    if (is_single_face(decoded_img)):
                        approve_kyc_status(session['id'])
                        msg = 'Congratulations! you are now a verified user'
                    else:
                        msg = "You couldn't be verified. Please Try Again !"
                elif photo.filename == '':
                    msg="Please select a photo in png, jpg or jpeg format showing your face clearly!"
                elif is_allowed_file(photo.filename)==False:
                    msg = "Only png, jpg or jpeg format are allowed"
                user_data= get_user_profile(session['id'])
                cursor.close()
                return render_template('user_profile.html',data=user_data,msg=msg)
        except Exception as e:
            msg = str(e)
            user_data= get_user_profile(session['id'])
            cursor.close()
            return render_template('user_profile.html',data=user_data,msg=msg)
            
@app.route('/order_history')
def order_history():
    cursor = db.cursor()
    history = []
    msg = ''
    try:
        history = get_order_history(session['id'])
    except Exception as e:
        msg = str(e)
    cursor.close()
    return render_template('order_history.html',history=history,msg=msg)
    
@app.route('/trade_page/<string:crypto>/<string:time_frame>')
def trade_page(crypto,time_frame):
    cursor = db.cursor()
    image = ''
    crypto_details = {}
    
    try:
        fetch_specific_currency_data(crypto+"/USDT", time_frame)
        fetch_market_page_data()
    except:
        pass
        
    try:
        (image,crypto_details) = form_graph(crypto,time_frame)
        wallet_data = get_wallet_data(session['id'])
        crypto_details["crypto_size"] = round(next((item['amount'] for item in wallet_data['data'] if item['symbol'] == crypto), 0),5)
        crypto_details["USDT"] = round( next((item['amount'] for item in wallet_data['data'] if item['symbol'] == 'USDT'), 0),2)
        crypto_details["Current_crypto_value"] = crypto_details["last_price"]*crypto_details["crypto_size"]
    except Exception as e:
        msg = str(e)
    cursor.close()
    return render_template('crypto_graph.html',image=image,data=crypto_details)

@app.route('/do_crypto_trade/<string:order_type>/<string:crypto>/<string:usdt_qty>')
def do_crypto_trade(order_type, crypto, usdt_qty):
    cursor = db.cursor()
    
    try:
        fetch_market_page_data()
    except:
        pass
    
    try:
        change_wallet(session['id'], order_type, crypto, usdt_qty)
    except Exception as e:
        msg = str(e)
        flash(msg)
        return redirect(url_for('trade_page', crypto=crypto, time_frame='1m', error=msg))
    cursor.close()
    return redirect(url_for('trade_page', crypto = crypto, time_frame="1m"))

@app.route('/chat_buy/<string:seller_mailID>',methods = ['GET','POST'])
def chat_buy(seller_mailID):
    cursor = db.cursor()
    print(1)
    if request.method == 'POST' and 'messageInput' in request.form:
        print('in post')
        message = request.form["messageInput"]
        try:
            print('updating')
            update_chat_txt(session['id'],session['id'],seller_mailID,message)
            print('update done')
            cursor.close()
            return redirect(url_for('chat_buy',seller_mailID=seller_mailID))
        except Exception as e:
            print('error')
            final = {}
            final['username'] = ''
            final['data'] = []
            final['my_mail'] = session['id']
            msg = str(e)
            cursor.close()
            return render_template('chat_buy.html',msg=msg,data=final,mail_id=seller_mailID)
    elif request.method == "POST" and 'photo' in request.files:
        photo = request.files['photo']
        try:
            update_chat_image(session['id'],session['id'],seller_mailID,photo)
            cursor.close()
            return redirect(url_for('chat_buy',seller_mailID=seller_mailID))
        except Exception as e:
            final = {}
            final['username'] = ''
            final['data'] = []
            final['my_mail'] = session['id']
            msg = str(e)
            cursor.close()
            return render_template('chat_buy.html',msg=msg,data=final,mail_id=seller_mailID)
    else:
        msg = ''
        # cursor = mysql.connection.cursor(MySQLdb.cursors.DictCursor)
        cursor.execute('SELECT chat_messages FROM chat WHERE (email_id1 = %s AND email_id2 = %s) OR (email_id1 = %s AND email_id2 = %s)',(session['id'],seller_mailID,seller_mailID,session['id'],))
        t = cursor.fetchone()
        cursor.execute('SELECT username from userinfo where email_id = %s',(seller_mailID,))
        final = {}
        final['username'] = cursor.fetchone()[0]
        final['my_mail'] = session['id']
        if t!=None:
            data = json.loads(t[0])
            final['data'] = data
            cursor.close()
            return render_template('chat_buy.html',data=final,msg=msg,mail_id = seller_mailID)
        else:
            msg="No Message"
            data = []
            final['data'] = data
            cursor.close()
            return render_template('chat_buy.html',data=final,msg=msg,mail_id=seller_mailID)

@app.route('/chat_sell/<string:buyer_mailID>',methods = ['GET','POST'])
def chat_sell(buyer_mailID):
    cursor = db.cursor()
    cursor.execute('SELECT email_id from userinfo where email_id=%s',(buyer_mailID,))
    mail_id = cursor.fetchone()[0]

    if request.method == 'POST' and 'messageInput' in request.form:
        message = request.form["messageInput"]
        print('hi')
        try:
            update_chat_txt(session['id'],buyer_mailID,session['id'],message)
            cursor.execute('SELECT chat_messages FROM chat WHERE (email_id1 = %s AND email_id2 = %s) OR (email_id1 = %s AND email_id2 = %s)',(session['id'],buyer_mailID,buyer_mailID,session['id'],))
            print(cursor.fetchone()[0])
            print(session['id'])
            cursor.close()
            return redirect(url_for('chat_sell',buyer_mailID=buyer_mailID))
        except Exception as e:
            final = {}
            print("in except")
            final['username'] = ''
            final['data'] = []
            msg = str(e)
            cursor.close()
            return render_template('chat_sell.html',msg=msg,data=final,mail_id=buyer_mailID)
        
    elif request.method == "POST" and 'photo' in request.files:
        print("here1")
        photo = request.files['photo']
        try:
            update_chat_image(session['id'],buyer_mailID,session['id'],photo)
            cursor.close()
            return redirect(url_for('chat_sell',buyer_mailID=buyer_mailID))
        except Exception as e:
            final = {}
            final['username'] = ''
            final['data'] = []
            msg = str(e)
            cursor.close()
            return render_template('chat_sell.html',msg=msg,data=final,mail_id=buyer_mailID)
    else:
        print('here2 get method')
        msg = ''
        # cursor = mysql.connection.cursor(MySQLdb.cursors.DictCursor)
        cursor.execute('SELECT chat_messages FROM chat WHERE (email_id1 = %s AND email_id2 = %s) OR (email_id1 = %s AND email_id2 = %s)',(session['id'],buyer_mailID,buyer_mailID,session['id'],))
        t = cursor.fetchone()
        cursor.execute('SELECT username from userinfo where email_id = %s',(buyer_mailID,))
        final = {}
        final['username'] = cursor.fetchone()[0]
        final['my_mail'] = session['id']
        if t!=None:
            data = json.loads(t[0])
            final['data'] = data
            cursor.close()
            return render_template('chat_sell.html',data=final,msg=msg,mail_id=buyer_mailID)
        else:
            data=[]
            final['data'] = data
            cursor.close()
            return render_template('chat_sell.html',data=final,msg=msg,mail_id=buyer_mailID)
        
@app.route('/release/<string:buyer_mailid>',methods = ['POST'])
def release(buyer_mailid):
    try:
        if request.method == 'POST' and 'amount' in request.form:
            print(1,request.form)
            amount = request.form['amount']
            print('HI',session['id'])
            
            if (deduct_usdt_from_wallet_when_released_in_p2p(session['id'], buyer_mailid, float(amount)) and add_usdt_to_wallet_when_bought_from_p2p(buyer_mailid, float(amount))):
                # flash(msg)
                print('HI')
                return redirect(url_for('p2p_sell'))
    except Exception as e:
        msg = str(e)
        print(msg, "release")
        # flash(msg)
        return redirect(url_for('chat_sell',buyer_mailID=buyer_mailid))

@app.route("/notifications", methods = ['GET','POST'])
def chat_notifications():
    msg=''
    try:
        data = get_chat_list(session['id'])
        if len(data)==0:
            msg='No Notifications'
        return render_template('notification.html',data=data,msg=msg)
    except:
        msg='Your chats could not be loaded , Please try again later'
        return render_template('notification.html',data=[],msg=msg)

# @app.route('/dropdown')
# def dropdown():
#     return render_template('dropdown.html')

if(__name__=="__main__"):
    app.run(debug=True)