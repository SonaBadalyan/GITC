from lib import replace_str, add_simbol

def test3(s) :
    s = replace_str(s)
    s = add_simbol(s)
    print(s)

test3("Hello, world")