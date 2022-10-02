scores = {"mamta":20, "aayush":19, "riya":8, "neha":10}
for key in scores:
	print(key, scores[key])

# get all keys
print(scores.keys())
# get all values
print(scores.values())
# get list of key value pairs in form of tuoples
print(scores.items())

# two variable for loop deasigning the touples
for a, b in scores.items():
	print(a, b)
