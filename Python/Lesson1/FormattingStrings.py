name = "John"
age = 24

year = 2021 - age

# res1 = "Your name is " + name + "\n Your age is " + str(age)

res2 = "Your name : {}, Your age : {}".format(name, age)
print(res2)

res2 = "Your name : {}, Your age : {}".format(age, name)
print(res2)

res2 = "Your name : {1}, Your age : {0}".format(name, age)
print(res2)

res2 = f"Your name :  {name}, Your age : {age}"
print(res2)

print(res2.lower())
print(res2.upper())
