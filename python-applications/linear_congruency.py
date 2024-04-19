## parâmetros para o método das congruências lineares:
m = 2**32
a = 22695477
c = 1
anterior = 42


# Continue aqui o seu programa ...

numJogadas=int(input("Digite o numero de jogadas: \n"))
numAcertos=0
numAcertos2=0
q=0
m=1
numero_aleatorio_anterior=42
while m<=numJogadas:
    n1=int(input("Pessoa 1: digite um numero: \n"))
    n2=int(input("Pessoa 2: digite um numero: \n"))
    n1Final=0
    n2Final=0
    while n1!=0:
        if n1>=10:
            r1=n1%10
            n1= n1//10
            n1Final=n1Final+r1
        if n1<10:
            n1Final=n1Final+n1
            n1=0
    if n1Final>10:
               while n1Final>10:
                   r1=n1Final%10
                   n1Final=n1Final//10
                   n1Final=n1Final+r1
    while n2!=0:
        if n2>=10:
            r2=n2%10
            n2= n2//10
            n2Final=n2Final+r2
        if n2<10:
            n2Final=n2Final+n2
            n2=0
    if n2Final>10:
               while n2Final>10:
                   r2=n2Final%10
                   n2Final=n2Final//10
                   n2Final=n2Final+r2
    m+=1
    if n1Final==n2Final:
        numAcertos+=1
afinidade=numAcertos/numJogadas

resposta=input("Deseja simular jogadas aleatorias (S/N)?  \n")
if resposta=='N':
    if afinidade>=0 and afinidade<(1/3):
        print("A afinidade de voces e de", afinidade,"\nA afinidade de voces e baixa. Que pena!")
    if afinidade>=(1/3) and afinidade<(2/3):
        print("A afinidade de voces e de ",afinidade,"\nA afinidade de voces e mediana!")
    if afinidade>=(2/3):
        print("A afinidade de voces e de ",afinidade,"\nParabens! Voces tem uma bela afinidade!")
    resposta=0

if resposta=='S':
    afinidade=0
    t=1
    j=1
    while t<=10000:
        while j<=numJogadas:
            n12= (22695477 * numero_aleatorio_anterior + 1) % 2**32
            numero_aleatorio_anterior=n12
            n22= (22695477 * numero_aleatorio_anterior + 1) % 2**32            
            numero_aleatorio_anterior=n22
            n12Final=0
            n22Final=0
            while n12!=0:
                if n12>=10:
                    r12=n12%10
                    n12= n12//10
                    n12Final=n12Final+r12
                if n12<10:
                    n12Final=n12Final+n12
                    n12=n12//10
            if n12Final>=10:
               while n12Final>=10:
                   r12=n12Final%10
                   n12Final=n12Final//10
                   n12Final=n12Final+r12
            while n22!=0:
                if n22>=10:
                    r22=n22%10
                    n22= n22//10
                    n22Final=n22Final+r22
                if n22<10:
                    n22Final=n22Final+n22
                    n22=n22//10
            if n22Final>=10:
               while n22Final>=10:
                   r22=n22Final%10
                   n22Final=n22Final//10
                   n22Final=n22Final+r22
            if n12Final==n22Final:
                numAcertos2+=1
            j+=1
        if numAcertos2>=numAcertos:
            q+=1
        numAcertos2=0
        j=1
        t+=1
    afinidade=1-(q/10000)
    if afinidade>=0 and afinidade<(1/3):
        print("A afinidade de voces e de", afinidade,"\nA afinidade de voces e baixa. Que pena!")
    if afinidade>=(1/3) and afinidade<(2/3):
        print("A afinidade de voces e de ",afinidade,"\nA afinidade de voces e mediana!")
    if afinidade>=(2/3):
        print("A afinidade de voces e de ",afinidade,"\nParabens! Voces tem uma bela afinidade!")

