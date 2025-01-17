# keyword arguements = arguements processed by an identifier when we pass them to a function.
                    #    The order of the arguements doesn't matter, unlike positional arguements(which we were using earlier)
                    #    Python knows the names of the arguement that our function recieves

def hello(fname,mname,lname):
    print(fname,mname,lname)

#positional arguements
hello("Bro","Dude","Code") #when the order of the arguements changes the output changes

#keyword arguements
hello(lname="Code",fname="Bro",mname="Dude") #order doesnt matter