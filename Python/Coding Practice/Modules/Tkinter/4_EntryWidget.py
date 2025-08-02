#entry widget = textbox that accepts a single line of user input

from tkinter import *

window = Tk()
# window.geometry('500x400')

def submit():
    username = entry.get()
    print('Hello',username)

def delete():
    entry.delete(0,END) # deletes the line of text

def backspace():
    entry.delete(len(entry.get())-1,END) 


submit = Button(window,text='Submit',command=submit)
# submit.pack(side=BOTTOM)
# submit.place(x=100,y=100)
submit.grid(row=1, column=0) # when using grid all dont use pack in the same program

delete = Button(window,text='Delete',command=delete)
# delete.pack(side=BOTTOM)
delete.grid(row=1, column=1)

backspace = Button(window,text='Backspace',command=backspace)
# backspace.pack(side=BOTTOM)
backspace.grid(row=1, column=2)

entry = Entry()
entry.config(font=('Inc Free',50),
             bg='black',
             fg='#00ff00',)
# entry.insert(0,'Spongebob') # default text
# entry.config(state=DISABLED) # to disable the text box (ACTIVE/DISABLED)
entry.config(width=10)
# entry.config(show='*') # to replace the charecters  in the textbox with the given charecter (like for passwords)



# entry.pack()
entry.grid(row=0, column=0, columnspan=3)  # Place the entry widget below the buttons

window.mainloop()