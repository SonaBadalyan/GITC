l = []

i = 0

while i < 3:
    i += 1;
    nameSurname = input(f"Please enter {i}-th person name and surname separated by a dot : ")
    
    nameSurname = nameSurname.replace('.', ' ')
    l.append(nameSurname) 

for i in range(len(l)) :
    print(i + 1, l[i])