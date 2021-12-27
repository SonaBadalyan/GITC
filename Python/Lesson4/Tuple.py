t = (3, 7, 9)

print(t)
print(type(t))
print(len(t))
# t[1] = 3 TypeError: 'tuple' object does not support item assignment
t = (9, 7, 3) # But this assignment is ok
print(t)