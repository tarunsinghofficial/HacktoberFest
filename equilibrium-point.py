class Solution:
    # Complete this function
    
    #Function to find equilibrium point in the array.
    def equilibriumPoint(self,A, N):
        # Your code here
        tsum=sum(A)
        suma=0
        for i in range(len(A)):
            if suma==tsum-A[i]:
                return i+1
            suma=suma+A[i]
            tsum=tsum-A[i]
        return -1 
