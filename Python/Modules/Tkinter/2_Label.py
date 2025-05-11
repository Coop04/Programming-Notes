from tkinter import *


# label = an area widget that holds text and/or an image within a window

window = Tk()
window.geometry('420x420')

# to add an image 
photo = PhotoImage(file='CampusFlow.png') # also add image=photo inside the label constructor
photo = photo.subsample(4, 4)  # Reduce the image size by a factor of 2 (width, height)

label = Label(window,
              text='Hello World',
              font=('Areal',40,'bold'),
              fg='#00ff00',
              bg='black',
              relief=RAISED,bd=10, # bd means border
              padx=20,pady=20, # adds padding to the text
              image=photo,
              compound='bottom'    # we can set direction toplace the image relative to the text
              ) 
label.pack() # label will be added to the window
#  or
# label.place(x=0,y=0) # with place function we can place the label at a particular index

window.mainloop()