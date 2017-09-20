int potPin = A0;
int led1 = D5;
int led2 = D6;
int led3 = D7;
int led4 = D8;

float val = 0;


//float mapFloat(float x, float in_min, float in_max, float out_min, float out_max)
//{
 // return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
//}


void setup() {
   Serial.begin(115200);
   pinMode(potPin, INPUT);
  
}


void loop(){
  val = analogRead(potPin);
  int percent = map(val, 0, 1023, 0, 100);
  Serial.println( percent);

  if (percent < 25){
    int p1 = (percent/25)* 100;
    int mapped1 = map(p1, 0, 100, 0, 1023);
    analogWrite(led1, mapped1);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
    analogWrite(led4, 0);
 
  }



  else if(percent >= 25 && percent <50){
    int p2 = ((percent-25)/25)* 100;
    int mapped2 = map(p2, 0, 100, 0, 1023);
    analogWrite(led1, 1023);
    analogWrite(led2, mapped2);
    analogWrite(led3, 0);
    analogWrite(led4, 0); 
   }

   else if(percent >= 50 && percent <75){
    int p3 = ((percent-50)/25)* 100;
    int mapped3 = map(p3, 0, 100, 0, 1023);
    analogWrite(led1, 1023);
    analogWrite(led2, 1023);
    analogWrite(led3, mapped3);
    analogWrite(led4, 0); 
   }

   else if(percent >= 75 && percent <=100){
    int p4 = ((percent-75)/25)* 100;
    int mapped4 = map(p4, 0, 100, 0, 1023);
    analogWrite(led1, 1023);
    analogWrite(led2, 1023);
    analogWrite(led3, 1023);
    analogWrite(led4, mapped4); 
   }
  

  delay(2);
}

