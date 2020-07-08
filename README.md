## Summary:

This repo contains a work-in-progress project. Currently, it has the following few features:
1. [Demo Package](#demo) 
   * Visualize robot's joints through Rviz GUI slider.
   * Publish joint goal position to Gazebo robot directly.
   
2. [Moveit Package](#moveit)
   * Execute planned trajectory from MoveIt onto Gazebo robot.
   * Moveit Commander Scripting

3. [Move Group C++ interface](#cppinterface)
   * Using MoveGroupInterface class to carry out most operations. 


4. [Hardware Package](#hardware)
   * Documentation on low level control.
   
## Demo
### Rviz GUI
![Robot joint rviz GUI image](https://github.com/nyangshawbin/ws_moveit/blob/master/images/robot_rviz.gif)

```
roslaunch moveit_demo robot_rviz.launch
```

### Gazebo Joint Position Control
![Gazebo demo image](https://github.com/nyangshawbin/ws_moveit/blob/master/images/robot_gazebo_demo.gif)

```
roslaunch moveit_demo robot_world.launch

roslaunch moveit_demo robot_control.launch
```

#### Example: 
```
rostopic pub /robot/joint1_position_controller/command std_msgs/Float64 "data: -1.2"
```  

## MoveIt

### Execute motion planned by MoveIt 
![Execute trajectory image](https://github.com/nyangshawbin/ws_moveit/blob/master/images/moveit_motion_planning.gif)

Launch robot in gazebo with its controller loaded

```
roslaunch robot_gazebo robot_gazebo.launch
```

Launch main moveit file

```
roslaunch robot_moveit robot_planning_execution.launch
```

Change state in planning tab of Motion Planning plugin. Plan and execute to visualize change in Gazebo.

### MoveIt Commander Scripting

![Command line control image](https://github.com/nyangshawbin/ws_moveit/blob/master/images/command_line_control.gif)

To control simulated robot in gazebo using [command line](http://docs.ros.org/melodic/api/moveit_tutorials/html/doc/moveit_commander_scripting/moveit_commander_scripting_tutorial.html): 
```
rosrun moveit_commander moveit_commander_cmdline.py
```

### Cpp Interface

## Hardware
Click [here](https://github.com/nyangshawbin/ws_moveit/tree/master/hardware) for documentation on hardware interface.
