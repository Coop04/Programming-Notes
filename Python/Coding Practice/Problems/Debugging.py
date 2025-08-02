# def append_list(item, lst=[]):
#     lst.append(item)
#     return lst

# print(append_list(1))
# print(append_list(2))
# # -----------------------------

# def increment(value, step=1):
#     value += step
#     return value

# num = 5
# num = (increment(num))
# print(num)
# # ----------------------------

# def countdown(n):
#     if(n==0):
#         print(0)
#         return
#     else:
#         print(n)
#         return(countdown(n-1))


# countdown(5)
# --------------------------------

# def countdown(n):
#     while(n>=0):
#         print(n)
#         return countdown(n-1)

# countdown(5)
# -----------------------------
# a = "hello"
# b = "hello"
# print(a == b)
# ---------------------------

# a = [1, 2, 3]
# b = a
# b.append(4)
# print(a)
# --------------------------

# def tricky():
#     return [lambda x: x + i for i in range(3)]

# funcs = tricky()
# print(funcs)
# ----------------------------

# class A:
#     def __init__(self):
#         self.x = 10

# a = A()
# print(hasattr(a, 'x'))
# print(hasattr(A, 'x'))

# -------------------------
# x = 1  # Global variable

# def func():
#     global x  # Declaring that we are modifying the global variable
#     x += 1    # This should increment `x`
#     return x

# print(func())  # Expected output: 2, but ERROR occurs!

# x = 1
# def func():
#     global x
#     x += 1
#     return x

# print(func())

# -----------------------------

# list = []
# n = int(input('Enter n'))
# for i in range(n):
#     k = int(input())
#     list.append(k)
# print(list)
# for i in range(n-1):
#     for j in range(n-i-1):
#         if(list[j] > list[j+1]):
#             list[j],list[j+1] = list[j+1],list[j]
# print(list)

# ----------------------------------

def list_of_frequency(a):
    dict = {}
    for i in a:
        if i not in dict:
            dict[i] = 1
        else:
            dict[i] += 1
    print(dict)
list_of_frequency('hello')
        