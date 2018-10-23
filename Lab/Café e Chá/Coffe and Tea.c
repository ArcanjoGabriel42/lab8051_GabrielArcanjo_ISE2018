#include <at89x52.h>
#define HIB P2_0
#define K P2_1
#define T P2_2
#define COFFE P2_3
#define TEA P2_4
#define GLASS P2_5
const int LIGADO = 0;
const int DESLIGADO = 1;
int contador = 0;
void coin() interrupt 0{
	HIB = LIGADO;
}
void timer() interrupt 1{
	TR0 = 0;
	TH0 = 0x3C;
	TL0 = 0xAF;
	TR0 = 1;
	
	contador++;
	
	if (contador == 60 && (K == LIGADO || T == LIGADO)){
		contador = 0;
		if (K == LIGADO){
			K = DESLIGADO;
			COFFE = LIGADO;
		}else{
			T = DESLIGADO;
			TEA = LIGADO;
		}
	}
	if (contador == 100){
		TR0 = 0;
		contador = 0;
		COFFE = DESLIGADO;
		TEA = DESLIGADO;
		GLASS = LIGADO;
	}
}
int main(){
	EA = 1;
	EX0 = 1;
	ET0 = 1;
	IT0 = 1;
	TMOD = 1;
	while(1){
		if(HIB == LIGADO && K == LIGADO){
			TR0 = 1;
			HIB = DESLIGADO;
		}
		if(HIB == LIGADO && T == LIGADO){
			TR0 = 1;
			HIB = DESLIGADO;
		}
		if (GLASS == LIGADO){
			GLASS = DESLIGADO;
			P3_2 = DESLIGADO;
		}
	}
}