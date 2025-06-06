/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       shaoming                                                  */
/*    Created:      6/5/2025, 9:14:07 PM                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include <cmath>

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  Inertial.calibrate();
  while (Inertial.isCalibrating()) {
    task::sleep(100);
  }

  task::sleep(500);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  int time = 0;
  float xbaseline = Inertial.acceleration(xaxis);
  float ybaseline = Inertial.acceleration(yaxis);
  float zbaseline = Inertial.acceleration(zaxis);

  //printf("%.2f\n%.2f\n%.2f\n", Inertial.acceleration(xaxis), ybaseline, zbaseline);
  printf("time,accel\n");
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................
    if (time == 20) {
      xbaseline = Inertial.acceleration(xaxis);
      ybaseline = Inertial.acceleration(yaxis);
      zbaseline = Inertial.acceleration(zaxis);
      //printf("%.2f\n%.2f\n%.2f\n", xbaseline, ybaseline, zbaseline);
    }

    float magnitude = sqrt(pow(xbaseline-Inertial.acceleration(xaxis), 2) + pow(ybaseline-Inertial.acceleration(yaxis), 2) + pow(zbaseline-Inertial.acceleration(zaxis), 2));
    printf("%d,%.2f\n", time, magnitude);
    //printf("%.2f,%.2f,%.2f\n", xbaseline, ybaseline, zbaseline);
    //printf("%.2f,%.2f,%.2f,\n\n", xbaseline-Inertial.acceleration(xaxis), ybaseline-Inertial.acceleration(yaxis), zbaseline-Inertial.acceleration(zaxis));
    time += 20;

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  usercontrol();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
  return 0;
}
