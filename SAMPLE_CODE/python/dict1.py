from collections import OrderedDict
d={}    #empty dict
d=dict()  #empty dict
d=dict(key='value')
#print(d)
d=dict([('key','value')])
d['key1']=[1,2,3]  # a new key with list as its value
d['key2']={'nested key':1}
for key,value in d.items():  # used to loop over both key and value
	print(key,value)
for value in d.values():     # used to loop over value only
	print(value)
#print(d)
#merging two dicts
fish ={'name': "Nemo",'hands': "fins",'special': "gills"}
dog ={'name': "Clifford",'hands': "paws",'color': "red"}
fishdog={**dog,**fish}
#print(fishdog)
#ordered dict
d=OrderedDict()
d['a']=1
d['b']=2
d['c']=3
d['d']=4
print(d)
