print(3 // 2)
print("Hello " * 10)
print("Hello" + ", " + "world!")

s1 = "Hello"
s2 = "world!"
s3 = s1 + ", " + s2 
# s3 = s1 + ", " + s2 + 34
# Traceback (most recent call last):
#   File "/home/sona/Desktop/GITC/Python/Lesson1/operators.py", line 6, in <module>
#     s3 = s1 + ", " + s2 + 34
# TypeError: can only concatenate str (not "int") to str

s3 = s1 + ", " + s2 + str(34)

x = len(s1)
print(x)

