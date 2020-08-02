## Summary:

This shows the documentation of low level control. This package has the same motion planning features as the [Robot package](https://github.com/nyangshawbin/ws_moveit/tree/master/robot), but with additional work on hardware interfacing. This package is set up for a simple 2-DOF arm for demo purposes. Currently, it has the following features:

1. [Demo](#demo)
  * Sending position command directly to servo to test rosserial connection. 
  * Streaming webcam
  * Saving of image/video (*in progress*)
 
2. [Hardware Interface](#hardware-interface)
  * (*in progress*)

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

(*in progress*)
