import mysql.connector


mydb = mysql.connector.connect(host="localhost",user='root',passwd='thebeast',database='employees21')
mycursor = mydb.cursor()
mycursor.execute('select ename from emp1')


for i in mycursor:
    print (i)