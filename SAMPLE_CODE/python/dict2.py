# iteration in a dict, making a key, value poosible combination
import itertools
options = {
	"x": ["a","b"],
	"y": [10,20,30]
}
keys=options.keys()
values=(options[key] for key in keys)
comb=[dict(zip(keys, combination)) for combination in itertools.product(*values)]
for c in comb:
	print(c)

#print(options)
