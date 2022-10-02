A=[[1,1],[1,1]]
B=[[2,2],[2,2]]
C=[[0,0],[0,0]]
for i in range (len(A)):
  for j in range (len(B)):
    C[i][j]=A[i][j]+B[i][j]
for i in C:
  print(i)
