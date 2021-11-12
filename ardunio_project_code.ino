int TempSenseInput=A1;
int PIRSenseInput=A0;
int PIRSenseOutput=13;
int TempRead=0;
int PIRValue=0;
void setup(){
  pinMode(TempSenseInput,INPUT);
  pinMode(PIRSenseInput,INPUT);
  pinMode(PIRSenseOutput,OUTPUT);
  Serial.begin(9600);
  }
void loop(){
TempRead=analogRead(TempSenseInput);
PIRValue=analogRead(PIRSenseInput);
float MVRead=(TempRead/1024.0)*5000;
float TempValue=MVRead/10;
  Serial.println("Temperature in Celcius:- ");
  Serial.println(TempValue);
  Serial.println(" C");
  if(TempValue<0)
  {
    Serial.println("Too Cold");
  }
  else{
    if(TempValue>=0 and TempValue<=50){
      Serial.println("Normal Situation");
    }
    else{
      if(TempValue>50 and TempValue<=60){
        Serial.println("Too Hot to live ");
      }
      else{
      Serial.println("Dangerous!! Escape as soon as possible ");
      }
    }
  }

  Serial.println(" Movement Observe is - ");
  Serial.println(PIRValue);
  if(PIRValue>=200)
  {
    Serial.println("Motion Detected!!");
    digitalWrite(PIRSenseOutput,HIGH);
  }
  else{
    Serial.println("Motion not Detected!!");
    digitalWrite(PIRSenseOutput,LOW);
  }
delay(1000);
}
