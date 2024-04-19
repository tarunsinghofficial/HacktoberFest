def CostlySolncountingApples(s,t,a,b,apples,oranges):
    
    house = list(range(s,t+1))
    countA=0
    countO=0

    for i in apples:
        incApple = i+a
        if incApple in house:
            countA +=1

    for j in oranges:
        incOranges = j+b
        if incOranges in house:
            countO +=1

    print(f"{countA}\n{countO}")

def countingApples(s,t,a,b,apples,oranges):
    
    house = set(list(range(s,t+1)))
    apples = [i+a for i in apples]
    oranges = [j+b for j in oranges]
   

    countA = len(set(apples).intersection(house))
    countO = len(set(oranges).intersection(house))
    print(countA)
    print(countO)
  

#this is the correct solution
def CorrectSolution(s,t,a,b,apples,oranges):
    count_Apples = 0
    count_Oranges= 0

    for i in range(len(apples)):
        if a+apples[i] >= s and a+apples[i] <= t:
            count_Apples +=1
    for i in range(len(oranges)):
        if b+oranges[i] >= s and b+oranges[i] <=t:
            count_Oranges +=1
    print(count_Apples)
    print(count_Oranges)

countingApples(7,11,5,15,[-2,2,1],[5,-6])
