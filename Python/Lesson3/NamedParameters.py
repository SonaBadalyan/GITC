def test(name, age = 1) :
    s = f"Name : {name}, Age : {age}"
    return s

a = test(age = 30, name = "John")
print(a)