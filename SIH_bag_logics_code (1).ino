#include<Stepper.h>
#include <Servo.h>
Servo servo1;//Length increasing servo
Servo servo2;
Servo servo3;
int x_step_pin=2;
int x_dir_pin=5;
int y_step_pin=3;
int y_dir_pin=6;
int z_step_pin=4;
int z_dir_pin=7;
int x_motor_rpm=90;
int y_motor_rpm=90;
int z_motor_rpm=90;
int Total_steps=1000;
int  x_endstop;
int  y_endstop;
int  z_endstop;
Stepper x_stepper(Total_steps,x_step_pin,x_dir_pin);
Stepper y_stepper(Total_steps,y_step_pin,y_dir_pin);
Stepper z_stepper(Total_steps,z_step_pin,z_dir_pin);

void setup() 
{
  Serial.begin(9600);
    pinMode(9,INPUT);     //x_endstop
    pinMode(10,INPUT);    //y_endstop
    pinMode(11,INPUT);    //z_endstop  
    x_stepper.setSpeed(x_motor_rpm);
    y_stepper.setSpeed(y_motor_rpm);
    z_stepper.setSpeed(z_motor_rpm);
    servo1.attach(8);     //pin num 8
    servo2.attach(12);    //pin num 12
    servo3.attach(13);    //pin num 13


}
void loop() {
  x_endstop=digitalRead(9);
  y_endstop=digitalRead(10);
  z_endstop=digitalRead(11);
  Serial.print("X-end:");
  Serial.println(x_endstop);
  Serial.print("Y-end:");
  Serial.println(y_endstop);
  Serial.print("Z-end:");
  Serial.println(z_endstop);
        while (x_endstop==1)
      {
         moveleft(4500);        
      }
         while (y_endstop==1)
      {
       movebackward(5500);
      }
          while (z_endstop==1)
      {
       movezaxisdown(5000);
       }    
  x_endstop=digitalRead(9);
  y_endstop=digitalRead(10);
  z_endstop=digitalRead(11);
        if (x_endstop==1)
      {
      Serial.println("initial x position Attained");         
      }

       if (y_endstop==1)
      {
       Serial.println("initial y position Attained");
      }

       if (z_endstop==1)
      {
       Serial.println("initial z  position Attained");    //end stopper for X-axis,Y-axis,Z-axis :)
       }   
  //----------------------------------------bag 1
    movezaxisup(4000);
//  moveforward(2000);
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
     //movezaxisdown(2000); //claw down z down
     movebackward(2000);
    servo3.write(90);
    delay(1000);
//movezaxisup(2000);//claw up z up

  //----------------------------------------bag 2
    moveforward(4000);
//movezaxisdown(2000); //claw down z down
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
    movebackward(4000);
//movezaxisup(2000);//claw up z up
    servo3.write(90);
    delay(1000);
////claw bag placement

 //----------------------------------------bag 3
    moveright(1000);
    moveforward(2000);
//movezaxisdown(2000); //claw down z down
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
////Z down claw operation bag picked
    movebackward(2000);
//movezaxisup(2000);//claw up z up
    servo3.write(90);
    delay(1000);
////claw bag placement

  //----------------------------------------bag 4
    
    moveforward(4000); 
//movezaxisdown(2000); //claw down z down
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
////Z down claw operation bag picked
    movebackward(4000);  
//movezaxisup(2000);//claw up z up
    servo3.write(90);
    delay(1000);
////claw bag placement

  //----------------------------------------bag 5
    moveright(1000);          //from initial 1000+1000=2000 steps
    moveforward(2000);
//movezaxisdown(2000); //claw down z down
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
////Z down claw operation bag picked
    movebackward(2000);
//movezaxisup(2000);//claw up z up
    servo3.write(90);
    delay(1000);
////claw bag placement

  //----------------------------------------bag 6
    
    moveforward(4000);
//movezaxisdown(2000); //claw down z down
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
////Z down claw operation bag picked
    movebackward(4000);
//movezaxisup(2000);//claw up z up
    servo3.write(90);
    delay(1000);
////claw bag placement

 //----------------------------------------bag 7
    moveright(1000);      //from initial 1000+1000+1000=3000 steps
    moveforward(2000);
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
////Z down claw operation bag picked
    movebackward(2000);
    servo3.write(90);
    delay(1000);
////claw bag placement

 //----------------------------------------bag 8

    moveforward(4000);
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);    
////Z down claw operation bag picked
    movebackward(4000);
    servo3.write(90);
    delay(1000); 
