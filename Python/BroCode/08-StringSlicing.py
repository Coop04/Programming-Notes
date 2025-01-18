# slicing = creating a substring by extracting elements fron another string
# indexing = accessing a character in a string by its position
# indexing[] or slice()
# [start:stop:step]

name="Aswanth Satheesan"
first_name=name[0:7] #sincr start is inclusive and stop is exclusive
# first_name=name[:7] #same as above, ie 0 is assumed
print(first_name) #output: Aswanth
last_name=name[8:17]
# last_name=name[8:] #all the rest are taken
print(last_name)
funky_name=name[::2] #step is by default 1,when changed to 2 , it only reads every 2nd letter
print(funky_name)    #output: AwnhStesn

reversed_string=name[::-1] #linke counting backwords
print(reversed_string) #output: naseehtaS htnawsA


website1="https://google.com"
website2="https://facebook.com"
slice= slice(8,-4) #same as indexing, but seperated by ",", ie [start,stop,step]
                   #-4 ie, negetive indexing,cuz diffrerent websites have different length, so cutting 4 from back (starting from -1)
print(website1[slice])
print(website1[8:-4])
print(website2[slice])