/********
 * deviceDefinitions.cpp - This is where all the variables and functions declared in the previous file 
 * are defined here, so that they can be used in other functions. 
 */ 

/** Defining Motors *
 * 
 * In Okapi, motors and groups are easier to declare. 
 * For groups the format is MotorGroup({motor#, motor#});
 * A motor can be defined via constructor as: 
 * Motor motorName(port, reverse, gearset);
 */ 


/*** Do not modfify, this includes file is necessary **/
#include "deviceDefinitions.h"

/****************************/

 // Using minus sign to indicate reverse the direction. 
 // Change the port numbers, gearsets, and encoder units shown to your actual port numbers on the robot. 
 MotorGroup leftChassis({-11, -1});
 MotorGroup rightChassis({-20, 10});
 Motor rightIntake(15);
 Motor leftIntake(-17);
 MotorGroup intake({rightIntake, leftIntake});
 Motor tray(10, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);
 Motor arm(2, false, AbstractMotor::gearset::red, AbstractMotor::encoderUnits::degrees);


//Mapping Controller Buttons is necessary to map physical robot movement to the joysticks
// You can change the mapping to fit your liking
ControllerButton armUp(ControllerDigital::R1);
ControllerButton armDown(ControllerDigital::R2);
ControllerButton trayUp(ControllerDigital::X);
ControllerButton trayDown(ControllerDigital::A);
ControllerButton intakeIn(ControllerDigital::L1);
ControllerButton intakeOut(ControllerDigital::L2);

 std::shared_ptr<ChassisControllerIntegrated> drive = ChassisControllerFactory::createPtr(
   leftChassis, rightChassis, 
   AbstractMotor::gearset::green
 );


/*** Declaring sensors *****
 * Sensors are declared by indicate the port they occupy, which can be a Number 1-8, or char 'A' - 'H'
 * If you're using Quadrature Encoders, the valid pairings for ports are {1,2}, {3,4}, {5,6}, {7,8}
 */

 Potentiometer pot('A');
 // We can define the gyro here, but this will begin a 1 second calibration. It's better to call this from the initialize function in main.cpp
 // ADIGyro gyro(2);
 ADIEncoder enc(3, 4); 
 // You can also reverse encoders if necessary. 
 ADIEncoder enc2('E', 'F', true);

 /*** Defining Controllers *
  * Defining controllers are simple. If you're using a secondary controller, you must indicate that it is a partner controller.
  */

 Controller mainCtrl(ControllerId::master); 
 Controller secondCtrl(ControllerId::partner);

// Defining variables 
 int sampleVariable = 1;
 bool toggle = false;

 /** Defining Functions 
  * You flesh out the function definition in cpp files
  */

//In Okapi we don't need the tank and arcade functions. 




