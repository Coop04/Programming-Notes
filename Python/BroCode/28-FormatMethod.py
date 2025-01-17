# str.format() = optional method that gives users more control when displaying output

animal = "cow"
item = "moon"

print(f"{animal} jumped over the {item}")   # most simple way

# print("The "+animal+" jumped over the "+item)

print("The {} jumped over the {}".format("cow","moon")) # we use placeholders {} in place of the variables
                                                        # {} are known as format fields

print("The {} jumped over the {}".format(animal,item))

print("The {1} jumped over the {0}".format(animal,item)) # positional arguements (using index starting from 0)

print("The {vehicle} jumped over the {thing}".format(vehicle="car",thing="hump")) # keyword arguement (here the global args are not taken)
                                                                                  # we can use the same format field twice like the cow jumped over the 
                                                                                  
text = "The {} jumped over the {}"
print(text.format(animal,item))

