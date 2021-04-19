int SER  = 11;
int RCLK = 8;
int SRCLK = 12;
int i = 1;
#define TIEMPO 500

/*
void ledWrite(int RLed, int GLed){
   
   shiftOut(pinData, pinClock, LSBFIRST, GLed);
   shiftOut(pinData, pinClock, LSBFIRST, RLed);
   digitalWrite(pinLatch, HIGH);
   digitalWrite(pinLatch, LOW);
}

void setup(){
   pinMode(pinData, OUTPUT);
   pinMode(pinLatch, OUTPUT);
   pinMode(pinClock, OUTPUT);
}

void loop(){
   ledWrite(B00000000,B00000001);   // * leds fila 1
   ledWrite(B00000000,B00000010);   // * leds fila 2
   ledWrite(B00011111,B00000100);   // 3 primeros led fila 3
   ledWrite(B00000001,B00001000);   // Todos menos el ultimo fila 4
   ledWrite(B11111000,B00010000);   // Los tres ultimos fila 5
   ledWrite(B00111000,B00100000);   // Fila 6
   ledWrite(B00000000,B01000000);   // * leds Fila 7
   ledWrite(B10000001,B10000000);   // *(1,8) Fila 8
  
}
*/


void setup(){
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  
  digitalWrite(SER, 0);
  digitalWrite(RCLK, 0);
  digitalWrite(SRCLK, 0);
  
  // (Paso 1) Configuracion de puertos digitales como salida
  
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  
  digitalWrite(SER, 0);
  digitalWrite(RCLK, 0);
  digitalWrite(SRCLK, 0);
  
  delay(TIEMPO);
  
  // (Paso 2) Llevar el dato al puerto serial del 74HC595
  digitalWrite(SER,1);  //Fila 1
  
  // (Paso 3) Activar el reloj de la primera etapa de los registro
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Fila 2
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,1);  //Fila 3
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Fila 4
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
   
  digitalWrite(SER,1);  //FIla 5
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Fila 6
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,1);  //Fila 7
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Fila 8
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,1);  //Columna 1
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
   
  digitalWrite(SER,1);  //Columna 1
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,1);  //Columna 1
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
   
  digitalWrite(SER,0);  //Columna 1
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Columna 1
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
   
  digitalWrite(SER,0);  //Columna 1
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Columna 1
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
   
  digitalWrite(SER,0);  //Columna 1
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(RCLK,0);
  digitalWrite(RCLK,1);
  digitalWrite(RCLK,0);
  
  
  
  

}

void loop(){
  if (i==0){
    digitalWrite(SER,1);
    digitalWrite(SRCLK,0);
    digitalWrite(SRCLK,1);
    digitalWrite(SRCLK,0);

    digitalWrite(RCLK,0);
    digitalWrite(RCLK,1);
    digitalWrite(RCLK,0);

    delay(TIEMPO);

    digitalWrite(SER,0);

    digitalWrite(SRCLK,0);
    digitalWrite(SRCLK,1);
    digitalWrite(SRCLK,0);

    digitalWrite(RCLK,0);
    digitalWrite(RCLK,1);
    digitalWrite(RCLK,0);
  }
  

 
  
  
  
}
