long findDistance(const int& trigger,const int& echo)
{
  //This is using the sensors to find the distance between the robot and the wall
  long durAt, distCm;
  //This is the pulse the sensor sends it measures the time in the pulses to determine the distance
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  //this is the pulses being recieved
  durAt = pulseIn(echo,HIGH);
 //This is the converting the time into cm's 
  distCm = durAt/58.2;
  return distCm;  
}
