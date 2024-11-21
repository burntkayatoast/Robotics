/*
program description:
	using moveRobot() and randomDirection(), the robot will:
	1. go in a square and return to its original position
	2. go forward for 2s at full power, turn 180degs and travel at half speed back to original position
author: renee low
*/

#pragma config(Motor,  motorA,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorD,           ,             tmotorEV3_Large, openLoop, encoder)

// function signatures
void moveRobot(long nMotorRatio, long time, long power);
int randomDirection();

task main() {
	int turn = randomDirection(); // generates a random direction to move in
	int i = 0;
		
	// moves in a square
	for(i = 0; i < 4; i++){
		moveRobot(0, 900, 50);
		sleep(500); // pause for .5s
		moveRobot(50, 800, turn);
	}
}

void moveRobot(long nMotorRatio, long time, long power){
	// sets the movement
	setMotorSyncTime(leftMotor, rightMotor, nMotorRatio, time, power);
	sleep(1500);
}

int randomDirection() {
	int turn = 0;
	int direction = random(1); // randomly generates 1 or 0
	
	// if 1, go right. Else go left.
	if (direction == 1){
		turn = 50; //right
	}
	else {
		turn = -50; //left
	}
	
	return turn; // returns turn value
}
