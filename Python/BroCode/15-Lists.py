# list = used to store multiple items in a single variable

food = ["pizza","burger","biriyani"]
food[0]="sushi" #replaces the 0th element
print(food)
print(food[1])

for i in food:
    print(i)

food.append("ice cream")
print(food)

food.remove("burger")
print(food)

food.pop() # or food.pop(1) : which pops the item at the given index (same as remove but with index)
print(food)

food.insert(1,"cake")
print(food)

food.sort()
print(food)

food.clear()
print(food)

# inputting to list
items = []
for i in range (3):
    k = input('Enter the items: ')
    items.append(k)

print(items)