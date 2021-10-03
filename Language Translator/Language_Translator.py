from tkinter import *
from textblob import TextBlob
from tkinter.ttk import Combobox

root = Tk()
root.geometry('500x400')
root.title('Language Translator')
root.iconbitmap('translater.ico')
root.resizable(False, False)
root.configure(bg='Black')
######################################################################## Translation Code
def tt(event=None):
    try:
        word3 = TextBlob(varname1.get())
        lan = word3.detect_language()
        lan_to_dict = languages.get()
        lan_to = lan_dict[lan_to_dict]
        word3 = word3.translate(from_lang=lan, to=lan_to)
        varname2.set(word3)
    except:
        varname2.set('Try Another Word')

def main_reset():
    varname1.set("")
    varname2.set("")
######################################################################## Binding Function
def on_enterentry1(e):
    entry1['bg'] = 'skyblue'
def on_leaveentry1(e):
    entry1['bg'] = 'white'

def on_enterentry2(e):
    entry2['bg'] = 'skyblue'
def on_leaveentry2(e):
    entry2['bg'] = 'white'

def on_enterbtn1(e):
    btn1['bg'] = 'skyblue'
def on_leavebtn1(e):
    btn1['bg'] = 'yellow'

def on_enterbtn2(e):
    btn2['bg'] = 'skyblue'
def on_leavebtn2(e):
    btn2['bg'] = 'yellow'

######################################################################## Combobox
lan_dict = {'afrikaans': 'af', 'albanian': 'sq', 'amharic': 'am', 'arabic': 'ar', 'armenian': 'hy', 'azerbaijani': 'az', 'basque': 'eu', 'belarusian': 'be', 'bengali': 'bn', 'bosnian': 'bs', 'bulgarian': 'bg', 'catalan': 'ca', 'cebuano': 'ceb', 'chichewa': 'ny', 'chinese (simplified)': 'zh-cn', 'chinese (traditional)': 'zh-tw', 'corsican': 'co', 'croatian': 'hr', 'czech': 'cs', 'danish': 'da', 'dutch': 'nl', 'english': 'en', 'esperanto': 'eo', 'estonian': 'et', 'filipino': 'tl', 'finnish': 'fi', 'french': 'fr', 'frisian': 'fy', 'galician': 'gl', 'georgian': 'ka', 'german': 'de', 'greek': 'el', 'gujarati': 'gu', 'haitian creole': 'ht', 'hausa': 'ha', 'hawaiian': 'haw', 'hebrew': 'he', 'hindi': 'hi', 'hmong': 'hmn', 'hungarian': 'hu', 'icelandic': 'is', 'igbo': 'ig', 'indonesian': 'id', 'irish': 'ga', 'italian': 'it', 'japanese': 'ja', 'javanese': 'jw', 'kannada': 'kn', 'kazakh': 'kk', 'khmer': 'km', 'korean': 'ko', 'kurdish (kurmanji)': 'ku', 'kyrgyz': 'ky', 'lao': 'lo', 'latin': 'la', 'latvian': 'lv', 'lithuanian': 'lt', 'luxembourgish': 'lb', 'macedonian': 'mk', 'malagasy': 'mg', 'malay': 'ms', 'malayalam': 'ml', 'maltese': 'mt', 'maori': 'mi', 'marathi': 'mr', 'mongolian': 'mn', 'myanmar (burmese)': 'my', 'nepali': 'ne', 'norwegian': 'no', 'odia': 'or', 'pashto': 'ps', 'persian': 'fa', 'polish': 'pl', 'portuguese': 'pt', 'punjabi': 'pa', 'romanian': 'ro', 'russian': 'ru', 'samoan': 'sm', 'scots gaelic': 'gd', 'serbian': 'sr', 'sesotho': 'st', 'shona': 'sn', 'sindhi': 'sd', 'sinhala': 'si', 'slovak': 'sk', 'slovenian': 'sl', 'somali': 'so', 'spanish': 'es', 'sundanese': 'su', 'swahili': 'sw', 'swedish': 'sv', 'tajik': 'tg', 'tamil': 'ta', 'telugu': 'te', 'thai': 'th', 'turkish': 'tr', 'ukrainian': 'uk', 'urdu': 'ur', 'uyghur': 'ug', 'uzbek': 'uz', 'vietnamese': 'vi', 'welsh': 'cy', 'xhosa': 'xh', 'yiddish': 'yi', 'yoruba': 'yo', 'zulu': 'zu'}
languages = StringVar()
font_box = Combobox(root, width=30, textvariable=languages, state='readonly')
font_box['values'] = [e for e in lan_dict.keys()]
font_box.place(x=300, y=0)
font_box.set('Choose Output Language')
######################################################################## Entry Box
varname1 = StringVar()
entry1 = Entry(root,width=30, textvariable=varname1, font=('times', 15, 'italic bold'))
entry1.place(x=150, y=70)

varname2 = StringVar()
entry2 = Entry(root,width=30, textvariable=varname2, font=('times', 15, 'italic bold'))
entry2.place(x=150, y=150)
########################################################################## Label
label1 = Label(root, text='Enter Word : ', font=('times', 15, 'italic bold'), bg='black', fg='white')
label1.place(x=5, y=70)

label2 = Label(root, text='Translated : ', font=('times', 15, 'italic bold'), bg='black', fg='white')
label2.place(x=5, y=150)
########################################################################### Button
imgbt1 = PhotoImage(file='clicking.png')
imgbt2 = PhotoImage(file='logout.png')

imbt1 = imgbt1.subsample(16, 16)
imbt2 = imgbt2.subsample(16, 16)

btn1 = Button(root, text='Click', bd=10, bg='yellow', activebackground='red', width=100, font=('times', 15, 'italic bold'),
              image=imbt1, compound=RIGHT, command=tt)
btn1.place(x=70, y=240)

btn2 = Button(root, text='Reset ', bd=10, bg='yellow', activebackground='red', width=100, font=('times', 15, 'italic bold'),
              image=imbt2, compound=RIGHT, command=main_reset)
btn2.place(x=280, y=240)
root.bind('<Return>', tt)
############################################################################# Binding
entry1.bind('<Enter>', on_enterentry1)
entry1.bind('<Leave>', on_leaveentry1)

entry2.bind('<Enter>', on_enterentry2)
entry2.bind('<Leave>', on_leaveentry2)

btn1.bind('<Enter>', on_enterbtn1)
btn1.bind('<Leave>', on_leavebtn1)

btn2.bind('<Enter>', on_enterbtn2)
btn2.bind('<Leave>', on_leavebtn2)
############################################################################# Created by


root.mainloop()
