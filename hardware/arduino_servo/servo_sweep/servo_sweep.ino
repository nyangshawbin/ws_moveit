/* 
 Allowing servo to sweep through its (min,max) range. 
 Track servo position from Arduino IDE serial monitor.
 */

#include <Servo.h>

Servo myservo;  // create servo object to control a servo


int pos = 0;    // variable to store the servo position
int min_pos = 0; // safe range of SM-S3317B Servo: (0,150)
int max_pos = 150;
int servo_pin = 2; //Digital pin number

void setup() {
  Serial.begin(9600);
  myservo.attach(servo_pin);  // attaches the servo on digital pin 2 to the servo object
}

void loop() {
  for (pos =0; pos <= max_pos; pos+=1){
    myservo.write(pos);
    delay(100);
    Serial.print("Current servo position: ");
    Serial.println(pos);
  };
    Serial.println("Restarting to start(min) position...");
    delay(200);
}
