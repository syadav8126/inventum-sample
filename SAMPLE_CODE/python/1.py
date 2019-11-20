a = [1,2,3,4,5]
a.append(6)
b = [7,8]
# to append a new list 
a.append(b)
str="hello world"
a.append(str)
# to extend/concatenate the list 
a.extend(b)
a.extend(range(3,6))
print(a)
a.remove(3)
