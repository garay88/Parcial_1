unsigned long Time = millis();   //Tiempo de programa
unsigned long *ptrTime;
int Duracion = 7000;    //Duración predeterminada en milisegundos
int **puntero_clear;  //Puntero matriz clear
int **puntero_full;   //puntero matriz full
//int image[8]={};
int **puntero_image;  //puntero matriz imagen
int Cont = 1;     //Un contador sin nada especial
int8_t nFilas = 8;    //Numero de filas
int8_t nCol = 2;    //Numero de columnas
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

//Creo una matriz para que todos los led´s este en LOW
void clear(){
  
   puntero_clear = new int*[nFilas];
  
   for(int i = 0;i<nFilas;i++){
   puntero_clear[i] = new int[nCol];
   }
  
   for(int i = 0;i<nFilas;i++,Cont = Cont*2){
      *(*(puntero_clear+i)+0) = 255;
      *(*(puntero_clear+i)+1) = Cont;
   }
}

void full(){
  
   puntero_full = new int*[nFilas];
  
   for(int i = 0;i<nFilas;i++){
   puntero_full[i] = new int[nCol];
   }
  
   for(int i = 0;i<nFilas;i++,Cont = Cont*2){
      *(*(puntero_full+i)+0) = 0;
      *(*(puntero_full+i)+1) = Cont; 
   }
}

void image(int matriz[]){
  int *ptr_matriz;
  ptr_matriz=matriz;

  puntero_image = new int*[nFilas];
  for(int i = 0;i<nFilas;i++){
    puntero_image[i] = new int[nCol];
  }


  for(int i = 0;i<nFilas;i++,Cont = Cont*2){

      *(*(puntero_image+i)+0) = *ptr_matriz++;
      *(*(puntero_image+i)+1) = Cont;
  }
}


void viewMatriz(int **puntero, int nFilas, int nCol){
 for(int i=0;i<nFilas;i++){
    ledWrite((*(*(puntero+i)+0)),(*(*(puntero+i)+1)));         
 }
}

void print_Matriz(int **puntero, int nFilas, int nCol){
 for(int i=0;i<nFilas;i++){
     Serial.print(*(*(puntero+i)+0));
     Serial.println(" ");
     Serial.print( *(*(puntero+i)+1));
     Serial.println(" ");
 }
}
void setup(){
   pinMode(SER, OUTPUT);
   pinMode(RCLK, OUTPUT);
   pinMode(SRCLK, OUTPUT);
  
   Serial.begin(9600);
}

void loop(){
  
  Cont=1;
  
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
      while (Time%Duracion <= Duracion/2){    //
        *ptrTime = millis();
        ledWrite(0,1);    // * leds fila 1
        ledWrite(0,2);    // * leds fila 2
        ledWrite(31,4);   // 3 primeros led fila 3
        ledWrite(1,8);    // Todos menos el ultimo fila 4
        ledWrite(248,16);   // Los tres ultimos fila 5
        ledWrite(56,32);    // Fila 6
        ledWrite(0,64);     // * leds Fila 7
        ledWrite(129,128);  // *(1,8) Fila 8  
      }

      clear();
      viewMatriz(puntero_clear,nFilas,nCol);
      Serial.println(" ");
      Serial.println("       One moment, plis");
      delay(3000);  //Esto es para que el programa no se muera
      break;
    
    
    case 2:   //Mostrar toda la matriz encendida
      ptrTime=&Time;
      *ptrTime = millis();
      full();
      while (Time%Duracion < Duracion/2){    
        *ptrTime = millis();
        viewMatriz(puntero_full,nFilas,nCol);
      }
      clear();
      viewMatriz(puntero_clear,nFilas,nCol); 
      Serial.println(" ");
      Serial.println("       One moment, plis");
      delay(3000);  //Esto es para que el programa no se muera
      break;
     
    case 3:
      int imagen[8]={2,4,8,16,64,32,128,255}; 
      ptrTime=&Time;
      *ptrTime = millis();  
      image(imagen);
      print_Matriz(puntero_image,nFilas,nCol);
      while (Time%Duracion < Duracion/2){    
        *ptrTime = millis();
        viewMatriz(puntero_image,nFilas,nCol);
      }
      clear();
      viewMatriz(puntero_clear,nFilas,nCol); 
      Serial.println(" ");
      Serial.println("       One moment, plis");
      delay(3000);  //Esto es para que el programa no se muera
      break;  
      
  }
}
