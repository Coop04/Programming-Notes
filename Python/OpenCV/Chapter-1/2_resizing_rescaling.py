# We usually resize and rescale frames to avoid computational strain
# Note:
# "Resizing" means changing the image to specific dimensions (width and height). 
    # resized_image = cv.resize(image, (new_width, new_height), interpolation=cv.INTER_AREA)
# "Rescaling" means changing the image size by a scaling factor (proportionally).
    # rescaled_image = cv.resize(image, None, fx=scale_x, fy=scale_y, interpolation=cv.INTER_AREA) 
    # fx is the scale factor along the horizontal axis and fy along the vertical axis (in this code we are doing rescaling)
# In practice, both use cv.resize(), and the terms are often used interchangeably.

import cv2 as cv

def rescale_frame(frame, scale=0.5):
    # This method will work for Images, Videos, Live Videos
    width = int(frame.shape[1] * scale) # frame.shape = [height,width] 
    height = int(frame.shape[0] * scale)
    dimensions = (width, height)
    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA) # cv.resize will resize the frame to a particular dimension
    # Interpolation is the mathematical method used to calculate these new pixel values based on the surrounding pixels.(shrinking [removing pixels] / enlarging [adding new pixels])
    # Interpolation methods for resizing:
    # cv.INTER_AREA   : Good for shrinking images. Uses pixel area relation, gives better results when reducing size.
    # cv.INTER_LINEAR : Good for enlarging (zooming). Default for upscaling.
    # cv.INTER_CUBIC  : Better for enlarging, produces smoother results but is slower.
    # cv.INTER_NEAREST: Fastest, but lowest quality (uses nearest neighbor).

def change_res(width, height): # (not used in this program)
    #This method only works with Live Videos 
    capture.set(3,width)
    capture.set(4,height)

# Resizing Video
capture = cv.VideoCapture('resources/Videos/dog.mp4')
while True:
    isTrue, frame = capture.read()
    cv.imshow('Dog', frame)
    rescaled_vidframe = rescale_frame(frame)
    cv.imshow('Rescaled_dog', rescaled_vidframe)

    if cv.waitKey(20) & 0xFF==ord('d'):
        break
capture.release()
cv.destroyAllWindows()

# Resizing Photo
img = cv.imread('resources/Photos/cat.jpg')
resized_img = rescale_frame(img)
cv.imshow('Cat',img)
cv.imshow('Rescaled_cat', resized_img)
cv.waitKey() # pressing any key will close this cat windows
