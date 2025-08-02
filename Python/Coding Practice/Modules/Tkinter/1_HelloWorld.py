from tkinter import *

# widgets = GUI elements: buttons, textboxes, lables, images
# windows = serves as a container to hold or contain these widgets

window = Tk() # instantiate an instance of a window
window.geometry('420x420')
window.title('Hello World GUI')

# to change the window icon, first we need to comvert the image into a photo image
icon = PhotoImage(file='CampusFlow.png')
window.iconphoto(True,icon) # now window icon is replaced

window.config(background='blue') # can use hex values also

window.mainloop() # place window on computer screen, listen for events

