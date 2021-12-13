# Types

i = 12
i = 3
i = 'test'
print(i)
s = "hello"

f = 2.5
b1 = True
b2 = False
print(i, s, f, b1, b2)

# Types conversion

t = str(i)
print(t)
print(type(t))

t = bool(i)
print(t)
print(type(t))

t = int(b1)
print(t)
print(type(t))

t = int(b2)
print(t)
print(type(t))

t = int(f)
print(t)
print(type(t))

st = '13'
t = int(st)
print(t)
print(type(t))

# st = '13k' 
# t = int(st)
# print(t)
# print(type(t))

# Traceback (most recent call last):
#   File "/home/sona/Desktop/GITC/Python/Lesson1/test.py", line 33, in <module>
#     t = int(st)
# ValueError: invalid literal for int() with base 10: '13j'

