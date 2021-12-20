from random import randrange

r1 = randrange(10, 30)

r2 = randrange(10, 30)

print(f"First number equal to {r1}")
print(f"Second number equal to {r2}")

res = int(input("Please insert two numbers addition result : "))

if r1 + r2 == res :
    print("You are right!")
else :
    print("You are wrong!")