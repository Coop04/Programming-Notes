# button = you click it, then it does stuff

from tkinter import *

count = 0
def click():
    global count # tells Python that you want to use and modify the global count variable, not create a new local one.
    count+=1
    # print(count)
    lable.config(text=count) # this helps to change the values of the count variable inside the window
    lable2.pack() # to show the label 2 when the button is clicked


window = Tk()
window.geometry('700x500')

button = Button(window,
                text='Click Me!!!')
button.config(command=click) # dont't include the parenthesis for the fn. call, performsw call back of function
button.config(font=('Ink Free',50,'bold'),
              bg='red',
              fg='black',
              activebackground='orange', # colour when being clicked
              activeforeground='white')

image = PhotoImage(file='CampusFlow.png')
image = image.subsample(7,7)
button.config(image=image, # 2nd image is the PhotoImage variable
              compound='top') # can be top, bottom, left, right

# to make the button active or disabled
# button.config(state='disabled') # active or disabled

# to display the count inside the window
lable = Label(window,text=count)
lable.config(font=('Monospace',50))
lable.pack()

button.pack()

# we can also add a picture along with the count
lable2 = Label(window,image=image)

window.mainloop()