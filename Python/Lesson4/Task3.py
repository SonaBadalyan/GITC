def test1(*params) : # tuple
    print(params)

def test2(**params) : #dictionarie
    print(params)

test1(23, "John")
test2(age = 23, name = "John")