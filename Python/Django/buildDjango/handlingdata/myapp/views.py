from django.shortcuts import render
from django.http import HttpResponse
from datetime import datetime

# Create your views here.
def say_hello(request):
    return HttpResponse('Hello, world')

def homepage(request):
    return HttpResponse('Welcome to Little Lemon!')

def display_date(request):
    date_joined = datetime.today().year
    return HttpResponse(f'The current year is {date_joined}')

def menu(request):
    text = """<h1 style="color: #F4CE14;"> This is Little Lemon again!</h1>""" # adding html code (with css) inside an object in python
    return HttpResponse(text)