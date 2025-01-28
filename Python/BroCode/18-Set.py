# set = collection which is unordered, unindexed. No duplicate values
# faster tha a list

utensils = {"fork","spoon","knife","knife","knife"} #only prints knife once
dishes = {"bowl","plate","cup","knife"}
dinner_table = utensils.union(dishes)

print(utensils)  # Output: {'fork', 'spoon', 'knife'} ie, even after union the utensils set is unaffected

utensils.add("napkin")
utensils.remove("knife")
# utensils.clear() #clears the set

# for i in utensils:
#     print(i) #different order each time on running

utensils.update(dishes) # update() is like union (i.e, combines from both and duplicates are eliminated)
                        # unlike union(), update() updates the first set (i.e, utensils here)

for i in utensils:
    print(i) #different order each time on running

print()

for i in dinner_table:
    print(i)

print(utensils.difference(dishes)) # shows what utensils have and dishes haven't
print(utensils.intersection(dishes)) # shows what the sets have in common