////claw bag placement
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //----------------------------------------bag 9
     movezaxisup(2000);
     moveforward(2000);
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
     //movezaxisdown(2000); //claw down z down
     movebackward(2000);
    servo3.write(90);
    delay(1000);
//movezaxisup(2000);//claw up z up

  //----------------------------------------bag 10
    moveforward(4000);
//movezaxisdown(2000); //claw down z down
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
    movebackward(4000);
//movezaxisup(2000);//claw up z up
    servo3.write(90);
    delay(1000);
////claw bag placement

 //----------------------------------------bag 11
    moveleft(1000);     //first position    1000 steps 
    moveforward(2000);
//movezaxisdown(2000); //claw down z down
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
////Z down claw operation bag picked
    movebackward(2000);
//movezaxisup(2000);//claw up z up
    servo3.write(90);
    delay(1000);
////claw bag placement

  //----------------------------------------bag 12
    
    moveforward(4000); 
//movezaxisdown(2000); //claw down z down
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
////Z down claw operation bag picked
    movebackward(4000);  
//movezaxisup(2000);//claw up z up
    servo3.write(90);
    delay(1000);
////claw bag placement

  //----------------------------------------bag 13
    moveleft(1000);          //from initial 1000+1000=2000 steps (2nd position)
    moveforward(2000);
//movezaxisdown(2000); //claw down z down
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
////Z down claw operation bag picked
    movebackward(2000);
//movezaxisup(2000);//claw up z up
    servo3.write(90);
    delay(1000);
////claw bag placement

  //----------------------------------------bag 14
    
    moveforward(4000);
//movezaxisdown(2000); //claw down z down
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
////Z down claw operation bag picked
    movebackward(4000);
//movezaxisup(2000);//claw up z up
    servo3.write(90);
    delay(1000);
////claw bag placement

 //----------------------------------------bag 15
    moveleft(1000);      //from initial 1000+1000+1000=3000 steps  3rd position
    moveforward(2000);
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);
////Z down claw operation bag picked
    movebackward(2000);
    servo3.write(90);
    delay(1000);
////claw bag placement

 //----------------------------------------bag 16

    moveforward(4000);
    servo1.write(45);
    delay(500);
    servo2.write(0);//This value change from row to row 
    delay(500);
    servo3.write(90);
    delay(1000);    
////Z down claw operation bag picked
    movebackward(4000);
    servo3.write(90);
    delay(1000); 
////claw bag placement

}
/////////////////////////////////////////////////functions
void moveforward(int w)
{
  for(int i = 0; i < w; i ++)
  {
    x_stepper.step(-1);   // motor x clockwise
    y_stepper.step(1);
  } 
// motor y counter clockwise
}

void movebackward(int x)
{
  for(int i = 0; i < x; i ++)
  {
    x_stepper.step(1);   // motor x counterclockwise
    y_stepper.step(-1);    // motor y clockwise
   }
}

void moveleft(int y)
{
  for(int i = 0; i < y; i ++)
  {
    x_stepper.step(-1);   // motor x clockwise
    y_stepper.step(-1);    // motor y clockwise
  }
}

void moveright(int z)
{
  for(int i = 0; i < z; i ++)
  {
    x_stepper.step(1);   // motor x counter clockwise
    y_stepper.step(1);    // motor y counter clockwise
   }
}

void movezaxisup(int z1)
{
  for(int i = 0; i < z1; i ++)
  {
    z_stepper.step(1);   // motor x counter clockwise
  }
}
void movezaxisdown(int z2)
{
  for(int i = 0; i < z2; i ++)
  {
    z_stepper.step(-1);   // motor x clockwise
  }
}
