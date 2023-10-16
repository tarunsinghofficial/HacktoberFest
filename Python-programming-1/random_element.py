from tkinter import *
from random import sample, choice

App = Tk()
App.title('Element picker')
App.geometry('220x150')

inp = Entry(App, width=25)
inp.grid(row=0, column=0, columnspan=2, padx=25, pady=5)

no_choice = IntVar()
sld = Scale(App, from_=1, to=5, variable=no_choice, orient=HORIZONTAL)
sld.grid(row=1, column=0, columnspan=2, padx=25, pady=5)


def pick():
    INP = (inp.get()).split(',')

    if no_choice.get() != 1:
        ele = sample(INP, no_choice.get())
        lbl = ''
        for e in ele:
            lbl += ' ' + e
        chois = 'Choice:' + str(lbl)
    else:
        chois = 'Choice: ' + str(choice(INP))

    OutWin = Toplevel()
    OutWin.title('Output')

    msg = Label(OutWin, text=chois, width=25)
    msg.grid(row=3, column=0, columnspan=2, padx=25, pady=5)

    if quitB['state'] == DISABLED:
        quitB['state'] = NORMAL


B = Button(App, text='Choose', command=pick)
B.grid(row=2, column=0, padx=25, pady=5)

quitB = Button(App, text='Cancel', command=App.quit, state=DISABLED)
quitB.grid(row=2, column=1, padx=25, pady=5)

App.mainloop()
