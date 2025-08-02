import cv2 as cv

img = cv.imread('resources/Photos/cat.jpg')
cv.imshow('Cat', img)

# 1. Converting an image into gray scale
grey = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Grey', grey)

# 2. Blur (reducing noice)
blur = cv.GaussianBlur(img, (3,3), cv.BORDER_DEFAULT)
cv.imshow('Blur', blur)

# 2.2 To increase the blur increase the kernal size (kernal values should be odd)
blur2 = cv.GaussianBlur(img, (7,7), cv.BORDER_DEFAULT)
cv.imshow('Blur2', blur2)

# 3. Edge Cascaade (edge detection)
canny = cv.Canny(img, 125, 175)
cv.imshow('Canny', canny)

# 3.2 We can reduce the no. of edges by blurring the image, ie, by passsing blured image instead of the original image
canny2 = cv.Canny(blur, 125, 175)
cv.imshow('Canny2', canny2)

cv.waitKey()