num1 = 3.14159
num2 = 100000000

print(f'The value of pi is: {num1:.2f}')
print(f'The value of pi is: {num1:,}')
print(f'The value of num2 is: {num2:,}')

print("The value of pi is: {}".format(num1))
print("The value of pi is: {:.2f}".format(num1)) # to limit the decimal value to 2 places (f = float) also no. is rounded
print("The value of num2 is: {:,}".format(num2)) # add , to every 1000s place
print("The value of num2 is: {:b}".format(num2)) # for binary representation
print("The value of num2 is: {:o}".format(num2)) # for octal (does not support floating value)
print("The value of num2 is: {:x}".format(num2)) # for hex (small) (does not support floating value)
print("The value of num2 is: {:X}".format(num2)) # for hex (capital) (does not support floating value)
print("The value of num2 is: {:e}".format(num2)) # for scientific notation (small)
print("The value of num2 is: {:E}".format(num2)) # for scientific notation (capital)