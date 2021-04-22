unsigned long Time = millis();   //Tiempo de programa
unsigned long *ptrTime;
int Duracion = 10000;   //Duración predeterminada en milisegundos
int **puntero_clear,nFilas,nCol,Cont = 1;
int8_t SER  = 3;    //Entrada
int8_t RCLK = 2;    //Reloj de regristo de salida
int8_t SRCLK = 4;   //Reloj de desplazamiento
int8_t Option;

void ledWrite(int GLed, int RLed){  //Gled = Columnas; Rled = Filas
  
   /*Los datos se envian de tal manera que los primeros que ingresan 
   son los ultimos en la posicion del integrado, si estan en */ 
   
   shiftOut(SER, SRCLK, LSBFIRST, RLed);
   shiftOut(SER, SRCLK, MSBFIRST, GLed);
  
   /*Activar el flanco de subido del regristo de salida. */
   digitalWrite(RCLK, LOW);
   digitalWrite(RCLK, HIGH);
   digitalWrite(RCLK, LOW);
}

void clear(){
   nFilas=8;
   nCol=2;
  
   puntero_clear = new int*[nFilas];
  
   for(int i = 0;i<nFilas;i++){
   puntero_clear[i] = new int[nCol];
   }
  
   for(int i = 0;i<nFilas;i++,Cont = Cont*2){
      *(*(puntero_clear+i)+0) = 255;
      *(*(puntero_clear+i)+1) = Cont;

   }
}

void Full(){

}

void setup(){
   pinMode(SER, OUTPUT);
   pinMode(RCLK, OUTPUT);
   pinMode(SRCLK, OUTPUT);
  
   Serial.begin(9600);
}

void loop(){
  //Mensaje de bienvenida
  Serial.println(" ");
  Serial.println("      Welcome to Parcial_1");
  Serial.println(" "); 
  Serial.println("Mostrar matriz predeterminada: 1");
  Serial.println("      Verificar matriz: 2");
  Serial.println("        Crear Matriz: 3");
  
  //Ingreso de opcion de usuario
  while (Serial.available()==0){}
  Option = Serial.parseInt();
  switch(Option){
    case 1:   //Matriz pretederminada
      ptrTime=&Time;
        *ptrTime = millis();
        while (Time%Duracion < Duracion/2){    //
            *ptrTime = millis();
            ledWrite(0,1);    // * leds fila 1
            ledWrite(0,;2)    // * leds fila 2
            ledWrite(31,4);   // 3 primeros led fila 3
            ledWrite(1,8);    // Todos menos el ultimo fila 4
            ledWrite(248,16);   // Los tres ultimos fila 5
            ledWrite(56,32);    // Fila 6
            ledWrite(0,64);     // * leds Fila 7
            ledWrite(129,128);  // *(1,8) Fila 8  
        }
        
      ledWrite(255,0);    
        ledWrite(255,2);      
        ledWrite(255,4);    
        ledWrite(255,8);    
        ledWrite(255,16);    
        ledWrite(255,32);     
        ledWrite(255,64);     
        ledWrite(255,128);    
      
        break;
      
      
        
  }
  
  /*
  digitalWrite(Reset, HIGH);
  
  while(myTime<2000){
       Serial.println(myTime);
       Serial.println(globalTime);
       ledWrite(0,1);   // * leds fila 1
       ledWrite(0,2);     // * leds fila 2
       ledWrite(31,4);    // 3 primeros led fila 3
       ledWrite(1,8);     // Todos menos el ultimo fila 4
       ledWrite(248,16);    // Los tres ultimos fila 5
       ledWrite(56,32);     // Fila 6
       ledWrite(0,64);    // * leds Fila 7
       ledWrite(129,128);   // *(1,8) Fila 8  
  }
  Serial.println(myTime);  
  digitalWrite(Reset, LOW);
  
  
  while(myTime<2000){
       ledWrite(255,1);   
       ledWrite(255,2);   
       ledWrite(255,4);   
       ledWrite(255,8);     //Todo en blanco
       ledWrite(255,16);   
       ledWrite(255,32);   
       ledWrite(255,64);   
       ledWrite(255,128);   
  }
  Serial.println(myTime);  
  digitalWrite(Reset, LOW);
  */
   
}
