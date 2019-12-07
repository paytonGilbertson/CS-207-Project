# CS-207-Project [V0.9]

The project that we created is a maze solving robot that uses ultrasonic sensors and the right hand rule to find it's way out of the maze. The concept is simple it keeps a "hand" on the  right wall of the maze following the wall until it escapes.

The version is 0.9 because the robot is flawed and needs some help to solve the maze
![Image of MazeBot](https://i.paste.pics/13e393408e2848efce610b80ff6fa6bc.png)
## Repository Contents
* **/Maze_bot** - All the code for the robot is stored here
* **/LICENSE** - Contains the license information about our project
* **/README.md** - This file you are currently viewing

## Requirements and Materials
Materials:
* 2 [Elegoo HC-SR04 Ultrasonic Module Distance Sensor](https://www.amazon.ca/HC-SR04-Ultrasonic-Distance-Arduino-MEGA2560/dp/B01COSN7O6/ref=sr_1_1_sspa?gclid=CjwKCAiAlajvBRB_EiwA4vAqiNk4YvvqUO1W8obdTxusWyVGJBnw2RUI0lSbgF4GSl8YswyILgqYthoCFPsQAvD_BwE&hvadid=208458042154&hvdev=c&hvlocphy=1002787&hvnetw=g&hvpos=1t1&hvqmt=e&hvrand=11458302815760331903&hvtargid=kwd-297793696298&hydadcr=1505_9454478&keywords=ultrasonic+sensor&qid=1575688739&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyRkFaOFY0N0lLVVlEJmVuY3J5cHRlZElkPUEwMDQyODM5MkdKMEFKR1E3SVNPWiZlbmNyeXB0ZWRBZElkPUEwMzg2MDM4NTFOVU1UWVdTNjNDJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)
* 2 Elegoo mounting brackets
* 1 [L298 Dual H-Bridge DC Motor Controller](https://www.robotshop.com/jp/en/l298-dual-h-bridge-dc-motor-controller.html?gclid=CjwKCAiAlajvBRB_EiwA4vAqiEaBQ2N2FE2s5LCr-lTssxaZbM05ozGSAUqC4Fg_S5OuXcYWIMhs8hoCRToQAvD_BwE)
* 2 Wheels
* 1 560k ohm resistor
* 1 Arduino Uno
* 2 Battery packs
* 1 Button
* 4 wood screws
* 12 input wires
* 26 output wires
* 4 brass stud M4X25
* Piece of Cardboard
* 8 M4X8 screw
* 2 Motors
* 1 mini auxiliary wheel
* 1 [Mbot Chassis](https://www.amazon.ca/Makeblock-Mechanical-Entry-Level-Programming-Creativity/dp/B00SK5RUQY/ref=sr_1_6?gclid=CjwKCAiAlajvBRB_EiwA4vAqiG_3BdHOIXsRahkQcEkppg5NxvlsZCh2P2pQYW0SRId266OOS7JLOBoCG9gQAvD_BwE&hvadid=232368238442&hvdev=c&hvlocphy=1002787&hvnetw=g&hvpos=1t1&hvqmt=e&hvrand=8993089864407756266&hvtargid=kwd-323372753946&hydadcr=8382_10274144&keywords=mbot+kit&qid=1575693170&sr=8-6) 
* 2 self tapping screws
* 4 M3 nut
* 4 M3X25 screw
* 2 Velcro pieces
## Build Instructions
The first step is assembling the chassis for the robot. The instructions to do so come with the Mbot kit. The chassis contains holes allowing you to screw in the parts like the  motors and brass beams. Then you can attach a piece of cardboard to the top by screwing it on to the 4 brass pillars
After the motors and cardboard are attached to the chassis; connect the wires from the motors to the L298 Motor controller. This is done by taking the power and ground for both motors to the input slots on the sides (Left motor power and ground to left input on the controller and right motor power and ground to right input on the controller) Then you can connect a battery pack to the 5v and ground of the controller
To test the controller is running properly you can take a wire from slot 3(on the controller NOT THE ARDUINO) and connect it to the right motor power or the left motor power. If that works, you are clear to connect the controller to the 10,11,12 and 13 pins on the arduino
Afterwards, attach the ultrasonic sensor brackets to the front and right side of the chassis(The mounting brackets come with the sensors) using screws. Wire the 5v and ground on the sensors to the 5v and ground on your breadboard. The trig pins from the front sensor goes to pin 8 and the trig pin for the right sensor goes to pin 2. The front echo pin goes to pin 9 and the right echo pin goes to 3.
Once this is finished you can start connecting the push button where it connects to a resistor(560 ohms) which is then connected to 5v rail the other side should then be connect to your digital pin 7. On the opposite side it will be connected to the ground rail.

Lastly, you need to connect another battery pack so you can run your Arduino with out plugging it in to a computer. There should be a plug-in on your Arduino where the battery pack can be connected to. As for placing, we placed ours at the front of the robot being held by a piece of wood screwed in from both sides by wood screws(this being below the cardboard and being screwed in through the circles on both sides at the front of the robots chassis) then placing it on top of the wood and holding it down with either Velcro or double sided tape.
![Schematic view of build](https://i.paste.pics/744a374b79d33c62b994b6f75df019f7.png)
(Note: The software we used to create the schematic view did not contain the same Dual H bridge shield we used)

## Usage
To use the robot after uploading the code you:
1. Set it at the begining of the maze
2. Press the button
3. Watch it solve the maze!
4. Help it when it gets stuck (Because it will get stuck)
## Team
The team consist of :
* Payton Gilbertson -- Documented and recorded our progress
* Hunter Ruel -- Coded the software for the project
* Anakin Shields -- Provided maze materials and assembled the hardware portion of the robot
