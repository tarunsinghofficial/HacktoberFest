from statistics import mean
n=int(input("Enter number of processes: "))
Bt=list(map(int, input("Enter burst time of processes: ").split()))
At=list(map(int, input("Enter arrival time of processes: ").split()))
TQ=int(input("Enter Time Quantum: "))
data=dict(zip(At,Bt))
dics=dict(sorted(data.items()))
at=[x for x in dics]
bt=[y for y in dics.values()]
t=0
Ct=[0]*n
Wt=[0]*n
TAT=[0]*n
Burst=Bt.copy()
Sum=sum(Bt)
while(t<Sum):
    for i in range(n):
        if bt[i]>TQ:
            bt[i]=bt[i]-TQ
            t+=TQ
        else:
            if bt[i]!=0:
                t+=bt[i]
                bt[i]=0
                Ct[i]=(t)
        TAT[i]=Ct[i]-at[i]
        Wt[i]=TAT[i]-Bt[i]
print("Average Waiting time: ", mean(Wt))
print("Average TAT is :", mean(TAT))
