import xml.etree.ElementTree as ET
data = '''
		<person>
			<name>Chuck</name>
			<phone type="intl">
				+912345343434
			</phone>
			<email hide="yes"/>
		</person>
	'''

tree = ET.fromstring(data)
print('Name:', tree.find('name').text)
print('Attr:', tree.find('email').get('hide'))

print('\n\nNew Data\n\n')

data2 = '''
		<stuff>
			<users>
				<user x="2">
					<id>001</id>
					<name>Chuck</name>
				</user>
				<user x="7">
					<id>009</id>
					<name>Brent</name>
				</user>
			</users>
		</stuff>
	'''
stuff = ET.fromstring(data2)
lst = stuff.findall('users/user')
print('User count:', len(lst))
for item in lst:
	print('Name:', item.find('name').text)
	print('Id:', item.find('id').text)
	print('Attribute:', item.get("x"))