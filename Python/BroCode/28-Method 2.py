name = "Bro"
rname = "Aswanth"

print("Hello, my name is {}. Nice to meet you".format(name))
print("Hello, my name is {:10}. Nice to meet you".format(name)) # to add padding (left align by default)
print("Hello, my name is {:<10}. Nice to meet you".format(name)) # left align
print("Hello, my name is {:>10}. Nice to meet you".format(name)) # right align
print("Hello, my name is {:^10}. Nice to meet you".format(name)) # center padding

print("Hello, my name is {rname:^10}. Nice to meet you".format(rname=rname))

# String formatting

print(f"{4:>10}") # Right justified
print(f"{4:^10}")
print(f"{4:<10}") # Left justified

# or

print("%10s"%"4") # Right justified 
print("%5s"%"4")
print("%-10d"%4) # Left justified     

# (for formatting integers we can use d instead of s)
print()

for exponent in range(7, 11):
    print("%-3d%12d" % (exponent, 10 ** exponent) )
