import cv2 as cv
import numpy as np

# to create a blank image
blank = np.zeros((500,500,3), dtype='uint8') # uint8 is the data type of an image
                                             # (500,500,3): (height, width, no. of colour channels)
cv.imshow('Blank image', blank)
cv.waitKey()
cv.destroyAllWindows()

# 1. Paint the image a certain colour
blank[:] = 0,255,0 # green
cv.imshow('Green', blank)
cv.waitKey() # cv.waitKey() and cv.destroyAllWindows() are used to open each windows one by one after closing the previous one
cv.destroyAllWindows()

# 1.2. We can also give colour to a range of pixels
blank[200:300, 300:400] = 255,0,0
cv.imshow('Red Square', blank)
cv.waitKey()
cv.destroyAllWindows()

# 2. Draw a rectangle
cv.rectangle(blank, (0,0), (255,255), (0,0,255), thickness=2)
cv.imshow('Rectangle', blank)
cv.waitKey()
cv.destroyAllWindows()

# 2.2 Filling a certain portion
cv.rectangle(blank, (0,0), (255,500), (0,0,255), thickness=cv.FILLED) # same as thickness=-1
cv.imshow('Rectangle', blank)
cv.waitKey()
cv.destroyAllWindows()

# 2.3 instead of specifing the co-ordinates
cv.rectangle(blank, (0, 0), (blank.shape[1]//2, blank.shape[0]//2), (0,0,100), thickness=-1)
cv.imshow('Rectangle', blank)
cv.waitKey()
cv.destroyAllWindows()

# 3. Draw a circle
cv.circle(blank, (blank.shape[1]//2, blank.shape[0]//2), 40, (0,100,100), thickness=3)
cv.imshow('Circle', blank)
cv.waitKey()
cv.destroyAllWindows()

# 4. Draw a line
cv.line(blank, (0,0), (blank.shape[1]//2, blank.shape[0]//2), (255,255,255))
cv.imshow('Line', blank)
cv.waitKey()
cv.destroyAllWindows()

# Write text
cv.putText(blank, 'Hello!', (400,400), cv.FONT_HERSHEY_TRIPLEX, 1.0, (0,0,0), thickness=2)
cv.imshow('Text', blank)
cv.waitKey()
cv.destroyAllWindows()