#include <at89x52.h>
#define ESTEIRAPROD P2_0
#define ESTEIRABOX P2_1

const int LIGADO = 0;
const int DESLIGADO = 1;

void delay(unsigned int tempo_ms){
	int i,j;
	for (i = 0; i < tempo_ms; i++){
		for (j = 0; j < 12750; j++){
		}
	}
}

void timer() interrupt 1{
	TR0 = 0; //Para a contagem
	TH0 = 0xFF; //Caixa suporta somente 100 produtos
	TL0 = 0x9B; //Inicia os registradores com 65435
	
	ESTEIRAPROD = DESLIGADO; //Desliga a esteira de produtos
	ESTEIRABOX = LIGADO; //Liga as esteiras das caixas
	delay(1500); //Tempo para posicionamento da caixa
	ESTEIRABOX = DESLIGADO; //Desliga esteira das caixas
	ESTEIRAPROD = LIGADO; //Religa a esteira de produtos
	delay(500);
	TR0 = 1; //Religa contagens
	
}
int main(){
	EA = 1;
	ET0 = 1;
	TMOD = 1;
	TR0 = 1;
	
	while(1){
	}
}