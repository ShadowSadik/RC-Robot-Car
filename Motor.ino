void forward() {
  follow(1,speed,1);
  follow(2,speed,1);

}

void backward() {

    follow(1,speed,0);
  follow(2,speed,0);
 
}

void leftTurn() {
   follow(1,speed,1);
  follow(2,speed,0);
}

void rightTurn() {
  follow(1,speed,0);
  follow(2,speed,1);
}

void forwardLeft() {
     follow(1,speed,1);
     follow(2,0,1);
}

void forwardRight() {

  
     follow(1,0,1);
     follow(2,speed,1);
}

void backLeft() {
      follow(1,speed,0);
  follow(2,0,0);
  
}

void backRight() {
 
     follow(1,0,0);
     follow(2,speed,0);
}

void stopMotors() {
   follow(1,0,0);
  follow(2,0,0);
}









void follow(int m, int spd, int direction){
  
  boolean inPin1=HIGH;
  boolean inPin2=LOW;
  
  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
    
  }  
  if(direction == 0){
    inPin1 = LOW;
    inPin2 = HIGH;
    
  }

  if(m == 1){
    digitalWrite(rf, inPin1);
    digitalWrite(rb, inPin2);
    analogWrite(rs,spd);
    
  }  

  

  if(m == 2){
    digitalWrite(lf, inPin1);
    digitalWrite(lb, inPin2);
    if(spd<30)
    {
      analogWrite(ls, spd);
    }
    else
    {
      analogWrite(ls, spd);
    }
    
    
  }

 
 
}
