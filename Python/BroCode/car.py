class Car:

    wheels = 4 # class variable (is declared inside the class but outside the constructor)
               # sets a default value for all instances of the class
    
    def __init__(self,make,model,year,color):   # constructor
                                                # special method that will create objects for us
                                                # event though there are 5 args we only pass 4 args, ie,we dont pass value for self


        self.make=make    #instance variable
        self.model=model  #instance variable
        self.year=year    #instance variable
        self.color=color  #instance variable

    def drive(self): # self refers to the object that is is using this method
        print("This "+self.model+" is driving")

    def stop(self):
        print("This "+self.model+" has stopped")