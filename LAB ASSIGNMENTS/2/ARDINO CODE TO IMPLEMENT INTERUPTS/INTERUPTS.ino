int ledOn=0;
void setup() {
  
//put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(2,INPUT);
attachInterrupt(0,buttonPressed,RISING);
}

void loop() {
  
  //put your main code here, to run repeatedly:
}

 void buttonPressed() {
    if (ledOn)
    {
      ledOn=0;
      digitalWrite(8,LOW);
    }
    else {
      ledOn=1;
      digitalWrite(8,HIGH);
    }
  }
