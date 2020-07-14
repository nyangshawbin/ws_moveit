/* 
 Taking in range command (0-1) from user.
 Input scaled according to servo's safety range as defined in following Servo config.
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/JointState.h>
#include <Servo.h>

ros::NodeHandle  nh;

/* 
 *  Setting Servo config 
 */
float min_pos = 0; // safe angle range of SM-S3317B Servo:(0,150)
float max_pos = 150;
float default_pos = 75; // Default position of servo
int servo_pin = 2; //Digital pin number
Servo myservo;  // create servo object to control a servo

/* 
 *  Setting joint parameters.
 */

float joint1_min = -1.57;
float joint1_max = 1.57;
float joint1_default = 0;


std_msgs::UInt16 command_msg;
ros::Publisher servo_position_command("servo_position_command", &command_msg); 

void commandCb( const sensor_msgs::JointState& joint_state_msg){
  float joint_range = abs(joint1_min-joint1_max);
  float servo_range = abs(min_pos-max_pos);
  float scaled_joint_state = abs(joint1_min-joint_state_msg.position[0]);

  command_msg.data = default_pos;
  
  //Computing servo position command
  command_msg.data = max_pos - (scaled_joint_state * (servo_range/joint_range)); 
//  command_msg.data = (scaled_joint_state * (servo_range/joint_range)); //if direction of servo rotates in the opposite direction as ros


  //debug, echo /servo_position_command to check if command given is within servo's range
  servo_position_command.publish(&command_msg);
  
  //MOVING REAL ROBOT, ENSURE SIMULATED ROBOT IS IN 'HOME' POSITION
  myservo.write(command_msg.data);
}

ros::Subscriber<sensor_msgs::JointState> sub("/arm/joint_states", commandCb );

void setup() {
  
  //initialize your ROS node handle, advertise any topics being published, 
  // and subscribe to any topics you wish to listen to.
  nh.initNode();
  nh.advertise(servo_position_command);
  nh.subscribe(sub);
  
  myservo.attach(servo_pin);  // attaches the servo on pin 2
  myservo.write(default_pos); // initialize servo to default position
}

void loop() {
  nh.spinOnce(); //where all of the ROS communication callbacks are handled.
  delay(1);
 
}
