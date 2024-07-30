void signal()
{
    if (Serial.available() > 0) {
    command = Serial.read();
   int x;
    x=command-48;
    if(x==0 || x==1 || x==2 || x==3 || x==4 || x==5 || x==6 || x==7 || x==8 || x==9)
    {
      speed=Bspd*x;
    }
    if(command=='q')
    {
      speed=254;
    }
      
    }
}
