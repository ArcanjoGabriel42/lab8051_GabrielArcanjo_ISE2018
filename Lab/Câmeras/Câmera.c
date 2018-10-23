#include <at89x52.h>

#define CAMERA1 P2_0
#define CAMERA2 P2_1
#define CAMERA3 P2_2
#define CAMERA4 P2_3

#define SENSOR1 P1_0
#define SENSOR2 P1_1
#define SENSOR3 P1_2
#define SENSOR4 P1_3

#define Alarm P2_4
#define Siren P2_5
#define REC P2_6

const int LIGADO = 0;
const int DESLIGADO = 1;

int esta_vazia();
void rotina_1();
void rotina_2();
void rotina_3();
void rotina_4();
void camera();
void delay(unsigned int tempo_ms);
void exception() interrupt 0{
	Siren = LIGADO;
	if (Alarm == DESLIGADO){
		Siren = DESLIGADO;
		P3_2 = 1;
	}
}

void main(){
	EA = 1;
	EX0 = 1;
	while(1){
		if (Alarm == LIGADO & !esta_vazia()){
			P3_2 = 0;
		}
		else if (!esta_vazia())
		{
			REC = LIGADO;
			camera();
		}else{
			REC = DESLIGADO;
		}
	}
}
void rotina1(){
	CAMERA1 = LIGADO;
	delay(3000);
	CAMERA1 = DESLIGADO;
	CAMERA2 = LIGADO;
	delay(3000);
	CAMERA2 = DESLIGADO;
	CAMERA3 = LIGADO;
	delay(3000);
	CAMERA3 = DESLIGADO;
	CAMERA4 = LIGADO;
	delay(3000);
	CAMERA4 = DESLIGADO;
	CAMERA1 = LIGADO;
	delay(3000);
}
void rotina2(){
	CAMERA2 = LIGADO;
	delay(3000);
	CAMERA2 = DESLIGADO;
	CAMERA3 = LIGADO;
	delay(3000);
	CAMERA3 = DESLIGADO;
	CAMERA4 = LIGADO;
	delay(3000);
	CAMERA4 = DESLIGADO;
	CAMERA1 = LIGADO;
	delay(3000);
	CAMERA1 = DESLIGADO;
	CAMERA2 = LIGADO;
	delay(3000);
	CAMERA2 = DESLIGADO;
}
void rotina3(){
	CAMERA3 = LIGADO;
	delay(3000);
	CAMERA3 = DESLIGADO;
	CAMERA4 = LIGADO;
	delay(3000);
	CAMERA4 = DESLIGADO;
	CAMERA1 = LIGADO;
	delay(3000);
	CAMERA1 = DESLIGADO;
	CAMERA2 = LIGADO;
	delay(3000);
	CAMERA2 = DESLIGADO;
	CAMERA3 = LIGADO;
	delay(3000);
	CAMERA3 = DESLIGADO;	
}
void rotina4(){
	CAMERA4 = LIGADO;
	delay(3000);
	CAMERA4 = DESLIGADO;
	CAMERA1 = LIGADO;
	delay(3000);
	CAMERA1 = DESLIGADO;
	CAMERA2 = LIGADO;
	delay(3000);
	CAMERA2 = DESLIGADO;
	CAMERA3 = LIGADO;
	delay(3000);
	CAMERA3 = DESLIGADO;
	CAMERA3 = LIGADO;
	delay(3000);
	CAMERA4 = DESLIGADO;
}
int esta_vazia(){
	return ((SENSOR1 == DESLIGADO) & (SENSOR2 == DESLIGADO) & (SENSOR3 == DESLIGADO) & (SENSOR4 == DESLIGADO));
}
void camera(){
	if (SENSOR1 == LIGADO){
		rotina1();
	}else if (SENSOR2 == LIGADO){
		rotina2();
	}else if (SENSOR3 == LIGADO){
		rotina3();
	}else{
		rotina4();
	}
}
void delay(unsigned int tempo_ms){
	int i,j;
	for (i = 0; i < tempo_ms; i++){
		for (j = 0; j < 12000; j++){
		}
	}
}