import SubFolder.lib 

def test3(s) :
    s = SubFolder.lib.replace_str(s)
    s = SubFolder.lib.add_simbol(s)
    print(s)

print(__name__) 

test3("Hello, world")