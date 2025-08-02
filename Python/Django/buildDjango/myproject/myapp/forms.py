from django import forms

from django.forms.widgets import NumberInput

from .models import Logger

FAVOURITE_DISH = [
        ('italian', 'Italian'),
        ('greek', 'Greek'),
        ('turkish', 'Turkish'),
    ]
class DemoForm(forms.Form):
    name = forms.CharField() #a default form is created with name: and an input field and a submit button
    # name = forms.CharField(widget=forms.Textarea) # changes the input text field to a text area
    # name = forms.CharField(widget=forms.Textarea(attrs={'rows':5})) # to reduce the size of the text area

    # email = forms.EmailField()
    email = forms.EmailField(label='Enter email address')

    reservation_date = forms.DateField(widget=NumberInput(attrs={'type': 'date'}))

    # favourite_dish = forms.ChoiceFields(choices=FAVOURITE_DISH) # dropdown
    favourite_dish = forms.ChoiceField(widget=forms.RadioSelect, choices=FAVOURITE_DISH) # radiobutton



class LogForm(forms.ModelForm):
    class Meta:
        model = Logger
        fields = '__all__'