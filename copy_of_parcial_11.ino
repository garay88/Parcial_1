int pinData  = 11;
int pinLatch = 8;
int pinClock = 12;

#define TIEMPO 200

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
   ledWrite(B00000000,B00000001); delay(TIEMPO);
   ledWrite(B00000000,B00000010); delay(TIEMPO);
   ledWrite(B11000000,B00000100); delay(TIEMPO);
   ledWrite(B11100000,B00001000); delay(TIEMPO);
   ledWrite(B11110000,B00010000); delay(TIEMPO);
   ledWrite(B11111000,B00100000); delay(TIEMPO);
   ledWrite(B11111100,B01000000); delay(TIEMPO);
   ledWrite(B11111110,B10000000); delay(TIEMPO);
  
}