# -*- coding: utf-8 -*-
"""
Created on Sat Jun 26 23:02:39 2021

@author: lucid
"""
def main():
    alienigenas = []
    n = int(input("Quantidade de alienigenas: "))
    for i in range(0,n):
        alienigenas.append( leAlienigena(i) )
    return alienigenas
 
def leAlienigena(numero_alienigena):
    coordenadas = input("Alienigena %d: " %(numero_alienigena))
    coordenadas = coordenadas.split()
    for i in range(0,6):
        coordenadas[ i ] = int( coordenadas[ i ] )
        v0 = [ coordenadas[0], coordenadas[1] ]
        v1 = [ coordenadas[2], coordenadas[3] ]
        v2 = [ coordenadas[4], coordenadas[5] ]
    return v0, v1, v2
main()
   
funcao=7
while funcao>0:
    funcao=int(input("\nDigite a funcao que deseja testar: "))

    """Função 1"""
    def distancia0(v0,v1):
        x0=v0[0] 
        y0=v0[1] 
        x1=v1[0]  
        y1=v1[1] 
        deltax0=x1-x0 
        deltay0=y0-y1 
        if deltax0<0:
            deltax0=deltax0*(-1)
        if deltay0<0:
            deltay0=deltay0*(-1)
            
        if deltax0==0:
            quantidade0=deltay0
        if deltay0==0:
            quantidade0=deltax0
        if deltax0!=0 and deltay0!=0:
            if deltax0 < deltay0:
                deltax0,deltay0 = deltay0,deltax0
            while deltay0 > 0:
                r = deltax0 % deltay0
                deltax0 = deltay0
                deltay0 = r
            quantidade0=deltax0
            
            
        return quantidade0
    
    
    def distancia1(v1,v2):
        x2=v2[0] 
        y2=v2[1] 
        x1=v1[0]  
        y1=v1[1] 
        deltax1=x1-x2 
        deltay1=y2-y1 
        if deltax1<0:
            deltax1=deltax1*(-1)
        if deltay1<0:
            deltay1=deltay1*(-1)
            
        if deltax1==0:
            quantidade1=deltay1
        if deltay1==0:
            quantidade1=deltax1
        if deltax1!=0 and deltay1!=0:
            if deltax1 < deltay1:
                deltax1,deltay1 = deltay1,deltax1
            while deltay1 > 0:
                r = deltax1 % deltay1
                deltax1 = deltay1
                deltay1 = r
            quantidade1=deltax1
            
            
        return quantidade1
            
    def distancia2(v0,v2):
        x2=v2[0] 
        y2=v2[1] 
        x0=v0[0]  
        y0=v0[1] 
        deltax2=x0-x2 
        deltay2=y2-y0 
        if deltax2<0:
            deltax2=deltax2*(-1)
        if deltay2<0:
            deltay2=deltay2*(-1)
            
        if deltax2==0:
            quantidade2=deltay2
        if deltay2==0:
            quantidade2=deltax2
        if deltax2!=0 and deltay2!=0:
            if deltax2 < deltay2:
                deltax2,deltay2 = deltay2,deltax2
            while deltay2 > 0:
                r = deltax2 % deltay2
                deltax2 = deltay2
                deltay2 = r
            quantidade2=deltax2
            
            
        return quantidade2
    
    def quantidade():
        distancia0(v0,v1)
        distancia1(v1,v2)
        distancia2(v0,v2)
        quantidade=distancia0(v0,v1)+distancia1(v1,v2)+distancia2(v0,v2)
        return quantidade
    
    def pontosNaBorda(v0,v1,v2):
        quantidade()
        return quantidade()
        
    
    
    if funcao==1:
        elemento=int(input("\nNumero do alienigena:"))
        v0=alienigenas[elemento][0]
        v1=alienigenas[elemento][1]
        v2=alienigenas[elemento][2]
        pontosNaBorda(v0,v1,v2)
        print("\nQuantidade de pontos na borda:",pontosNaBorda(v0,v1,v2))
        
    """Função 2"""
    quantidades=[]
    def somaPontosNaBorda(alienigenas):
        quantidade()
        quantidades.append(quantidade())
        somaquantidade=0
        for i in quantidades:
            somaquantidade=somaquantidade+i
        
    
    if funcao==2:
        elemento=0
        somaquantidade=0
        while elemento<n:
            v0=alienigenas[elemento][0]
            v1=alienigenas[elemento][1]
            v2=alienigenas[elemento][2]
            somaPontosNaBorda(alienigenas)
            elemento+=1
        for i in quantidades:
            somaquantidade=somaquantidade+i
                
        print(somaquantidade)
       
    """Função 3"""
    ponto=[]
    def v():
        coordenadav=input("\nCoordenadas do ponto: ")
        coordenadav=coordenadav.split()
        for i in range(0,2):
            coordenadav[ i ] = int( coordenadav[ i ] )
            ponto.append(coordenadav[i])
        return ponto
    def pontoInterno(ponto,v0,v1,v2):
        if ponto==[]:
            v()
        v0x=v0[0]
        v0y=v0[1]
        v_1x=v1[0]-v0[0]
        v_1y=v1[1]-v0[1]
        v_2x=v2[0]-v0[0]
        v_2y=v2[1]-v0[1]
        vx=ponto[0]
        vy=ponto[1]
        
        a=((vx*v_2y-vy*v_2x)-(v0x*v_2y-v0y*v_2x))/((v_1x*v_2y)-(v_1y*v_2x))
        
        b=(-1)*((vx*v_1y-vy*v_1x)-(v0x*v_1y-v0y*v_1x))/((v_1x*v_2y-v_1y*v_2x))
        
        
        if a>0 and b>0 and a+b<1:
            return True
        else:
            return False
        
    def tiro():
        if pontoInterno(ponto,v0,v1,v2)==True:
            return "\nPonto interno ao triangulo!"
        else:
            return "\nPonto nao interno ao triangulo!"
    
    
    
    if funcao==3:
        elemento=int(input("\nNumero do alienigena: "))
        v0=alienigenas[elemento][0]
        v1=alienigenas[elemento][1]
        v2=alienigenas[elemento][2]
        print("\nCoordenadas do alienigena: ",(v0[0],v0[1]),",",(v1[0],v1[1]),",",(v2[0],v2[1]))
        pontoInterno(ponto,v0,v1,v2)
    
        print(tiro())
        ponto=[]
    
    
    """Função 4""" 
    x_min=[0]
    x_max=[0]
    y_min=[0]
    y_max=[0]
    def limitesDeBusca(v0, v1, v2):
        vx0=v0[0]
        vx1=v1[0]
        vx2=v2[0]
        vy0=v0[1]
        vy1=v1[1]
        vy2=v2[1]
        if vx0>=vx1 and vx0>=vx2:
            x_max[0]=vx0
        if vx0<=vx1 and vx0<=vx2:
            x_min[0]=vx0
        if vx1>=vx0 and vx1>=vx2:
            x_max[0]=vx1
        if vx1<=vx0 and vx1<=vx2:
            x_min[0]=vx1
        if vx2>=vx0 and vx2>=vx1:
            x_max[0]=vx2
        if vx2<=vx0 and vx2<=vx1:
            x_min[0]=vx2
        if vy0>=vy1 and vy0>=vy2:
            y_max[0]=vy0
        if vy0<=vy1 and vy0<=vy2:
            y_min[0]=vy0
        if vy1>=vy0 and vy1>=vy2:
            y_max[0]=vy1
        if vy1<=vy0 and vy1<=vy2:
            y_min[0]=vy1
        if vy2>=vy0 and vy2>=vy1:
            y_max[0]=vy2
        if vy2<=vy0 and vy2<=vy1:
            y_min[0]=vy2
            
        return x_min,x_max,y_min,y_max
    


   
    if funcao==4:
        elemento=int(input("\nNumero do alienigena: "))
        v0=alienigenas[elemento][0]
        v1=alienigenas[elemento][1]
        v2=alienigenas[elemento][2]
        limitesDeBusca(v0,v1,v2)
        print("Os limites são:",(x_min[0],y_min[0]),"e",(x_max[0],y_max[0]))
        x_min=[0]
        x_max=[0]
        y_min=[0]
        y_max=[0]     
        
        
    """Função 5"""
    ponto=[]
    def pontosInternos(v0,v1,v2):
        limitesDeBusca(v0, v1, v2)
        c=x_min[0]
        d=y_min[0]
        k=0
        while c<=x_max[0]:
            while d<=y_max[0]:
                ponto=[c,d]
                pontoInterno(ponto,v0,v1,v2)
                if pontoInterno(ponto,v0,v1,v2)==True:
                    k+=1
                d+=1
            d=y_min[0]
            c+=1
        return(k)
                    
            
    if funcao==5:
        elemento=int(input("\nNumero do alienigena: "))
        v0=alienigenas[elemento][0]
        v1=alienigenas[elemento][1]
        v2=alienigenas[elemento][2]
        limitesDeBusca(v0, v1, v2)
        pontosInternos(v0,v1,v2)
            
        print("\nQuantidade de pontos internos:",pontosInternos(v0,v1,v2))
            
    """Função 6"""
    soma=[]  

    def somaPontosInternos(alienigenas):
        pontosInternos(v0, v1, v2)
        soma.append(pontosInternos(v0,v1,v2))
      
        
    
    if funcao==6:
        somainterna=0
        for elemento in range(0,n):
            v0=alienigenas[elemento][0]
            v1=alienigenas[elemento][1]
            v2=alienigenas[elemento][2]
            somaPontosInternos(alienigenas)
            elemento+=1
        for j in soma:
            somainterna+=j
        print("\nSoma de pontos internos: ",somainterna)


if __name__ == '__main__':
   main()       