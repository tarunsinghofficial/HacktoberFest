def newtonLawOfGravitation(m, m2, d):
  g = 6.674 * (10**-11)
  F = g*(m1 * m2)/(d**2)
  return F

m1 = float(input('Enter mass of first object in kg: '))
m2 = float(input('Enter mass of second object in kg: '))
d = float(input('Enter distance between them in mt: '))

print('The calculated force is: ' + str(newtonLawOfGravitation(m1,m2,d)) + 'N')
