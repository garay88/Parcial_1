int SER  = 3;
int RCLK = 2;
int SRCLK = 4;

void ledWrite(int GLed, int RLed){  //Gled = Columnas; Rled = Filas
  
   /*Los datos se envian de tal manera que los primeros que ingresan 
   son los ultimos en la posicion del integrado, si estan en */ 
   
   shiftOut(SER, SRCLK, LSBFIRST, RLed);
   shiftOut(SER, SRCLK, MSBFIRST, GLed);
  
   digitalWrite(RCLK, HIGH);
   digitalWrite(RCLK, LOW);
}

void setup(){
   pinMode(SER, OUTPUT);
   pinMode(RCLK, OUTPUT);
   pinMode(SRCLK, OUTPUT);
}

void loop(){
  
   
       ledWrite(0,1);   // * leds fila 1
       ledWrite(0,2);   // * leds fila 2
       ledWrite(0,4);   // 3 primeros led fila 3
       ledWrite(0,8);   // Todos menos el ultimo fila 4
       ledWrite(0,16);   // Los tres ultimos fila 5
       ledWrite(0,32);   // Fila 6
       ledWrite(0,64);   // * leds Fila 7
       ledWrite(0,128);   // *(1,8) Fila 8
     
   
}
