/****** 
 * 
 * This is a device template using the Okapi Library. With Okapi, we have MotorGroups, ControllerButtons, and additional controls to make programming easier
 * deviceDefinitions.h is the header file where you declare all your motors, sensors, controllers, etc. 
 * Header files in C++ are used to define all constants, variables, and functions throughout the program. 
 * Because we plan on defining these definitions in one source file (deviceDefinitions.cpp), 
 * and using them elsewhere, we prefix the declaration with the "extern" keyword. 
 * 
 */

/**** Do not modify - Header Guard***/
#pragma once
#include "main.h"
/**********************/

// In main.h, we've uncommented the lines using namespace okapi

// Declaring Motors - Modify the number and name as you need.
// Motor Groups in Okapi is a way of combining multiple motors under one command to move. 
// Using Okapi - We'll use a mix of motor groups and motors
extern MotorGroup leftChassis;
extern MotorGroup rightChassis;
extern MotorGroup intake; 
extern Motor tray;
extern Motor arm; 

//We need controller buttons to map bot movement to the joystick.

extern ControllerButton armUp;
extern ControllerButton armDown;
extern ControllerButton trayUp;
extern ControllerButton trayDown;
extern ControllerButton intakeIn;
extern ControllerButton intakeOut;

extern std::shared_ptr<ChassisControllerIntegrated> drive;





/****** Declaring Sensors
 * There are multiple sensor types in Okapi. All fall under either Analog or Digital. A brief list of types includes: 
 *  Potentiometer, ADIEncoder, ADIGyro
 * They are declared similarly to motors; 
 *
 */

extern Potentiometer pot;
extern ADIGyro gyro;
extern ADIEncoder enc;
extern ADIEncoder enc2;


/*** Declaring Controllers
 * A controller in PROS is declared using the Controller class. 
 */

extern Controller mainCtrl; 
extern Controller secondCtrl; 

/*** Other variables ** 
 * You can also declare additional variables in a header file
 */

extern int sampleVariable; 
extern bool toggle; 

/*** Functions ***
 * Functions can also be declared in header files, where you must also define the return type, name of the function,
 * and number and type of parameters. 
 */ 

extern void tank(bool partner = false); 
/*** We provide a default parameter, in this case whether or not to use the partner controller. 
 * Default parameters are called if you call a function with specifying a value ***/

/**
 * More default parameters here
 * bool partner - Indicates whether to use partner joystick
 */ 
extern void arcade(bool partner = false);
 