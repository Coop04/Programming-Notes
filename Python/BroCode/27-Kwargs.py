# **kwargs = paramater that will pack all arguements into a dictionary
# useful so that a function accept a varying amount of keyword arguements

# def hello(first,last):
#     print("hello " + first + " " + last)

# hello(first="Bro",last="Code") # cant accept more than 2 args


# def hello(**kwargs):
#     print("hello " + kwargs['first'] + " " + kwargs['last'])

# hello(first="Bro",middle="Dude",last="Code")


def hello(**kwargs):
    print("Hello",end=" ")
    for key,value in kwargs.items():
        print(value,end=" ")

hello(title="Mr.",first="Bro",middle="Dude",last="Code")