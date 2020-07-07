# ws_moveit
Motion Planning Documentation

## Summary:

This repo contains a work-in-progress project. Currently, it has the following few features:
1. [Demo Package](#demo) 
   * Visualize robot's joint through Rviz GUI slider.
   * Publish position goal to each joint through rostopic.
   
2. [Moveit Package](#moveit)
   * Execute MoveIt planned trajectory on simulated robot in Gazebo.
   * Moveit Commander Scripting

3. [Hardware Package](#hardware)
   * Documentation of low level hardware control
   
## Demo
### Rviz GUI
![Rviz image](https://github.com/nyangshawbin/moveit_ws/blob/master/image/rviz.gif)

```
roslaunch moveit_demo robot_rviz.launch
```

### Gazebo Joint Position Control
![Gazebo image](https://github.com/nyangshawbin/moveit_ws/blob/master/image/gazebo.gif)

```
roslaunch moveit_demo robot_world.launch

roslaunch moveit_demo robot_control.launch
```

#### Example: 
```
rostopic pub /robot/joint1_position_controller/command std_msgs/Float64 "data: -1.2"
```  

## MoveIt

### Execute motion planned by MoveIt (Rviz) 
![Execute MoveIt trajectory](https://github.com/nyangshawbin/moveit_ws/blob/master/image/execute_moveit.gif)

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

![MoveIt Commander](https://github.com/nyangshawbin/moveit_ws/blob/master/image/moveit_commander.gif)

To control simulated robot in gazebo using [command line](http://docs.ros.org/melodic/api/moveit_tutorials/html/doc/moveit_commander_scripting/moveit_commander_scripting_tutorial.html): 
```
rosrun moveit_commander moveit_commander_cmdline.py
```

### Camera Plugin
![Camera Image](https://github.com/nyangshawbin/moveit_ws/blob/master/image/camera.gif)

## Hardware

