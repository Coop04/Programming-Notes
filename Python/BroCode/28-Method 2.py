name = "Bro"
rname = "Aswanth"

print("Hello, my name is {}. Nice to meet you".format(name))
print("Hello, my name is {:10}. Nice to meet you".format(name)) # to add padding (left align by default)
print("Hello, my name is {:<10}. Nice to meet you".format(name)) # left align
print("Hello, my name is {:>10}. Nice to meet you".format(name)) # right align
print("Hello, my name is {:^10}. Nice to meet you".format(name)) # center padding

print("Hello, my name is {rname:^10}. Nice to meet you".format(rname=rname))