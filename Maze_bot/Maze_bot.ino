
//This represent the different cases the Robot could run in to
enum Mode {NO_WALL, CONT_LINE, CROSS, LEFT_TURN_ONLY, RIGHT_TURN_ONLY, WALL, CONT_LINE_L, CONT_LINE_R};
Mode mode;


const int frontSensorEcho = 9;
const int frontSensorTrigger = 8;
const int rightSensorTrigger = 2;
const int rightSensorEcho = 3;

const int rightMotorA = 10;
const int rightMotorB = 11;
const int leftMotorA = 13;
const int leftMotorB = 12;

const int button = 7;

long frontDistance;
long rightDistance;
//This delay is how long the motors need to run to make a 90 degree turn
int turnDelay = 755;
int buttonState = 0;
int buttonCount = 0;
bool onOrOff = false;
void setup()
{
  pinMode(frontSensorTrigger, OUTPUT);
  pinMode(rightSensorTrigger, OUTPUT);
  pinMode(rightSensorEcho, INPUT);
  pinMode(frontSensorEcho, INPUT);

  Serial.begin(9600);

  pinMode(rightMotorA, OUTPUT);
  pinMode(rightMotorB, OUTPUT);

  pinMode(leftMotorA, OUTPUT);
  pinMode(leftMotorB, OUTPUT);

  pinMode(button, INPUT);
}

void loop()
{
  //This is used to turn the robot on and off it was to avoid it running rampant when we wanted to set it in the maze
  buttonState = digitalRead(button);
  if (buttonState == LOW)
  {
    buttonCount += 1;
    if (buttonCount == 1)
    {
      onOrOff = true;
    }
    else if (buttonCount == 0 || buttonCount > 1)
    {
      onOrOff = false;
      Stop();
      buttonCount = 0;
    }

  }



  frontDistance = findDistance(frontSensorTrigger, frontSensorEcho);
  //The serial.print fucntions were used for calibrating the distance and what we should use for turning thresholds
  //Serial.print("front sensor distance is: ");
  // Serial.println(frontDistance);

  rightDistance = findDistance(rightSensorTrigger, rightSensorEcho);
  Serial.print("Right sensor distance is: ");
  Serial.println(rightDistance);

  if (onOrOff)
  {
    mode = findCase(frontDistance, rightDistance);
    switch (mode)
    {


      case LEFT_TURN_ONLY:

        Stop();
        delay(150);
        rotateLeft();
        delay(turnDelay);
        Stop();
        delay(150);
        break;
      //This is because the right sensor is far foward on the arduino this is an adjustment to make it drive forward enough to make the corner.
      case RIGHT_TURN_ONLY:

        Stop();
        delay(100);
        drive();
        delay(200);
        Stop();
        delay(100);
        rotateRight();
        //The wheels are wonky and dont have the same power for turning this is to give more time to the right turn
        delay(turnDelay);
        drive();
        //this is to get it around the corner farther
        delay(600);
        Stop();
        break;

      case NO_WALL :
        Stop();
        delay(100);
        break;

      case CONT_LINE:
      //This is so it pulses frequentely while driving forward.
        drive();
        delay(55);
        Stop();
        break;

      case WALL:
        Stop();
        break;

    }
  }
  //This is to cause pauses between the pulses
  delay(50);
}
