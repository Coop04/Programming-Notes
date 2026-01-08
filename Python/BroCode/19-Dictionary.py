# dictionary = A changeable, unordered collection of unique key:value pairs
# Fast because they use hashing, allow us to access a value quickly

capitals = {'USA':'Washington DC',
            'India':'New Delhi',
            'China':'Baijing',
            'Russia':'Moscow'}

print(capitals['Russia']) #not safe since if the key is not in the dictionary error occurs
# print(capitals['France']) #error occurs since France is not in the dictionary

# safer way
print(capitals.get('Germany')) #returns None if key is not in the dictionary

print(capitals.keys()) #returns list of keys
print(capitals.values()) #returns list of values
print(capitals.items()) #returns a list of tuples

for i,j in capitals.items(): #for key value pairs
    print(i,j)
for key,value in capitals.items():
    print(key +"\t: "+ value)


# for values
for i in capitals.values(): 
    print(i)
for i in capitals:  # for values (get is used for values)
    print(capitals.get(i)) 

# for keys
for i in capitals:   
    print(i)
for i in capitals.keys():
    print(i)


capitals.update({"Germany":"Berlin"})
capitals.update({"USA":"Las Vegas"})
capitals.pop("China")
# capitals.clear() #clears the dictionary

# -------------------------------------------------

# to append values/ update values
capitals['A']='B'
capitals['Germany']= 'Goa'
for i,j in capitals.items():
    print(i + '\t: '+ j)

print()

# to delete a value from dictionary
capitals.pop('A')
print(capitals)

print()
# ---------------------------------------------------
# to compare 2 dictionaries
d1 = {1:'a',2:'b',3:'c'}
d2 = {2:'b',1:'a',3:'c'}
if d1 == d2:
    print("They are equal")
else:
    print("They are different")

print()
# ----------------------------------------------------
print(capitals.get('UA','Invalide key')) # we can use a default fallback value inside a get() if the key value is not found
print()
# ----------------------------------------------------
# Switch using dictionary 

def get_week_day(argument):
    switcher = {
        0: "Sunday",
        1: "Monday",
        2: "Tuesday",
        3: "Wednesday",
        4: "Thursday",
        5: "Friday",
        6: "Saturday"
    }
    return switcher.get(argument, "Invalid day")

print(get_week_day(6))
print(get_week_day(8))
print(get_week_day(0))

# ---------------------------------------------------------
# to sort dictionaries by keys
d = {'b': 2, 'a': 1, 'c': 3}

sorted_d1 = dict(sorted(d.items())) # by ascending order of keys
sorted_d2 = dict(sorted(d.items(), reverse=True)) # by descending order of keys
print(sorted_d1)
print(sorted_d2)
