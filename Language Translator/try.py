from tkinter import *
from tkinter import ttk
import tkinter as tk
from googletrans import Translator , LANGUAGES

root = Tk()
text=Text(root)
root.geometry('1080x400')
root.resizable(0,0)
root.title("Language Translator")
root.config(bg = 'ghost white')


#heading
Label(root, text = " @_@ WELCOME @_@ ", font = ('Courier',15,'bold'), fg='blue', relief = tk.RIDGE, borderwidth = 5).place(x = 400 , y = 5)
Label(root,text =" - Presented by SATYAM TRIPATHI & SATYAM BAJPAI", font = 'arial 20 bold', bg ='white smoke' , width = '47', relief = GROOVE, borderwidth = 3).place(x=130,y=350)
label = Label(root, fg="red", width = '3', relief = GROOVE, borderwidth = 3, font = ('Courier',15,'bold'))

#INPUT AND OUTPUT TEXT WIDGET
Label(root,text ="Please Enter Text", font = 'arial 13 bold', bg ='mint cream').place(x=280,y=72)
Input_text = Text(root,font = 'arial 10', height = 11, wrap = WORD, padx=15, pady=15, width = 60)
Input_text.place(x=30,y = 100)


Label(root,text ="OUTPUT", font = 'arial 13 bold', bg ='mint cream').place(x=850,y=72)
Output_text = Text(root,font = 'arial 10', height = 11, wrap = WORD, padx=15, pady= 15, width =60)
Output_text.place(x = 600 , y = 100)

def Reset():
   Input_text.delete('1.0','end')
   Output_text.delete('1.0','end')

##################
language = list(LANGUAGES.values())
language=[lan.title() for lan in language]
fontExample = ("Courier", 10, "bold")
src_lang = ttk.Combobox(root, values= language, width =25,font=fontExample,state='readonly', justify = tk.CENTER,cursor="target")

src_lang.place(x=30,y=72)
src_lang.set('Choose Input Language')

dest_lang = ttk.Combobox(root, values= language, width =25,font=fontExample, state='readonly', justify = tk.CENTER,cursor="target")
dest_lang.place(x=600,y=72)
dest_lang.set('Choose Output Language')
########################################  Define function #######

def Translate():
    a = 3
    while a > 0:
      try:
            a-=1
            translator = Translator()
            translated = translator.translate(text=Input_text.get(1.0, END), src=src_lang.get(), dest=dest_lang.get())
            Output_text.delete(1.0, END)
            Output_text.insert(END, translated.text)

      except:
          a-=1
          translator = Translator()
          translated = translator.translate(text=Input_text.get(1.0, END), src=src_lang.get(), dest=dest_lang.get())
          Output_text.delete(1.0, END)
          Output_text.insert(END, translated.text)

##########  Translate Button ########
trans_btn = Button(root, text = 'Translate',font = 'arial 12 bold', pady=5,padx=4,bd=5, command = Translate , bg = "gold2")
trans_btn.place(x = 490, y = 180)
btnReset = Button(root, text="RESET", bg="OrangeRed2",font=('arial', 12, 'bold'), pady=5,padx=4,bd=5,command=Reset).place(x=500, y=260)
root.mainloop()