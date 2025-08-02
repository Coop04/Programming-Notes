"""
URL configuration for handlingdata project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from myapp import views # in myproject, since we created a seperate urls.py(app) file we used . to import the file(because views.py was in the same directory)
                        # here since no urls.py(app) was not created (include fn is not used) the views was imported from the myapp directory

urlpatterns = [
    path('admin/', admin.site.urls),
    path('say_hello/', views.say_hello),  # here it views.py (app) is directly mapped without creating any urls.py file in app
                                          # since 'say_hello/' string was used if we check the server page in browser directly it will show a page not found (404) error to solve this temporarily use /say_hello/ at the end of the url in the browser
    path('homepage/', views.homepage),    # now at the end of the url if I type /homepage/ it will show the view of homepage
    path('display_date/', views.display_date),
    path('menu/', views.menu)
]
