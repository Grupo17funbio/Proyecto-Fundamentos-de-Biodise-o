// INCLUSIÓN BT

//Inclusión de la librería indicada
#include <SoftwareSerial.h>

//Asignación de a qué pines del Arduino se conecta el módulo BT
SoftwareSerial miBT(10, 11);

// PROGRAMA DEL ARDUINO

//Asignación de nombres a los pines del A0 al A5.
int pinA0 = 0;
int pinA1 = 1;
int pinA2 = 2;
int pinA3 = 3;
int pinA4 = 6;
int pinA5 = 7;


//Asignación de variables a la lectura de los sensores.
int LecSensor1;
int LecSensor2;
int LecSensor3;
int LecSensor4;
int LecSensor5;
int LecSensor6;


//Asignación de valores fijos a una presión nula y a una presión alta.
int no_presion= 5;
int alta_presion= 900;
int bloques_suma_presion = 3000;

//INICIO DEL PROGRAMA

void setup(void)
{
//Inicio del programa del ARDUINO
Serial.begin(9600);
//Inicio del programa del BT
miBT.begin(9600);
}

//EJECUTACIÓN DEL PROGRAMA 

void loop (void){
 LecSensor1 = analogRead(pinA0);
 Serial.print("Lectura Celda1 = ");
 Serial.print(LecSensor1);
 Serial.print(" , ");
 LecSensor2 = analogRead(pinA1);
 Serial.print("Lectura Celda2 = ");
 Serial.print(LecSensor2);
  Serial.print(" , ");
 LecSensor3 = analogRead(pinA2);
 Serial.print("Lectura Celda3 = ");
 Serial.print(LecSensor3);
 Serial.print(" , ");
 LecSensor4 = analogRead(pinA3);
 Serial.print("Lectura Celda4 = ");
 Serial.print(LecSensor4);
 Serial.print(" , ");
 LecSensor5 = analogRead(pinA4);
 Serial.print("Lectura Celda5 = ");
 Serial.print(LecSensor5);
 Serial.print(" , ");
 LecSensor6 = analogRead(pinA5);
 Serial.print("Lectura Celda6 = ");
 Serial.println(LecSensor6);
  
  
//Si la suma de sensores, es menor al valor de presión base
//la presión está controlada.
  
if (LecSensor1 + LecSensor2 + LecSensor3 + LecSensor4 +
    LecSensor5 + LecSensor6 < bloques_suma_presion) {
  	miBT.println("N");
} 

  
//Si la suma de sensores, es mayor al valor de presión base
//existe una presión irregular y se debe indicar 
//qué o cuales celdas provocan la misma.
  
if (LecSensor1 + LecSensor2 + LecSensor3 + LecSensor4 +
    LecSensor5 + LecSensor6 > bloques_suma_presion) {
  	miBT.println("E");
	
	if (alta_presion < LecSensor1) {
    miBT.println("1");
		} 
  
	if (alta_presion < LecSensor2) {
  	miBT.println("2");
	} 
  
	if (alta_presion < LecSensor3) {
  	miBT.println("3");
	} 
  
    if (alta_presion < LecSensor4) {
    miBT.println("4");
	}
  
	if (alta_presion < LecSensor5) {
    miBT.println("5");
    }
	
  	if (alta_presion < LecSensor6) {
    miBT.println("6");
    }
}
  
  delay(1000); //El proceso se repite cada 5 segundos
}
