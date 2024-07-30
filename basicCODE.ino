#define l1 11
#define l2 10
#define r1 9
#define r2 6


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode (l1, OUTPUT);
pinMode (l2, OUTPUT);
pinMode (r1, OUTPUT);
pinMode (r2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available () >0 );
{
  int a = Serial.read();

  if (a== '1'); // forward going
  analogWrite (l1,255);
  analogWrite (l2,0);

  analogWrite (r1,255);
  analogWrite (r2,0);
  
  
}
else if (a== '2') // reverse going
{
  analogWrite (l1,0);
  analogWrite (l2,255);

  analogWrite (r1,0);
  analogWrite (r2,255);
  
}

else if (a=='3') //left turn
{
analogWrite (l1,0);
  analogWrite (l2,0);

  analogWrite (r1,255);
  analogWrite (r2,0);
  
}

else if (a=='4') //right turn
{
analogWrite (l1,255);
  analogWrite (l2,0);

  analogWrite (r1,0);
  analogWrite (r2,0);
  
}

else if (a=='5') //stop
{
  analogWrite (l1,0);
  analogWrite (l2,0);

  analogWrite (r1,0);
  analogWrite (r2,0);

}
