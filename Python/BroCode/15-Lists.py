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

x = food.pop() # or food.pop(1) : which pops the item at the given index (same as remove but with index)
print(food)
print(x)

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

# copying a string

a = [1, 2, 3]
b = a
b.append(4)
print(a) # [1,2,3,4] since b is not a list (b is another reference to a )

# proper way to copy
a = [1, 2, 3]
b = a[:]  # Slicing method
b.append(4)
print(a)  # [1, 2, 3]
print(b)  # [1, 2, 3, 4]

# proper way to copy
a = [1, 2, 3]
b = a.copy()  # Using list.copy()
b.append(4)
print(a)  # [1, 2, 3]
print(b)  # [1, 2, 3, 4]

# -----------------------------

def func(val, lst=[]):
    lst.append(val)
    return lst

print(func(1))  # [1]
print(func(2))  # [1, 2]
print(func(3))  # [1, 2, 3]


def func(val, lst=None):
    if lst is None:
        lst = []  # Creates a new list for each function call
    lst.append(val)
    return lst

print(func(1))  # [1]
print(func(2))  # [2]
print(func(3))  # [3]

# to merge 2 lists
a = [1,2,3,4,5]
b = [3,4,5,6]
c = []
c.extend(a)
c.extend(b)
print(c)
# or use +
m = a+b
print(m)

d = []
d.append(a)
d.append(b)
print(d)
