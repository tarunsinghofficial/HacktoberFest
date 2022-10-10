# diagnal line of numbers from any number to another number
def diagnal():
  c = int(input('Start from number: '))
  rows = int(input("Stop at number: "))
  for i in range(1, rows + 1):
      for j in range(c, i + 1):
          print(j, end=' ')
      print('')
      
# the main project
def project():
    diagnal()
project()
