# def square(x):
#     return x * x

square = lambda x: x * x
print(square(5))  # Output: 25
# ------------------------------

add = lambda a, b: a + b
print(add(3, 7))  # Output: 10

# --------------------------------

greater = lambda a,b:a if(a>b) else b
print(greater(10,20))

# ---------------------------------

# Using Lambda in map()
nums = [1, 2, 3, 4, 5]
squared_nums = list(map(lambda x: x * x, nums))
print(squared_nums)  # Output: [1, 4, 9, 16, 25]

# ------------------------------------

# Using Lambda in filter()
nums = [1, 2, 3, 4, 5, 6]
even_nums = list(filter(lambda x: x % 2 == 0, nums))
print(even_nums)  # Output: [2, 4, 6]

# ------------------------------------

# Using Lambda in sorted() with key
students = [("Alice", 25), ("Bob", 20), ("Charlie", 22)]
students_sorted = sorted(students, key=lambda x: x[1])  # Sort by age
print(students_sorted)
# Output: [('Bob', 20), ('Charlie', 22), ('Alice', 25)]

# -------------------------------------

check_even = lambda x: "Even" if x % 2 == 0 else "Odd"
print(check_even(10))  # Output: Even
print(check_even(7))   # Output: Odd

# --------------------------------------

nums = [1, 2, 3, 4, 5]
squared = list(map(lambda x: x ** 2, nums))
print(squared)  # Output: [1, 4, 9, 16, 25]

# ---------------------------------------

# Using Lambda in List Comprehension
numbers = [1, 2, 3, 4]
doubled_numbers = [(lambda x: x * 2)(x) for x in numbers]
print(doubled_numbers)  # Output: [2, 4, 6, 8]

# -----------------------------------------

# Using Lambda in Dictionary Sorting
people = [{'name': 'Alice', 'age': 25}, {'name': 'Bob', 'age': 20}, {'name': 'Charlie', 'age': 22}]
people_sorted = sorted(people, key=lambda person: person['age'])
print(people_sorted)  # Output: [{'name': 'Bob', 'age': 20}, {'name': 'Charlie', 'age': 22}, {'name': 'Alice', 'age': 25}]

# Example 9: Using Lambda in reduce()
from functools import reduce
numbers = [1, 2, 3, 4, 5]
product = reduce(lambda x, y: x * y, numbers)
print(product)  # Output: 120

# Example 10: Using Lambda with Nested Functions
def multiplier(n):
    return lambda x: x * n

double = multiplier(2)
print(double(5))  # Output: 10
