def test(name):
    x = f"Hello, {name}"
    print("test in function")
    return x
    # print("test in function") code is unreachable

test.hello = "esim"
test.hello2 = 23

print("test global")
s = test("John")
print(s)
print(type(s))

print(test.hello)
print(test.hello2)
print(type(test))