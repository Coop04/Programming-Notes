from django.http import HttpResponse, HttpResponseNotFound

# def handler404(request, exception): # here 404 error message is not passed internally
#     return HttpResponse("<h1>404: Page not found!!!!!</h1>") 

# def handler404(request, exception):
    # return HttpResponseNotFound("<h1>404: Page not found!!!!!</h1>") # no visible changes from the above HttpResponse but 404 error message is passed internally (can be viewed with inspect tool (in networks))