from django.contrib import admin
from .models import Menu
from .models import MenuCategory
from .models import Customer
from .models import Logger
from .models import Reservation
from .models import Menu2

# Register your models here.
admin.site.register(Menu)
admin.site.register(MenuCategory)
admin.site.register(Customer)
admin.site.register(Logger)
admin.site.register(Reservation)
admin.site.register(Menu2)


# superadmin 
# username: john
# email: john@littlelemon.com
# password: john@1234