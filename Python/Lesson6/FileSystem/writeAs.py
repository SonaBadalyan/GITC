with open('/home/sona/Desktop/GITC/Python/Lesson6/FileSystem/test.txt', 'a+', encoding='utf-8') as f:
    f.write('\n2. Mike')
    print(f.closed)
    print(f.mode)
    print(f.name)

# f.read()

