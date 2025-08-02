from django.shortcuts import render

# Create your views here.
from django.http import HttpResponse

from myapp.forms import LogForm
from myapp.forms import DemoForm
from .models import Menu2

def home(request):
    return HttpResponse("Welcome to Little Lemons Restaurant!")

# def home1(request):
#     path = request.path # function requests the path
#     return HttpResponse(path, content_type = 'text/html', charset = 'utf-8') # function returns the path of the function
                                                                             # when /main/home1/ is appended with the url the output /main/home1/ is displayed
                                                                             # since main/ is given as a path for myapp in the urls.py(project)
def home1(request):
    path = request.path # function requests the path
    response = HttpResponse("This works! ")
    return response

def home2(request):
    path = request.path
    scheme = request.scheme
    method = request.method
    address = request.META['REMOTE_ADDR'] # provide info about the headers of the request object passed
    user_agent = request.META['HTTP_USER_AGENT']
    path_info = request.path_info

    #if you want to update the header information for both the http request and response objects
    response = HttpResponse() # HttpResponse() is an object
    response.headers['Age'] = 20

    # the request object info is displayed in the browser
    # The """ is used in Python to create multiline strings. These are also called triple-quoted strings and can be enclosed in either triple double quotes (""") or triple single quotes (''').
    msg = f"""<br>                      
            <br>Path: {path}
            <br>Address: {address}
            <br>Scheme: {scheme}
            <br>Method: {method}
            <br>User Agent: {user_agent}   
            <br>Path Info: {path_info}
            <br>Response header: {response.headers} 
    """
    return HttpResponse(msg, content_type = 'text/html', charset = 'utf-8')
        

def menuitems(request, dish): # additional arg (dish) is passed inside the urls.py(app) file
    items = {
        'pasta':'Type of noodle',
        'falafel':'Deep fried patties',
        'cheesecake':'Type of dessert'
    }
    # code to access the dictionary
    description = items[dish] # logic of this code is that the url parameter value passed to this function will be matched to a key inside the dictionary, then the associated value is stored in the variable named description (dish becomes the key and description becomes the value)
    return HttpResponse(f"<h2> {dish} </h2> " + description) # the variable description is used inside

def form_view(request):
    form = LogForm()
    if request.method == 'POST':          
        form = LogForm(request.POST)   # updates the form object with the content of the form inside the request object
        if form.is_valid():
            form.save() # saves the form data to the database
    context = {'form': form}
    return render(request, "home.html", context)

def demo_form(request):
    form = DemoForm()
    context = {'form': form}
    return render(request, "demo.html", context)

def about(request):
    about_content = {'about': 'Based in Chicago, Illinois'} # here about is a key in the dictionary
    return render(request, "about.html", about_content)

def menu(request):
   menuitem = {'name':'greek salad'}
   return render(request, 'menu.html', menuitem)

# def menu2(request):
#     newmenu = {'mains': [
#         {'name': 'Shawarma', 'price': 15.99},
#         {'name': 'Falafel', 'price': 8.99},
#         {'name': 'Cheesecake', 'price': 7.99}
#     ]}
#     return render(request, 'menu2.html', newmenu)

def menu_by_id(request):
    newmenu = Menu2.objects.all() # to show all the objects
    newmenu_dict ={'menu' : newmenu}
    return render(request, 'menu_cards.html', newmenu_dict)