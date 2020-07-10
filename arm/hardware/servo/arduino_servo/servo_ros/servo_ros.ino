/* 
 Taking in range command (0-1) from user.
 Input scaled according to servo's safety range as defined in following Servo config.
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>
#include <Servo.h>

ros::NodeHandle  nh;

/* 
 *  Setting Servo config 
 */
int min_pos = 0; // safe angle range of SM-S3317B Servo:(0,150)
int max_pos = 150;
int pos = 90; // Default position of servo
int servo_pin = 2; //Digital pin number
int cmd = 0;
Servo myservo;  // create servo object to control a servo


std_msgs::UInt16 fb_msg;
ros::Publisher servo_position_fb("servo_position_fb", &fb_msg); 

void commandCb( const std_msgs::Float32& cmd_msg){
  
  if (cmd_msg.data >= 0 && cmd_msg.data <= 1){ // Getting input (0-1) from user
    cmd = (cmd_msg.data)* (max_pos - min_pos); // scale it to use it with the servo (value between min and max)
    myservo.write(cmd); 

//    //Debug
//    fb_msg.data = cmd;
//    servo_position_fb.publish(&fb_msg);
  }
   
}

ros::Subscriber<std_msgs::Float32> sub("/servo_position_command", commandCb );

void setup() {
  nh.initNode();
  nh.advertise(servo_position_fb);
  nh.subscribe(sub);
  myservo.attach(servo_pin);  // attaches the servo on pin 2
  myservo.write(pos); // move servo to default position upon starting
}

void loop() {
  nh.spinOnce();
  delay(1);
  
}
