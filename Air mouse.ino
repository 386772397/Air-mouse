

//air_mouse_with_click
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Mouse.h>
#include <Keyboard.h>
long MyRnd;

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy, vx_prec, vy_prec;
void setup() {

  randomSeed(analogRead(0)); 
  Serial.begin(9600);
  Wire.begin();
  Mouse.begin();
  Keyboard.begin();
  pinMode(8,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
    }
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  vx = (gx+750)/200;  
  vy = -(gz)/200; 
  
  Mouse.move(vx, vy);

 

 if(digitalRead(8) == 0)
 {
        Mouse.press(MOUSE_LEFT);
 }
        else
 {
          Mouse.release(MOUSE_LEFT);
 }

 if(digitalRead(10) == 0)
 {
        Mouse.press(MOUSE_RIGHT);
 }
        else
 {
          Mouse.release(MOUSE_RIGHT);
 }



 //Serial.print("ax= ");
     //   Serial.print(ax);
 /*Serial.println("ay= ");
        Serial.print(ay);
 Serial.println("az= ");
        Serial.print(az);
 Serial.println("gx= ");
        Serial.print(gx);
 Serial.println("gy= ");
        Serial.print(gy);
 Serial.println("gz= ");
        Serial.print(gz);
  */
        

        delay(30);
 }
       
  
