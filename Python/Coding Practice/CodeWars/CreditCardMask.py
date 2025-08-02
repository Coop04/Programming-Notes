# Usually when you buy something, you're asked whether your credit card number, phone number or answer to your most secret question is still correct. However, since someone could look over your shoulder, you don't want that shown on your screen. Instead, we mask it.

# Your task is to write a function maskify, which changes all but the last four characters into '#'.

# Examples (input --> output):
# "4556364607935616" --> "############5616"
#      "64607935616" -->      "#######5616"
#                "1" -->                "1"
#                 "" -->                 ""

# // "What was the name of your first pet?"
# "Skippy" --> "##ippy"
# "Nananananananananananananananana Batman!" --> "####################################man!"

# return masked string
def maskify(cc):
    cc2 = ''
    for index, char in enumerate(cc):  # in case of list index, value enumerate(list_name) is used
        if index<(len(cc)-4):
            char ='#'
            cc2+=char
        else:
            cc2+=char
    return cc2


print(maskify('4556364607935616'))
print(maskify('Nananananananananananananananana Batman!'))
print(maskify('1'))
print(maskify(''))