Mode findCase(long frontD,long rightD)
{
  //This runs into a dead end but is open on the right
  Mode case1;
  if(rightD > 6 && rightD < 100)
  {
    case1 = RIGHT_TURN_ONLY;
  }
  //This case covers left turns and complete dead ends so it will turn 180 or turn left
  else if(frontD < 5 && rightD <= 6)
  {
    case1 = LEFT_TURN_ONLY;
  }
  //this covers cases where it continues forward and has an open right turn
  else if(frontD >= 5 && rightD > 6 && rightD < 100)
  {
    case1 = CROSS;
  }
  //This covers the case of a straight hallway
  else if(frontD>=5 && rightD <= 8)
  {
    case1 = CONT_LINE;
  }
  //This is when the bot is out of the maze.
  else if(frontD > 100 && rightD >=100 )
  {
    case1 = NO_WALL;
  }





  return case1;
}
