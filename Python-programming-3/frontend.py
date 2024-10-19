from tkinter import *
import backend  # Make sure this module is correctly defined

def get_selected_row(event):
    global selected_tuple
    try:
        index = list1.curselection()[0]
        selected_tuple = list1.get(index)
        e1.delete(0, END)
        e1.insert(END, selected_tuple[1])
        e2.delete(0, END)
        e2.insert(END, selected_tuple[2])
        e3.delete(0, END)
        e3.insert(END, selected_tuple[3])
        e4.delete(0, END)
        e4.insert(END, selected_tuple[4])
    except IndexError:
        pass  # Handle case when no item is selected

def view_command():
    list1.delete(0, END)
    for row in backend.view():
        list1.insert(END, row)

def search_command():
    list1.delete(0, END)
    for row in backend.search(title_text.get(), author_text.get(), year_text.get(), isbn_text.get()):
        list1.insert(END, row)

def add_command():
    backend.insert(title_text.get(), author_text.get(), year_text.get(), isbn_text.get())
    list1.delete(0, END)
    list1.insert(END, (title_text.get(), author_text.get(), year_text.get(), isbn_text.get()))
    clear_entries()  # Clear entry fields after adding

def delete_command():
    try:
        backend.delete(selected_tuple[0])
        clear_entries()  # Clear entry fields after deleting
    except NameError:
        pass  # Handle case when no item is selected

def update_command():
    try:
        backend.update(selected_tuple[0], title_text.get(), author_text.get(), year_text.get(), isbn_text.get())
    except NameError:
        pass  # Handle case when no item is selected

def clear_entries():
    """Clear all entry fields."""
    e1.delete(0, END)
    e2.delete(0, END)
    e3.delete(0, END)
    e4.delete(0, END)

window = Tk()
window.wm_title("BookStore")

# Labels
Label(window, text="Title").grid(row=0, column=0)
Label(window, text="Author").grid(row=0, column=2)
Label(window, text="Year").grid(row=1, column=0)
Label(window, text="ISBN").grid(row=1, column=2)

# Entry fields
title_text = StringVar()
e1 = Entry(window, textvariable=title_text)
e1.grid(row=0, column=1)

author_text = StringVar()
e2 = Entry(window, textvariable=author_text)
e2.grid(row=0, column=3)

year_text = StringVar()
e3 = Entry(window, textvariable=year_text)
e3.grid(row=1, column=1)

isbn_text = StringVar()
e4 = Entry(window, textvariable=isbn_text)
e4.grid(row=1, column=3)

# Listbox and scrollbar
list1 = Listbox(window, height=6, width=35)
list1.grid(row=2, column=0, rowspan=6, columnspan=2)

sb1 = Scrollbar(window)
sb1.grid(row=2, column=2, rowspan=6)

list1.configure(yscrollcommand=sb1.set)
sb1.configure(command=list1.yview)

list1.bind('<<ListboxSelect>>', get_selected_row)

# Buttons
Button(window, text="View all", width=12, command=view_command).grid(row=2, column=3)
Button(window, text="Search entry", width=12, command=search_command).grid(row=3, column=3)
Button(window, text="Add entry", width=12, command=add_command).grid(row=4, column=3)
Button(window, text="Update selected", width=12, command=update_command).grid(row=5, column=3)
Button(window, text="Delete selected", width=12, command=delete_command).grid(row=6, column=3)
Button(window, text="Close", width=12, command=window.destroy).grid(row=7, column=3)

# Footer
Label(window, text="Created By : Gaurav Kumar").grid(row=8, column=1, columnspan=4)

window.mainloop()

