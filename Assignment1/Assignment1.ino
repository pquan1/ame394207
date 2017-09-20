//Implement PWM led, whose brightness is controlled by the potentiometer input.


int potPin = A0;
int LED = D5;
float val = 0;


float mapFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void setup() {
   Serial.begin(115200);
   pinMode(potPin, INPUT);
   pinMode(LED, OUTPUT);
}


void loop(){
  val = analogRead(potPin);
  float valMapped =  mapFloat(val,0,1023,0,200);
  analogWrite( LED, val);
  delay(2);
}

