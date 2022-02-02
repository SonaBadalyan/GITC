import json

def get_user_data() :

    l = []

    i = 1
    while i <= 2:
        name = input("Please input person name: ")
        surname = input("Please input person surname: ")
        age = input("Please input person age: ")

        while not age.isdigit() :
            age = input("You are entered non digit value! Please input person age: ")

        age = int(age)
    

        l.append
        ( 
            {
                'id' : i,
                'name' : name,
                'surname' : surname,
                'age' : age
            }
        )

        i += 1

    return l

def create_data(l):

    f_str = '['
    
    for d in l:
        f_str += f"Id: {d['id']},\n"
        f_str += f"Name: {d['name']},\n"
        f_str += f"Surename: {d['surname']},\n"
        f_str += f"Age: {d['age']}\n\n"
    
    f_str += ']'

    with open('C:\\Users\\sonab\\Documents\\GitHub\\GITC\\Python\\Lesson7\\Persons.json', "w") as outfile:
        outfile.write(f_str)

create_data(get_user_data())
