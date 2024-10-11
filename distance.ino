#include <SoftwareSerial.h>
SoftwareSerial bt(3,2);

int c=0;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(12,INPUT);
Serial.begin(9600);
bt.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(bt.available()){
  Serial.write(bt.read());
}
if (Serial.available()){
  bt.write(Serial.read());
}

digitalWrite(13,HIGH);
delayMicroseconds(10);
digitalWrite(13,LOW);
int d = pulseIn(12,HIGH)*340/2/10000;
Serial.println(d);
if (d < 7 && c == 0){  
  bt.print("move");
  Serial.print("move");
  c=1;
}

else if (d >= 7 && c==1){
  c=0;
  bt.print("no");
  Serial.print("no");
}
delay(100);
}
