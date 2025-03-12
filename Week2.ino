#define Trig 13
#define Echo 12
#define ledG 8
#define ledR 7


void setup()
{
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
}

void loop()
{
  long duration,distance;
  
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  
  duration = pulseIn(Echo, HIGH);
  
  distance = duration/58.2;
    
  Serial.println(duration );
  Serial.print("\nDistance : ");
  Serial.print(distance);
  Serial.println(" Cm");
  
  delay(1000);
  
  if(distance>=100){
  	digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
  }
  else{
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
  }
}