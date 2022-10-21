#include <stdio.h>
#include <stdlib.h>

void transformTxt() //recebe o txtIn e converte pra escrever no txtOut
{
  FILE *fileIn; //pega o esc.in
  int numsInTxt[1000]; //array grande o suficiente 
  int n = 0; //contador
  fileIn = fopen("escadinha.in", "r"); //abre o esc.in
  if(fileIn != NULL) //se tiver numeros dentro realiza o processo
  {
    while (fscanf(fileIn, "%i", &numsInTxt[n]) != EOF) //lê o esc.in e salva num array
    {
      n++; //add no contador
    }
    fclose(fileIn); //fecha o esc.in
  }

  FILE *fileOut; //pega/cria o esc.out
  fileOut = fopen("escadinha.out", "w"); //abre o esc.out
  for(int i = 0; i < n-1; i++) //conversão pedida na questão
  {
    if(numsInTxt[i] > numsInTxt[i+1]){fputs("-1\n",fileOut);}
    else if(numsInTxt[i] < numsInTxt[i+1]){fputs("1\n",fileOut);}
    else{fputs("0\n",fileOut);}
  }
  fclose(fileOut); //fecha est.out
}

int main(void) 
{
  transformTxt(); //Chama funç que recebe arquivo TXT com X numeros e cria um arquivo TXT com Y numeros
}

//by Artur Raffael