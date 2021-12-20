def customSort(el) :
    return len(el)

l = ['hello', 'alo', 'ab', 'esim']

# l.sort( reverse = True, key = customSort)

l.sort(key = len)

print(l)