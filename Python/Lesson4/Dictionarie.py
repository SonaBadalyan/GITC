d = {
    "name" : "John", 
    "age" : 21, 
    "test" : [23, True, {"a" : 2}],
    "name" : 56
    }

d["name"] = "test"

print(d)
# print(d[0]) KeyError: 0
print(d["name"])
d["name"] = "Mike"
print(d["name"])
print(type(d))

print("name" in d)
print("hello" in d)

print(d.get("name"))

# print(d["hello"])
print(d.get("hello", "Guest")) # get is exception free, the second parameter is the default value when element not found by key if we did not give it to function, it returns None

a = None
print(a)

print(d.items())

for e in d.items() :
    print(e)

for key, value in d.items() :
    print(key, value)

print(d.values())

for value in d.values():
    print(value)

print(d.keys())

for key in d.values():
    print(key)