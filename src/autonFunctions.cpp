#include "deviceDefinitions.h"
#include "autonFunctions.h"
//Declaring lift controller

/**
 * void moveRobot
 * @params:
 * double distance - Distsnce the robot travels
 * double speed - Speed the robot travels
 * Moves the robot a specified distance  at a certain max speed.
 */
void moveRobot(double distance, double speed){
    drive->setMaxVelocity(speed);
    drive->moveDistance(distance);
}
/**
 * void turnRobot
 * @params:
 * QAngle angle - Distance the robot turns
 * double speed - Speed the robot travels
 * Moves the robot a specified distance  at a certain max speed.
 */
void turnRobot(QAngle angle, double speed){
    drive->setMaxVelocity(speed);
    drive->turnAngle(angle);
}

/**
 * void moveTray
 * @params:
 * double distance - Distance to move tray
 * double speed - Maximum speed to move tray
 * Moves the tray at a specified speed and distance. 
 */
void moveTray(double distance, double speed) {
    tray.tarePosition();
    tray.moveRelative(distance, speed);
}

/**
 * void toggleIntake
 * @params:
 * double speed - Maximum speed to move intakes
 * Moves the intakes indefinitely at a specified speed 
 */
void toggleIntake(double speed) {
    intake.moveVelocity(speed);
}

/**
 * void moveArm
 * @params: 
 * double distance - Distance to move arm
 * double speed - Speed arm moves at
 * Moves the arm at a specified distance and speed
 */
void moveArm(double distance, double speed) {
    arm.tarePosition();
    arm.moveRelative(distance, speed);
}

/**
 * void moveArmTrayAsync
 * @params:
 * double armDistance
 * double trayDistance
 * double traySpeed
 * Moves the arm and tray together at specified distances and speeds. Will not stop until one of the functions stops.
 */
void moveArmTrayAsync(double armDistance, double armSpeed, double trayDistance, double traySpeed) {
    auto liftCtrl = AsyncControllerFactory::posIntegrated(arm, armSpeed);
    liftCtrl.tarePosition();
    tray.tarePosition();
    tray.moveRelative(trayDistance, traySpeed);
    liftCtrl.setTarget(armDistance);
    liftCtrl.waitUntilSettled(); // Nothing will move until the lift is done moving.
} 
