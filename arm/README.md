## Summary:

This shows the documentation of low level control. This package has the same motion planning features as the [Robot package](https://github.com/nyangshawbin/ws_moveit/tree/master/robot), but with additional work on hardware interfacing. This package is set up for a simple 2-DOF arm for demo purposes. Currently, it has the following features:

1. [Demo](#demo)
  * Sending position command directly to servo to test rosserial connection. 
  * Streaming webcam
  * ~~Saving of image/video~~ (*in progress*)
 
2. [Hardware Interface](#hardware-interface)
  * Moving real world robot (servo), synced with simulated robot's trajectory 

## Demo
### Sending command to servo

![microcontroller](https://github.com/nyangshawbin/ws_moveit/blob/master/arm/hardware/servo/images/servo.png)

Following section shows how to establish the rosserial connection between pc and microcontroller. Servo should move to show connection has been successfully established.

First initialize connection between ROS and microcontroller:
```
roslaunch servo servo_rosserial.launch
```

Send servo position command to `/servo_position_command`. Command to be within the range of [0,1] with 0 and 1 being the min and max value respectively as configured in the [node](https://github.com/nyangshawbin/ws_moveit/blob/d7b1760fbd5dd7b9577fccc9010608f5222a2b4d/hardware/servo/arduino_servo/servo_ros/servo_ros.ino#L17), i.e,:
```
rostopic pub /servo_position_command std_msgs/Float32 "data: 0.75" 
```


### Streaming webcam

![streaming camera feed](https://github.com/nyangshawbin/ws_moveit/blob/master/arm/hardware/usb_cam/images/webcam.png)
```
roslaunch usb_cam usb_cam.launch
```


## Hardware Interface

First launch arm in Gazebo and main MoveIt file

```
roslaunch arm_gazebo arm_gazebo.launch

roslaunch arm_moveit arm_planning_execution.launch
```

With the Gazebo simulation and Rviz running, execute each of the following commands in a new terminal:


* `roslaunch servo servo_rosserial.launch` (Establish rosserial connection)
* `rostopic echo /servo_position_feedback` (Since servo has no encoder and it's open-looped, 'feedback' is hardcoded and copied from the servo position command it received. However, this assumed robot moves perfectly as commanded.)

![servo_moveit_interface](https://github.com/nyangshawbin/ws_moveit/blob/master/arm/hardware/servo/images/servo_hardware_interface.gif)

When new goal state is set and executed in the planning tab of the motion planning plugin in Rviz, Servo (*bottom of monitor*) moves accordingly in-sync with the Gazebo simulated robot. The servo subscribes to /arm/joint_states published by Gazebo. Scaling of servo position is done in [rosserial node](https://github.com/nyangshawbin/ws_moveit/blob/master/arm/hardware/servo/arduino_servo/servo_moveit_interface/servo_moveit_interface.ino) to ensure that the final servo position command is within the servo's desired [min_pos, max_pos] range. 
