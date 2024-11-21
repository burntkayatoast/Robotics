/* 
program description: 
	using up,down,left and right buttons; user selects the following start locations
		up for starting point [1,1]
		down for starting point [5,5]
		left for starting point [6,6]
		right for starting point [1,6]
	after choosing the start location, the program will then run until the target location of [5,5] is reached
Author: Renée Low
*/

#define leftMotor 1
#define rightMotor 2

//function signature
int goX(int, int, int);
int goY(int, int, int);
void turn90(int);

task main(){
	int locX = 5;
	int locY = 5;
	// starting location
	int curX = 0;
	int curY = 0;
	
	SensorType[S3] = sensorEV3_Color;
	SensorType[S2] = sensorEV3_Gyro;
	
	// selects the current starting location, then runs to 5,5
	while(getButtonPress(buttonEnter) == 0) {
		displayTextLine(2,"up (1,1), down (5,5)");
		displayTextLine(4,"left (6,6), right (1,6)");
		displayTextLine(6,"target location (%d,%d)", locX, locY);
		displayTextLine(8,"starting location (%d,%d)", curX, curY);
		
		// menu for which location the user wants to reach
		if(getButtonPress(buttonUp)){
			curX = 1;
			curY = 1;
		} 
		else if (getButtonPress(buttonDown)){
			curX = 5;
			curY = 5;
		}
		else if (getButtonPress(buttonLeft)){
			curX = 6;
			curY = 6;
		}
		else if (getButtonPress(buttonRight)){
			curX = 1;
			curY = 6;
		}
	}
	
	// once user confirms target location, functions to move is called
	if(getButtonPress(buttonEnter) == 1) {
		curX = goX(locX, curX, curY);
		curY = goY(locY, curY, curX);
	}
}

// function that moves robot to x location
int goX(int locX, int curX, int curY) {
	int line; 
	
	// if current x location is less than target
	if(curX < locX){
		// keeps moving until the current x location is the same as target
		while(curX <= locX){
			displayTextLine(10,"current location (%d,%d)", curX, curY);
			
			// counts the lines it passes so it knows how many boxes the robot moved
			if(SensorValue[S3] > 25){
				line = 0;
			}
			else {
				if(line == 0){
					curX++; 
				}
				
				line = 1; 				
			}
			setMotorSync(leftMotor,rightMotor, 0,100);
		}
		curX--;
	}
	
	// if current X is more than the target location,it will turn left then drive to desired position 
	if (curX > locX){
		turn90(1);
		while(curX >= locX){
			displayTextLine(10,"current location (%d,%d)", curX, curY);
			
			if(SensorValue[S3] > 25){
				line = 0;
			}
			else {
				if(line == 0){
					curX--;
				}
				line = 1;				
			}
			setMotorSync(leftMotor,rightMotor, 0,100);
		}
		curX++;
	}
	
	return curX;
}

// function that moves the robot to y location. Essentially the same thing as goX, with minor changes.
int goY(int locY, int curY, int curX){
	int line; 
	
	// if current Y location is more than the target, it will go left
	if (curY > locY){
		turn90(1);
		
		while(curY >= locY) {
			displayTextLine(10,"current location (%d,%d)", curX, curY);
			
			if(SensorValue[S3] > 25){
				line = 0;
			}
			else {
				if(line == 0) {
					curY--;
				}
				line = 1;
			}
			setMotorSync(leftMotor, rightMotor, 0,100);	
		}
	}
	
	// if current Y location is less than target, it will go right
	else if(curY < locY) {
		turn90(2);
		
		while (curY <= locY) {
			displayTextLine(10,"current location (%d,%d)", curX, curY);
			
			if (SensorValue[S3] > 25) {
				line = 0;
			}
			else {
				if (line == 0) {
					curY++;
				}
				line = 1;
			}
			
			setMotorSync(leftMotor, rightMotor, 0, 100);
		}
		return curY;
	}
}

// this function tells the robot which direction to turn to meet Y target
void turn90(int direction){
	
	resetGyro(S2);
	
	// turns left
	if (direction == 1){
		while(SensorValue[S2] < 82) {
			setMotorSync(leftMotor, rightMotor, 100,100);
		}
	}
	// turns right
	else if (direction == 2){
		while(SensorValue[S2] > -83) {
			setMotorSync(leftMotor, rightMotor, -100,100);
		}
	}
}
