## Summary:

This shows the documentation of low level control. Currently, it has the following features:

1. [Servo Package](#servo)
  * Sending servo position command
  
2. [Webcam Package](#webcam)
  * Streaming webcam
 
3. [Hardware-Moveit Interface](#hardware-interface)
  * Controlling servo from MoveIt's interface 





## Servo
### Sending command to servo

![microcontroller](https://github.com/nyangshawbin/ws_moveit/blob/hardware/hardware/servo/images/servo.png)

Firstly initialize connection between ROS and microcontroller:
```
roslaunch servo servo_rosserial.launch
```

Send servo position command to `/servo_position_command`. Command to be within the range of [0,1] with 0 and 1 being the min and max value respectively as configured in the [node](https://github.com/nyangshawbin/ws_moveit/blob/d7b1760fbd5dd7b9577fccc9010608f5222a2b4d/hardware/servo/arduino_servo/servo_ros/servo_ros.ino#L17), i.e,:
```
rostopic pub /servo_position_command std_msgs/Float32 "data: 0.75" 
```


## Webcam 
![streaming camera feed](https://github.com/nyangshawbin/ws_moveit/blob/hardware/hardware/usb_cam/images/webcam.png)
```
roslaunch usb_cam usb_cam.launch
```


## Hardware Interface

-in progress-
