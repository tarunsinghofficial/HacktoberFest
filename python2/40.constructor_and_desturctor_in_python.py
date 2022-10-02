class PartyAnimal:
	x = 0
	# constructor
	def __init__(self):
		print('I am constructed')
	# destructor
	def __del__(self):
		print('I am destructed', self.x)

	def party(self):
		self.x = self.x + 1
		print('So far', self.x)

an = PartyAnimal()
an.party()
an.party()
# assignment calling object destruction
an = 42
print('an contains', 42)