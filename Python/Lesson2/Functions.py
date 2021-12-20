def test(name, age = 10) :
    data = f"Name : {name}, Age : {age}"
    return data


x = test("Mike", 55)
print(x)