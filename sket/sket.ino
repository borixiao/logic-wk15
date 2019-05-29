
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
byte colDataMatrix[8] = { B01111111,
   B10111111,
   B11011111,
   B11101111,
   B11110111,
   B11111011,
   B11111101,
   B11111110
  };
  byte colDataMatrix1[8] = { B10000000,
   B01000000,
   B00100000,
   B00010000,
   B00001000,
   B00000100,
   B00000010,
   B00000001
  };
                      
byte rowDataMatrix[8] = { B11111111,
            B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111
  };
  byte rowDataMatrix1[8] = { B00000000,
            B01111110,
    B01111110,
    B01111110,
    B01111110,
    B01111110,
    B01111110,
    B00000000
  };
 
 // 定義顯示器顯示的時間 (延遲時間), 預設 1ms
int delay_time = 1;
const int buttonPin=2;
int buttonState=0; 

 
void setup() {
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(buttonPin,INPUT_PULLUP);
}
void loop() {

  buttonState=digitalRead(buttonPin);
Serial.println(buttonState);
if(buttonState==HIGH){ 
    for(int i = 0; i < 8 ; i++){
   //byte colData = colDataMatrix[i];
  digitalWrite(latchPin,LOW);
    //  pickDigit(i);
     shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);
      //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      digitalWrite(latchPin,HIGH);
      delay(delay_time);
    }
}else {
      for(int i = 0; i < 8 ; i++){
           //byte colData = colDataMatrix[i];
          digitalWrite(latchPin,LOW);
            //  pickDigit(i);   
             shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix1[i]);
              shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix1[i]);
           
              //shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
              digitalWrite(latchPin,HIGH);
              delay(delay_time);
       }
}

}
void pickDigit(int x) {
  byte rowByte = 1 << x;
  shiftOut(dataPin, clockPin, MSBFIRST, rowByte);
  
}



