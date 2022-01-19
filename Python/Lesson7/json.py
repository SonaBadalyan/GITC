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

def create_json_data(l):
    json_object = ''
    
    for d in l:
        json_object= json.dumps(d, indent = 4)
  
    with open('C:\\Users\\sonab\\Documents\\GitHub\\GITC\\Python\\Lesson7\\PersonsList.json', "w") as outfile:
        outfile.write(json_object)


create_json_data(get_user_data())