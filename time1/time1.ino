unsigned long t;                         //Es muy importante respetar el tipo de dato
const int d = 2000;                      //Duración en milisegundos del ciclo completo
void setup() {
   pinMode(13, OUTPUT);
   Serial.begin(9600);
}
void loop() {
   
   while (1){
     t = millis();
     Serial.println(t);
     while (t%d < d/2){
        t = millis();
        Serial.println(t%d );
        Serial.println(d/2);
        digitalWrite(13,HIGH);             //Prende LED
        Serial.println(t);
     }
     digitalWrite(13, LOW);              //Apaga LED
     Serial.println(t);
     delay(1000);
     break;
     
   }
}


