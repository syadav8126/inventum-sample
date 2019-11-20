from array import *
m = array('i',[1,4,2,4])
m.append(9)
print("count of 4 :",m.count(4))
m.remove(4)
m.insert(0,0)
print(m.buffer_info())
print("tolist:",m.tolist())
for i in m:
	print(i)
