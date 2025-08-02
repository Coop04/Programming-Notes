import cv2 as cv

# # Reading Images

# img = cv.imread('resources/Photos/cat.jpg')
# cv.imshow('Cat', img) # Cat is the name we give the window to open the image 
#                       # img is the matrix of pixels to display

# cv.waitKey(0) # The image window opened by cv.imshow() will stay open until a key is pressed.

# --------------------------------------------------------------------------------------
# Reading Videos

capture = cv.VideoCapture('resources/Videos/dog.mp4')
# this method takes in either an interger value (like 0,1,2, etc) if using webcam (in most cases the webcam will be referenced by 0, if multiple cameras are connected to the computer other integers are used)
# or a path

# here we are using a while loop and reading the video frame by frame
while True:
    isTrue, frame = capture.read()
    cv.imshow('Video', frame) # showing each frame

    if cv.waitKey(20) & 0xFF==ord('d'): # To stop the video from running indefinitely: Since this condition is inside a while loop, cv.waitKey(20) waits for 20 ms after displaying each frame, and checks if 'd' is pressed (using & 0xFF for cross-platform key detection) during that time. If 'd' is pressed, it breaks out of the loop.
        break
    # if nothing is pressed the video will exit automatically returning a (-215:Assertion failed), this is because the video has ran out of frames ie, the video has ended

capture.release()
cv.destroyAllWindows()
# -------------------------------------------------------------------------------------