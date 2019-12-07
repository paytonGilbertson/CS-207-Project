
//This represent the different cases the Robot could run in to
enum Mode {NO_WALL, CONT_LINE, LEFT_TURN_ONLY, RIGHT_TURN_ONLY};
Mode mode;

//These are the pins the ultarsonic sensors are attached to
const int frontSensorEcho = 9;
const int frontSensorTrigger = 8;
const int rightSensorTrigger = 2;
const int rightSensorEcho = 3;
//These are the pins that go to the hbridge
const int rightMotorA = 10;
const int rightMotorB = 11;
const int leftMotorA = 13;
const int leftMotorB = 12;
//This is the on off button
const int button = 7;
//Distance from the  front and right sensor
long frontDistance;
long rightDistance;

//This is the aproximate delay for how long the motors need to run to make a 90 degree turn
int turnDelay = 755;
//tracking the state of the on off button
int buttonState = 0;
int buttonCount = 0;
bool onOrOff = false;

void setup()
{
  //setting up the ultrasonic sensors
  pinMode(frontSensorTrigger, OUTPUT);
  pinMode(rightSensorTrigger, OUTPUT);
  pinMode(rightSensorEcho, INPUT);
  pinMode(frontSensorEcho, INPUT);
//starting communication with the serial to determine a good distance from the sensor
  Serial.begin(9600);
//activating the motors
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


//this determines the distance from the front sensor
  frontDistance = findDistance(frontSensorTrigger, frontSensorEcho);
  //The serial.print fucntions were used for calibrating the distance and what we should use for turning thresholds
  Serial.print("front sensor distance is: ");
  Serial.println(frontDistance);

  rightDistance = findDistance(rightSensorTrigger, rightSensorEcho);
  Serial.print("Right sensor distance is: ");
  Serial.println(rightDistance);
//This turns the bot on when the button is pushed
  if (onOrOff)
  {
    //this checks both sensors and decides if it should drive forward, turn left or turn right
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
      case RIGHT_TURN_ONLY:

        Stop();
        delay(100);
        //This is because the right sensor is far foward on the arduino this is an adjustment to make it 
        //drive forward enough to make the corner.
        drive();
        delay(200);
        Stop();
        delay(100);
        rotateRight();
        delay(turnDelay);
        drive();
        //this is to get it around the corner it turned towards
        delay(600);
        Stop();
        break;
//This is for when it got out of the maze it would stop
      case NO_WALL :
        Stop();
        delay(100);
        break;

      case CONT_LINE:
      //This is so it drives forward, stops pulses, and decides what to do next
        drive();
        delay(55);
        Stop();
        break;
    }
  }
  //This is to pause it and gives time to understand what the arduino was thinking
  delay(50);
}
