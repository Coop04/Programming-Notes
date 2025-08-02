from django.urls import path
from . import views

urlpatterns = [
    # path('', views.home), # dont need to use view.py since the urls file and view file are in the same folder
                         # in views.home home is the name of the function
                         # if view is highlighted, it means inordr to use the views.py it must be imported
                         # remember to put , at the end of this path fn (to match the parsing that django performs)
    path('home1/', views.home1),
    path('home2/', views.home2),
    path('dishes/<str:dish>',views.menuitems), # str refers to the path converger type & dish is the url parameter name
    path('home/',views.form_view), # form added
    path('demoform/',views.demo_form),
    path('about/',views.about),
    path('menu/',views.menu),
    # path('menu2/', views.menu2),
    path('menu_card/', views.menu_by_id),
]