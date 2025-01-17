def abbrev_name(name):
    name=name.upper()
    word=name.split()
    print(word)
    first_letter=word[0][0]
    second_letter=word[1][0]
    short = first_letter+"."+second_letter
    return short

print(abbrev_name("Aswanth Satheesan"))
print(abbrev_name("aswanth satheesan"))

