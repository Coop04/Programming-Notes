# scope = The region that a variable is recognized
# A variable is only available from inside the region it is created
# A global and locally scoped versions of a variable can be created


def display_name():
    name="Code"       #local scope (available only inside the function)
    print(name)       #even if a global variable with same name is available the local variable is considered first
                      #LEGB ie, Local>Enclosed>GLobal>Built-in
display_name()
# print(name) cannot be done since it only has local scope

name="Bro" #now print(name) is possible since it has global scope