/*
program description:
	 robot does a figure of 8 look, arriving back at the same starting point, 
	 pointing in the same direction as before it started moving.
author: renee Low
*/

task main()
{
	int leftMotor = 1;
	int rightMotor = 2;
	
	// moves foward 2s
	setMotorSpeed(leftMotor,50);
	setMotorSpeed(rightMotor,50);
	sleep(1000);
	
	// spins left
	setMotorSpeed(leftMotor, 100);
	setMotorSpeed(rightMotor,0);
	sleep(1000);
	
	// forwards .5s
	setMotorSpeed(leftMotor,50);
	setMotorSpeed(rightMotor,50);
	sleep(500);
	
	// spins right
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor,100);
	sleep(900);
	
	// forwards .5s
	setMotorSpeed(leftMotor,50);
	setMotorSpeed(rightMotor,50);
	sleep(500);
	
	// spins left
	setMotorSpeed(leftMotor, 100);
	setMotorSpeed(rightMotor,0);
	sleep(1100);
	
	
}
