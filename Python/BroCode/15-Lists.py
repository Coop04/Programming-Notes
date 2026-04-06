# list = used to store multiple items in a single variable

food = ["pizza","burger","biriyani","burger"]
food[0]="sushi" #replaces the 0th element
print(food)
print(food[1])

for i in food:
    print(i)

print(len(food))

food.append("ice cream")
print(food)

food.remove("burger") # only the first occurnance will be removed
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
# -----------------------------------------

# to remove duplicates from a list

l1 = ['c','d', 'a', 'b','d','b', 'i','a']

# if order doesnt matter
l2 = list(set(l1)) 
print(l2) # ['a', 'd', 'c', 'b', 'i']

# by preserving order
d = {}
for i in l1:
    if i not in d:
        d[i] = 1
    else: 
        d[i]+=1
l3 = list(d.keys())
print(l3) # ['c', 'd', 'a', 'b', 'i'] preserves order

# or 
l4 = list(dict.fromkeys(l1))
print(l4) # ['c', 'd', 'a', 'b', 'i'] preserves order

# removing duplicates without dict:
l5 = l1.copy()
for i in range(len(l1)):
    if l5[i]=='-':
        continue
    for j in range(i+1,len(l1)):
        if l5[j]=='-':
            continue
        elif l5[i]==l5[j]:
            l5[j]='-'
l6 = []
for i in l5:
    if i!='-':
        l6.append(i)
print(l6)

# --------------------------------------------

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
print(func(3,[5,6])) # [5, 6, 3]


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

# ---------------------------------------------

# to convert the data type of all the elements in a list

lst = ['1', '2', '3', '4']
new_lst = list(map(int, lst))
print(new_lst)
