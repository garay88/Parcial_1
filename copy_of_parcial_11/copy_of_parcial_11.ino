int SER  = 3;
int RCLK = 2;
int SRCLK = 4;
int i;

#define TIEMPO 1000

void Clock(){
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);  
}

void Print(){
  digitalWrite(RCLK,0);
  digitalWrite(RCLK,1);
  digitalWrite(RCLK,0);
}
 


void ledWrite(int RLed, int GLed){
   
   shiftOut(SER, SRCLK, LSBFIRST, GLed);
   shiftOut(SER, SRCLK, MSBFIRST, RLed);
  
   digitalWrite(RCLK, HIGH);
   digitalWrite(RCLK, LOW);
}

void setup(){
   pinMode(SER, OUTPUT);
   pinMode(RCLK, OUTPUT);
   pinMode(SRCLK, OUTPUT);
}

void loop(){
  
  for(i=0;i<100;i++){
    
     ledWrite(B00000000,B00000001);   // * leds fila 1
     ledWrite(B00000000,B00000010);   // * leds fila 2
     ledWrite(B00011111,B00000100);   // 3 primeros led fila 3
     ledWrite(B00000001,B00001000);   // Todos menos el ultimo fila 4
     ledWrite(B11110000,B00010000);   // Los tres ultimos fila 5
     ledWrite(B01100000,B00100000);   // Fila 6
     ledWrite(B00000000,B01000000);   // * leds Fila 7
     ledWrite(B10000001,B10000000);   // *(1,8) Fila 8
    
  }
  
  ledWrite(B00000000,B00000000);   // * leds fila 1
  ledWrite(B00000000,B00000000);   // * leds fila 2
  ledWrite(B11111000,B00000000);   // 3 primeros led fila 3
  ledWrite(B10000000,B00000000);   // Todos menos el ultimo fila 4
  ledWrite(B00001111,B00000000);   // Los tres ultimos fila 5
  ledWrite(B00000000,B00000000);   // Fila 6
  ledWrite(B00000000,B00000000);   // * leds Fila 7
  ledWrite(B10000001,B00000000);   // *(1,8) Fila 8
  
  delay(2000);
}


/*
void setup(){
  // (Paso 1) Configuracion de puertos digitales como salida
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  
  
  digitalWrite(SER, 0);
  digitalWrite(RCLK, 0);
  digitalWrite(SRCLK, 0);
*/
/* 
  // (Paso 2) Llevar el dato al puerto serial del 74HC595
  digitalWrite(SER,1);  //Fila 1
  
  // (Paso 3) Activar el reloj de la primera etapa de los registro
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,1);  //Fila 2
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,1);  //Fila 3
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,1);  //Fila 4
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
   
  digitalWrite(SER,0);  //FIla 5
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Fila 6
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Fila 7
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Fila 8
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Columna 1
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
   
  digitalWrite(SER,0);  //Columna 2
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0); //Columna 3
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
   
  digitalWrite(SER,0);  //Columna 4
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,0);  //Columna 5
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
   
  digitalWrite(SER,0);  //Columna 6
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(SER,1);  //Columna 7
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
   
  digitalWrite(SER,1);  //Columna 8
  digitalWrite(SRCLK,0);
  digitalWrite(SRCLK,1);
  digitalWrite(SRCLK,0);
  
  digitalWrite(RCLK,0);
  digitalWrite(RCLK,1);
  digitalWrite(RCLK,0);
*/
/*
  digitalWrite(SER,1);
  Clock();
  digitalWrite(SER,1);
  Clock();
  digitalWrite(SER,1);
  Clock();
  digitalWrite(SER,1);
  Clock();
  digitalWrite(SER,1);
  Clock();
  digitalWrite(SER,1);
  Clock();
  digitalWrite(SER,1);
  Clock();
  digitalWrite(SER,1);
  Clock();
  digitalWrite(SER,0);
  Clock();
  digitalWrite(SER,0);
  Clock();
  digitalWrite(SER,0);
  Clock();
  digitalWrite(SER,0);
  Clock();
  digitalWrite(SER,0);
  Clock();
  digitalWrite(SER,0);
  Clock();
  digitalWrite(SER,0);
  Clock();
  digitalWrite(SER,0);
  Clock();
  Print();
} 

void loop(){
}
*/


 
