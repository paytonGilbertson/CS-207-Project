
void rotateRight()
{
  //This controls the motors to make the bot turn right
  digitalWrite(leftMotorA,HIGH);
  digitalWrite(leftMotorB,LOW);

  digitalWrite(rightMotorA,LOW);
  digitalWrite(rightMotorB,HIGH);    
}

//This contorls the bot to make it rotate left
void rotateLeft()
{
  digitalWrite(leftMotorA,LOW);
  digitalWrite(leftMotorB,HIGH);

  digitalWrite(rightMotorA,HIGH);
  digitalWrite(rightMotorB,LOW);  

}
//this makes the robot drive foward
void drive()
{
  //left motor forward
    digitalWrite(leftMotorA, HIGH);
    digitalWrite(leftMotorB,LOW);

//right motor forward
    digitalWrite(rightMotorA,HIGH);
    digitalWrite(rightMotorB,LOW);
}
void Stop()
{
  //turn motors off
  digitalWrite(leftMotorA,LOW);
  digitalWrite(leftMotorB,LOW);

  
  digitalWrite(rightMotorB,LOW);
  digitalWrite(rightMotorA,LOW);
}
