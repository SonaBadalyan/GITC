def test(*params) : # tuple
    print(params)

def test(**params) : #dictionarie
    print(params)

test(23, "John")
test(age = 23, name = "John")