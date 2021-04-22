unsigned long Time;	//Tiempo de programa
const int d = 10000;                      //Duración en milisegundos del ciclo completo
int8_t SER  = 3;	//Entrada
int8_t RCLK = 2;	//Reloj de regristo de salida
int8_t SRCLK = 4;	//Reloj de desplazamiento
int8_t Reset = 5;	//Borrar registro de desplazamiento
int8_t Option;

void ledWrite(int GLed, int RLed){	//Gled = Columnas; Rled = Filas
  
   /*Los datos se envian de tal manera que los primeros que ingresan 
   son los ultimos en la posicion del integrado, si estan en */ 
   
   shiftOut(SER, SRCLK, LSBFIRST, RLed);
   shiftOut(SER, SRCLK, MSBFIRST, GLed);
  
   /*Activar el flanco de subido del regristo de salida. */
   digitalWrite(RCLK, LOW);
   digitalWrite(RCLK, HIGH);
   digitalWrite(RCLK, LOW);
}

void setup(){
   pinMode(SER, OUTPUT);
   pinMode(RCLK, OUTPUT);
   pinMode(SRCLK, OUTPUT);
   pinMode(Reset, OUTPUT);
  
   Serial.begin(9600);
int Encenderleds(){
    	ledWrite(fila1,colm1);		
        ledWrite(fila2,colm2);  		
        ledWrite(fila3,colm3);  	
        ledWrite(fila4,colm4);   	
        ledWrite(fila5,colm5);    
        ledWrite(fila6,colm6);   	
        ledWrite(fila7,colm7);   	
        ledWrite(fila8,colm8);   	
        digitalWrite(Reset, LOW);
}
    
int verificación (){
  fila1=255; fila2=255; fila3=255; fila4=255;
  fila5=255; fila6=255; fila7=255; fila8=255;
  colm1=0;colm2=0;colm3=0;colm4=0;
  colm5=0;colm6=0;colm7=0;colm8=0;
  Encenderleds();
  }
/*int publik(){
  //el usuario ingresa el numero de patrones y el tiempo
  while (Npatrones>0){
    Imagen(); //se invoca la funcion imagen 
    delay=tiempo;
    Npatrones--;
    */
  }