#Buying the item with discount
a=input("Price of the item")
d=input("Discount percentage")
a=int(a);d=int(d)
p=(a-(a*(d/100)))
print("The actual price is",p)

#Selling the item for 15% gain
x=.15
print("Total money gained after selling",a+(a*x))