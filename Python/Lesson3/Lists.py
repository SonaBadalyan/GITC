l = [23, 45]
l1 = [23, True, [45, ["hello"], "Hello"], False]

# print(l)
# print(l1[2][1][0])
# print(len(l1))

# for el in l:
#     print(el)

for i in range(len(l1)):
    if i == 2 :
        for x in l1[i] :
            print('______', x)
    else:
        print(l1[i])