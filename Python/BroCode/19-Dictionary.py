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

# to append values/ update values
capitals['A']='B'
capitals['Germany']= 'Goa'
for i,j in capitals.items():
    print(i + '\t: '+ j)