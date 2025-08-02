import random

def choose():
    words=['computer','science','sky','chemistry','blue','program','ground','rainbow','water','food']
    pick=random.choice(words) #for picking a random word from the gicen library
    return pick

def jumbled(word):
    jumble="".join(random.sample(word,len(word))) #jumbling the selected word and joining it irrespective of any symbols
    return jumble

def thanks(p1n,p2n,p1,p2): #since none of the variables are defined in the beginning they should be defined within ()
    print("Thanks for playing",p1n,p2n)
    print("Your scores are")
    print(p1n,":",p1)
    print(p2n,":",p2)

def play():
    p1n=input("Enter Player 1 Name: ")
    p2n=input("Enter player 2 Name: ")
    p1=0
    p2=0
    turn=0
    c=1
    while(c==1):
        if(turn%2==0):
            print(p1n,"it's your turn")
            picked_word=choose()
            q=jumbled(picked_word)
            print(q)
            w=input("Enter what you think: ")
            if(w==picked_word):
                p1+=1
                print("Right answer",p1n)
                print("Your score is",p1)
            else:
                print("Sorry, I thought",picked_word)
                c=input("If you wish to continue press 1 or press 0 to quit: ")
                c=int(c)
                if(c==0):
                    thanks(p1n,p2n,p1,p2)
                    break
        else:
            print(p2n,"it's your turn")
            picked_word=choose()
            q=jumbled(picked_word)
            print(q)
            w=input("Enter what you think: ")
            if(w==picked_word):
                p2+=1
                print("Right answer",p2n)
                print("Your score is",p2)
            else:
                print("Sorry, I thought",picked_word)
                c=input("If you wish to continue press 1 or press 0 to quit: ")
                c=int(c)
                if(c==0):
                    thanks(p1n,p2n,p1,p2)
                    break
        turn=turn+1 
play()   