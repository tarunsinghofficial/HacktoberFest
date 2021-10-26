"""here's a python program to generate a movie ticket"""

l=[]   #[name,location,movie,totprice,multi,time,sc,tick]
def name():
    name=input("ENTER YOUR NAME : ") 
    l.append(name)

def place():
    print("Where you want to watch movie? : ") 
    print("1. Marathalli") 
    print("2. Whitefield") 
    print("3. Kormangala") 
    city = int(input("enter location: "))
    q=''
    if city==1:
        q='Marathalli'
    if city==2:
        q='Whitefield'
    if city==3:
        q='Kormangala'
    l.append(q)

def currshow():
    print("Currently Showing : ") 
    print("1. Dolittle    -->400") 
    print("2. Bloodshot   -->410") 
    print("3. Knives Out  -->380") 
    print("4. Back.       -->490") 
    movie = int(input("Choose your movie : "))
    w=''
    if movie==1:
        w='Dolittle'
    if movie==2:
        w='Bloodshot'
    if movie==3:
        w='Knives Out'
    if movie==4:
        w='Back'
    l.append(w)
    tot_price=0
    if movie==1:
        tot_price+=400
    if movie==2:
        tot_price+=400
    if movie==3:
        tot_price+=400
    if movie==4:
        tot_price+=400
    l.append(tot_price)
      
def multi():
    print("In which multiplex do you wish to see movie? ")
    print("1. INOX       ") 
    print("2. PVR        ") 
    print("3. Cinepolis  ")
    a = int(input("Choose your option : "))
    e=''
    if a==1:
        e='INOX'
    if a==2:
        e='PVR'
    if a==3:
        e='Cinepolis'
    l.append(e)

    time1 ='''1. 10:30 AM - 12:30 PM 
    2. 2:00 PM - 4:00 PM 
    3. 6:00 PM - 8:00 PM 
    4. 10:00 PM - 12:00 AM'''
        
        
    time2 ='''1. 10:15 AM - 12:15 PM 
    2. 1:25 PM - 3:25 PM
    3. 4:35 PM - 6:35 PM 
    4. 7:45 PM - 8:45 PM'''
        
    time3 ='''1.  9:00 AM - 11:00 AM 
    2.  1:00 PM - 3:00 PM
    3.   6:00 PM - 8:00 PM
    4.   11:00 PM - 1:00 AM'''    
    
    if a==1:
        print(time1)
    if a==2:
        print(time2)
    if a==3:
        print(time3)
    
    time=int(input('select time: '))
    
    l.append(time)
    
    print("Would u like to have any of these: ")
    x='''1.coke - 100
2.popcorn - 200
3.nachos - 200
4. nothing'''
    print(x)
    u=int(input())
    
    if u==1:
        l[3]=l[3]+100
    if u==2:
        l[3]=l[3]+200
    if u==2:
        l[3]=l[3]+200
    if u==4:
        l[3]=l[3]+0
        
import random        
def screen():
    print('Tere are 3 screens in total')
    sc=random.randint(1,4)
    print("Your hall number is",sc)
    l.append(sc)

def nooftick():    
    tick=int(input('enter no.of tickets: '))
    l.append(tick)    
    l[3]=l[3]*tick
    
    print('NAME -',l[0]) 
    print('CITY -',l[1] )
    print('MOVIE -',l[2])
    print('MULTIPLEX-',l[4]) 
    print('TIME - ',l[5])
    print('SCREEN NO. -',l[6]) 
    print('NO. OF TICKETS -',l[7])
    print()
    print("proceed to payment?")

def payment():    
    print(" --------------------------------")
    print("\n Total Amount: ",l[3],"\t")
    print(" --------------------------------")              
    
    print(" Payment")
    print(" --------------------------------")
    print(" MODE OF PAYMENT")
    
    print(" 1- Credit/Debit Card")
    print(" 2- Paytm/PhonePe")
    print(" 3- Using UPI")
    print(" 4- Cash")
    
    c=int(input("enter mode of payment: "))
    if c in [1,2,3,4]:
        print("PAYMENT HAS BEEN DONE")
        
        print(" Thank You")
        print(" Visit Again :)")
        print(" --------------------------------\n")  
    else:
        print("invalid choice")

print("----------------------------------------------------------")
print("             WELCOME TO BRUH TICKET CENTRE                ") 
print("----------------------------------------------------------")
name()
print("MENU : ")
print("➤ Select location")
print("➤ Select movie")
print("➤ Select multiplex")
print("➤ Number of Tickets")
print("➤ Payment") 
print("----------------------------------------------------------")

place()
currshow()
multi()
screen()
nooftick()
payment()

        
    
