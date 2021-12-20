num1 = input("Please enter first number : ")

if num1.isdigit() :
    num1 = int(num1)
else :
    print(f"Your entered value({num1}) is not number!")
    exit()

num2 = input("Please enter second number : ")

if num2.isdigit() :
    num2 = int(num2)
else :
    print(f"Your entered value({num2}) is not number!")
    exit()

print(f"Multiplication result is equal to : {num1 * num2}" )