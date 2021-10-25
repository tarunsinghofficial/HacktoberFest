#include<stdio.h>

int main(){
	
	float velocidade;
	float tempo;
	float distancia;
	float combustivel;
	
	printf("Trmpo em h: ");
	scanf("%f", &tempo);
	
	printf("Velocidade media: ");
	scanf("%f", &velocidade);
	
	distancia = tempo * velocidade;
	combustivel = distancia/12;
	
	printf("Velocidade media e %f", velocidade);
	printf("\nTempo de viagem e %f", tempo);
	printf("\nDistancia percorrida %f", distancia);
	printf("\nQuantidade de litros foi %f", combustivel);
	
	return 0;
}
