l = [23, True, 'Hello']

l[0] = 'Test'
# l[4] = 55 IndexError: list assignment index out of range
l.append(55)
print(l)

x = 'hello'
# x[0] = 't' TypeError: 'str' object does not support item assignment

x = 23
print(type(x))

y = str(x)
print(type(x))

x = range(10)
# print(x) range(0, 10)

y = list(x)
print(y)