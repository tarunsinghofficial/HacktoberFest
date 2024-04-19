from tkinter import *
from typing import Collection

root = Tk()
root.title('Simple Calculator')

# Input 
e = Entry(root, width=35, borderwidth=5)
e.grid(row=0, column=0, columnspan=3, padx=10, pady=10)

def button_insert(number):
    global num1
    if num1 != 0 and operator == '.':
        e.delete(0, END)
        e.insert(0,str(number))
        num1 = 0
    else:
        current = e.get()
        e.delete(0, END)
        e.insert(0,(str(current)+ str(number)))

button_0 = Button(root, text="0", padx=40, pady=20, command=lambda : button_insert(0))
button_1 = Button(root, text="1", padx=40, pady=20, command=lambda : button_insert(1))
button_2 = Button(root, text="2", padx=40, pady=20, command=lambda : button_insert(2))
button_3 = Button(root, text="3", padx=40, pady=20, command=lambda : button_insert(3))
button_4 = Button(root, text="4", padx=40, pady=20, command=lambda : button_insert(4))
button_5 = Button(root, text="5", padx=40, pady=20, command=lambda : button_insert(5))
button_6 = Button(root, text="6", padx=40, pady=20, command=lambda : button_insert(6))
button_7 = Button(root, text="7", padx=40, pady=20, command=lambda : button_insert(7))
button_8 = Button(root, text="8", padx=40, pady=20, command=lambda : button_insert(8))
button_9 = Button(root, text="9", padx=40, pady=20, command=lambda : button_insert(9))

button_7.grid(row=3, column=0)
button_8.grid(row=3, column=1)
button_9.grid(row=3, column=2)
button_4.grid(row=4, column=0)
button_5.grid(row=4, column=1)
button_6.grid(row=4, column=2)
button_1.grid(row=5, column=0)
button_2.grid(row=5, column=1)
button_3.grid(row=5, column=2)
button_0.grid(row=6, column=0)

num1 = 0
num2 = 0
operator = '.'

def button_add():
    global num1
    current = e.get()
    if len(current) > 0: 
        num1 = int(e.get())
        e.delete(0, END)
        global operator
        operator = '+'

def button_minus():
    global num1
    current = e.get()
    if len(current) > 0:
        num1 = int(e.get())
        e.delete(0, END)
        global operator
        operator = '-'

def button_multiply():
    global num1
    current = e.get()
    if len(current) > 0:
        num1 = int(e.get())
        e.delete(0, END)
        global operator
        operator = '*'

def button_divide():
    global num1
    current = e.get()
    if len(current) > 0:
        num1 = int(e.get())
        e.delete(0, END)
        global operator
        operator = '/'

def button_calc():

    global operator
    global num1
    global num2

    if operator == '.':
        return

    num2 = int(e.get())

    if operator == '.':
        return
    else:
        e.delete(0, END)

        if operator == '+':
            e.insert(0, str(num1+num2))
            num1 = num1+num2
        elif operator == '-':
            e.insert(0, str(num1-num2))
            num1 = num1-num2
        elif operator == '*':
            e.insert(0, str(num1*num2))
            num1 = num1*num2
        elif operator == '/':
            e.insert(0, str(int(num1/num2)))
            num1 = num1/num2
        
        operator = '.'
        num2 = 0

button_add = Button(root, text="+", padx=39, pady=20, command=button_add)
button_minus = Button(root, text="-", padx=41, pady=20, command=button_minus)
button_multiply = Button(root, text="x", padx=40, pady=20, command=button_multiply)
button_divide = Button(root, text="/", padx=41, pady=20, command=button_divide)

button_add.grid(row=1, column=0)
button_minus.grid(row=1, column=1)
button_multiply.grid(row=2, column=0)
button_divide.grid(row=2, column=1)

def button_back():
    current = e.get()
    if(len(current) > 0):
        current = current[:-1]
        e.delete(0, END)
        e.insert(0, current)

def button_clear():
    e.delete(0, END)

button_backspace = Button(root, text="C", padx=39, pady=20, command=button_back)
button_clear = Button(root, text="CE", padx=36, pady=20, command=button_clear, bg='lightblue')
button_backspace.grid(row=1, column=2)
button_clear.grid(row=2, column=2)

button_enter = Button(root, text="=", padx=87, pady=20, command=button_calc, bg='red')
button_enter.grid(row=6, column=1, columnspan=2)

root.mainloop()
