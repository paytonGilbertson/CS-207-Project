Mode findCase(long frontD, long rightD)
{
  Mode case1;
  //Has soon as the right sensor was open the arduino new to stop and turn to that direction
  if (rightD > 25 && rightD < 100)
  {
    case1 = RIGHT_TURN_ONLY;
  }
  //This case covers left turns and complete dead ends so it will turn 180 or turn left
  //if the front sensor was at a certain threshold and if the right sensor could find a wall
  else if (frontD < 15 && rightD <= 25)
  {
    case1 = LEFT_TURN_ONLY;
  }
  //This covers the case of a straight hallway
  else if (frontD >= 5 && rightD <= 25)
  {
      case1 = CONT_LINE;
  }
  //This is when the bot is out of the maze.
  else if (frontD > 100 && rightD >= 100 )
  {
    case1 = NO_WALL;
  }
  return case1;
}
