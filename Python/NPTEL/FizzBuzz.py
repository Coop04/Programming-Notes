#multiple of 3 is Fizz
#multiple of 5 is Buzz
#multiple of 3 & 5 is FizzBuzz
def FizzBuzz(n):
    #n=input("Enter a limit")
    n=int(n)
    for i in range(n+1): 
    #for i in range(1,n+1): #Or (to avoid zero) range can be specified ie, for i in range(1,n+1): 
        if((i%3==0)&(i%5==0)):
            print("FizzBuzz")
        elif(i%3==0):
            print("FIzz")
        elif(i%5==0):
            print("Buzz")
        else:
            print(i)

FizzBuzz(50)