from random import randrange

while True :

    num = randrange(1, 15)
    guess = input(f"Please input numbers from 1 to 15 range : ")

    if guess.isdigit() :
        guess = int(guess)
    else :
        print("You are entered non digit value!")
        continue

    if guess < 1 or guess > 15 : # ??
        print("Your entered number does not belong to the range!")
        continue

    if guess == num :
        print("You guessed it. Congratulations!")
        break
    elif guess != num :
        print(f"You did not guess the randomly generated number value. It has a {num} value. Try again!")