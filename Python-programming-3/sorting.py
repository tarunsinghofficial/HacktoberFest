def bubbleSort(Seq ):
    l = len(Seq )

    for i in range( l-1 ) :
        flag = 0

        for j in range(l - 1) :
            
            if theSeq[j] > theSeq[j + 1] : 
                t = Seq[j]
                Seq[j] = Seq[j + 1]
                Seq[j + 1] = t
                flag = 1

        if flag == 0:
            break

    return Seq

a = [21,6,9,33,3] 

result = bubbleSort(a)

print (result)
