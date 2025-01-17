def new_game():
    guesses = []
    correct_guesses = 0
    question_num =1

    for key in questions:
        print("--------------------")
        print(key) # prints question
        for i in options[question_num-1]: # since index starts from 0
            print(i)
        guess = input("Enter A,B,C, or D: ").upper()
        guesses.append(guess)
        correct_guesses+=check_answer(questions.get(key),guess) # get() is used for retrieving values from dictionary
        question_num += 1
    display_score(correct_guesses,guesses)
# --------------------
def check_answer(answer,guess):
    if answer == guess:
        print("CORRECT!")
        return 1
    else:
        print("INCORRECT!")
        return 0
# --------------------
def display_score(correct_guesses,guesses):
    print("--------------------")
    print("RESULT")
    print("--------------------")
    print("Answers: ",end="")
    for i in questions.values():
        print(i,end=" ")
    print()
    print("Guesses: ",end="")
    for i in guesses:
        print(i,end=" ")
    print()

    score = int((correct_guesses/len(questions))*100)
    print("Your score is: "+str(score)+"%")
# --------------------
def play_again():
    response = input("Do you want to play again (y/n): ")
    response = response.upper()
    if response == "Y":
        new_game()
    else:
        print("Thank You...")
# --------------------

questions = {
    "Who created python? ":"A",
    "What year was python created?: ":"B",
    "Python is tributed to which comedy group?: ":"C",
    "Is the earth round?: ":"A"
}

options = [["A. Guido van Rossum", "B. Elon Musk", "C. Bill Gates", "D. Mark Zuckerburg"],
          ["A. 1989", "B. 1991", "C. 2000", "D. 2016"],
          ["A. Lonely Island", "B. Smosh", "C. Monty Python", "D. SNL"],
          ["A. True","B. False", "C. sometimes", "D. What's Earth?"]]

new_game()
play_again()