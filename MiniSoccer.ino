

int rf=6,rb=7,  lf=9,lb=8; //in1234
int rs=5,ls=10; //ENA ENB
int Bspd=26;
int speed = 254; // Set the initial speed value here
char command;
void setup() {
  Serial.begin(9600);
   pinMode(rf,OUTPUT); 
   pinMode(rb,OUTPUT); 
   pinMode(lf,OUTPUT);
   pinMode(lf,OUTPUT); 
   pinMode(rs,OUTPUT); 
  pinMode(ls,OUTPUT); 
  
}




void loop() {

  signal();
  Action(command);
}
