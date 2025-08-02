from django.db import models

from django.forms import ModelForm
# Create your models here.
# Menu Category
# Menu

class MenuCategory(models.Model):
    menu_category_name = models.CharField(max_length=200)

class Menu(models.Model):
    menu_item = models.CharField(max_length=200)
    price = models.IntegerField(null = False)
    # Inside the foreign key are 2 required fields, the first field is the class for the model to connect to, and the second is the settings field.
    category_id = models.ForeignKey(MenuCategory, on_delete=models.PROTECT, default=None,related_name="category_name")

class Customer(models.Model):
    name = models.CharField(max_length=200)
    reservation_day = models.CharField(max_length=10)
    seats = models.IntegerField()
    
    def __str__(self):
        return self.name
    
class Logger(models.Model):
    first_name = models.CharField(max_length=200)
    last_name = models.CharField(max_length=200) # can give required to change the default required settings
    time_log = models.TimeField(help_text='Enter the exact time') # help_text is optional

class Reservation(models.Model):
    name = models.CharField(max_length=200)
    contact = models.CharField('Phone number',max_length=300)
    time = models.TimeField()
    count = models.IntegerField()
    notes = models.CharField(max_length=300, blank=True)

    def __str__(self):
        return self.name
    
class Menu2(models.Model):
    name = models.CharField(max_length=200)
    price = models.IntegerField()

    def __str__(self):
        return self.name