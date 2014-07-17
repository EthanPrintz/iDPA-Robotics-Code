#pragma config(Sensor, in2,    rightLineSensor, sensorLineFollower)
#pragma config(Sensor, in3,    leftLineSensor, sensorLineFollower)
#pragma config(Sensor, in4,    light,          sensorReflection)
#pragma config(Sensor, dgtl1,  bump,           sensorTouch)
#pragma config(Sensor, dgtl9,  sleft,          sensorSONAR_inch)
#pragma config(Sensor, dgtl11, sright,         sensorSONAR_inch)
#pragma config(Motor,  port2,           mleft,         tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           kick,          tmotorVex393, openLoop)
#pragma config(Motor,  port8,           leg,           tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           mright,        tmotorVex393, openLoop, reversed)
void end(){motor[mleft]=0;motor[mright]=0;}
task terrain(){while(true){
		motor[mleft]=127;
		motor[mright]=127;
}}
task arcade(){while(true){
		motor[mleft]  = (vexRT[Ch2] + vexRT[Ch1]);
		motor[mright] = (vexRT[Ch2] - vexRT[Ch1]);
}}
task tank(){while(true){
		motor[mleft]=vexRT(Ch3);
		motor[mright]=vexRT(Ch2);
}}
task slowtank(){while(true){
		motor[mleft]=vexRT(Ch3)/4;
		motor[mright]=vexRT(Ch2)/4;
		if(SensorValue(light)<400){end();StopTask(slowtank);}
}}
task bumper{while(true){
	StopTask(terrain);StopTask(arcade);StopTask(tank);StopTask(slowtank);
	motor[mright]=-100;motor[mleft]=-100;wait1Msec(1500);motor[mright]=-50;
	motor[mleft]=100;wait1Msec(1100);end();StopTask(bumper);
}}
task goalie{while(true){
	 wait1Msec(9029);motor[mleft]=127;motor[mright]=127;wait1Msec(750);motor[mleft]=-127;motor[mright]=-127;wait1Msec(790);end();
	 wait1Msec(5276);motor[mleft]=127;motor[mright]=127;wait1Msec(750);motor[mleft]=-127;motor[mright]=-127;wait1Msec(790);end();
	 wait1Msec(2565);motor[mleft]=127;motor[mright]=127;wait1Msec(750);motor[mleft]=-127;motor[mright]=-127;wait1Msec(790);end();
	 wait1Msec(8851);motor[mleft]=127;motor[mright]=127;wait1Msec(750);motor[mleft]=-127;motor[mright]=-127;wait1Msec(790);end();
	 wait1Msec(4042);motor[mleft]=127;motor[mright]=127;wait1Msec(750);motor[mleft]=-127;motor[mright]=-127;wait1Msec(790);end();
	 wait1Msec(7615);motor[mleft]=127;motor[mright]=127;wait1Msec(750);motor[mleft]=-127;motor[mright]=-127;wait1Msec(790);end();
	 wait1Msec(3315);motor[mleft]=127;motor[mright]=127;wait1Msec(750);motor[mleft]=-127;motor[mright]=-127;wait1Msec(790);end();
	 wait1Msec(1819);motor[mleft]=127;motor[mright]=127;wait1Msec(750);motor[mleft]=-127;motor[mright]=-127;wait1Msec(790);end();
	 wait1Msec(4678);motor[mleft]=127;motor[mright]=127;wait1Msec(750);motor[mleft]=-127;motor[mright]=-127;wait1Msec(790);end();
	 wait1Msec(6278);motor[mleft]=127;motor[mright]=127;wait1Msec(750);motor[mleft]=-127;motor[mright]=-127;wait1Msec(790);end();
}}
task arcadekicker{while(true){

	motor[mleft]  = (vexRT[Ch2] + vexRT[Ch1]);
	motor[mright] = (vexRT[Ch2] - vexRT[Ch1]);
	motor[leg] = (vexRT[Ch4] + vexRT[Ch3]);
	if(vexRT[Btn6D]==1){motor[kick]=127;}
	else if(vexRT[Btn6U]==1){motor[kick]=-127;}
	else{motor[kick]=0;}
}}
task tankkicker{while(true){
	motor[mleft]=vexRT(Ch3);
	motor[mright]=vexRT(Ch2);
	if(vexRT[Btn5U]==1){motor[leg]=-127;}
	else if(vexRT[Btn5D]==1){motor[leg]=127;}
	else if(vexRT[Btn6D]==1){motor[kick]=127;}
	else if(vexRT[Btn6U]==1){motor[kick]=-127;}
	else{motor[kick]=0;motor[leg]=0;}
}}
//___________________________________________________________________________________________________
//Task Main
task main(){
	while(true){
		if(vexRT[Btn8R]==1){StopTask(terrain);StopTask(arcade);StopTask(tank);StopTask(slowtank);StopTask(bumper);StopTask(goalie);StopTask(arcadekicker);
			StopTask(tankkicker);end();}
		else if(vexRT[Btn8U]==1){StartTask(arcade);}
		else if(vexRT[Btn8D]==1){StartTask(tank);}
		else if(vexRT[Btn8L]==1){StartTask(terrain);}
		else if(vexRT[Btn7L]==1){StartTask(goalie);}
		else if(vexRT[Btn7U]==1){StartTask(arcadekicker);}
		else if(vexRT[Btn7D]==1){StartTask(tankkicker);}
		else if(SensorValue(bump)==1){StartTask(bumper);}
		else if(SensorValue(light)>400){StopTask(terrain);StopTask(arcade);StopTask(tank);StartTask(slowtank);}

	}
}
