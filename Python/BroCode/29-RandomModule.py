import random

x = random.randint(1,6) # generates random integer no. between 1 and 6
y = random.random() # generates random floating point no. between 0 and 1

myList = ["rock","paper","scissors"] # pics random element from the list
z = random.choice(myList)

cards = [1,2,3,4,5,6,7,8,9,"J","Q","K","A"] # shuffles a list
random.shuffle(cards)

print(x)
print(y)
print(z)
print(cards)