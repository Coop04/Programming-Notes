import random

choices = ["rock","paper","scissors"]

def inputs(player,computer):
    print("Player: " + player)
    print("Computer: " + computer)
while True:
    computer = random.choice(choices) # module.function(list)
    player = "" # for resetting values of computer and player
    while player not in choices:
        player = input("rock,paper or scissors?:").lower()
    if player == computer:
        inputs(player,computer)
        print("Tie!")
    elif player == "rock":
        if computer == "paper":
            inputs(player,computer)
            print("You Lose...")
        else:
            inputs(player,computer)
            print("You Win...!")
    elif player == "paper":
        if computer == "rock":
            inputs(player,computer)
            print("You Win...!")
        else:
            inputs(player,computer)
            print("You Lose...")
    else:
        if computer == "rock":
            inputs(player,computer)
            print("You Lose...")
        else:
            inputs(player,computer)
            print("You Win...!")
    again = input("Do you want to continue: y/n: ")
    if again != "y":
        break
print("Thank you for playing")
