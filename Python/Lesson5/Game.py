languages = ["Python", "Go", "JavaScript", "PHP", "Perl", "Swift", "Flask"]

print("______Welcome to the game!__________", end = "\n\n\n")

count = 3;

print(f"""You are have {count} attempts to guess language name or you may check characters that contian languages {count} times.""")

user_input = input("Please input character or language name : ")

while (0 != count) :

    for language in languages :
        if language == user_input :
            print("WON!")
            exit()
        elif 



