import json
data = '''
	{
		"name":"Chunk",
		"phone":{
			"type": "intl",
			"number": "+91 3234343423"
		},
		"email":{
			"hide": "yes"
		}
	}
'''

info = json.loads(data)
print('name:', info['name'])
print('hide:', info['email']['hide'])

print("\n\nNew Data\n\n")

data2 = '''
[
	{
		"id": "001",
		"x":"2",
		"name":"Chunk"
	},{
		"id": "009",
		"x": "7",
		"name": "Chunk"
	}
]'''

info = json.loads(data2)
print('User count:', len(info))

for item in info:
	print('Name', item['name'])
	print('Id', item['id'])
	print('Attribute', item['x'])
