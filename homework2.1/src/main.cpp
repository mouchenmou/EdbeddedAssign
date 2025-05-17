#include <Arduino.h>
int i;

int pinlist[5]={27,26,25,33,32};
void setup() {
  for(int i=0;i<5;i++){
    pinMode(pinlist[i],OUTPUT);
  }
}
void loop(){
  for(i=0;i<5;i++){
    digitalWrite(pinlist[i],HIGH);
    delay(1000);
    digitalWrite(pinlist[i],LOW);
  }
  for(i=4;i>=0;i--){
    digitalWrite(pinlist[i],HIGH);
    delay(1000);
    digitalWrite(pinlist[i],LOW);
  }
}