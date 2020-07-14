# Summary:

## Gazebo Robot
This repo contains a work-in-progress project which documents MoveIt motion planning on a custom 6-DOF robot simulated in Gazebo.  Currently, it has the following features:
1. [Demo Package](#demo) 
   * Visualize robot's joints through Rviz GUI slider.
   
2. [Moveit Package](#moveit)
   * Execute motion planning from MoveIt to Gazebo robot.
   * Moveit Commander Scripting.
   
3. [Move Group C++ interface](#move-group-cpp-interface)
   * Using MoveGroupInterface class to carry out most basic operations. 
   
## Demo
### Rviz GUI
![Robot joint rviz GUI image](https://github.com/nyangshawbin/ws_moveit/blob/master/robot/images/robot_rviz.gif)

```
roslaunch moveit_demo robot_rviz.launch
```

## MoveIt

### Execute motion planned by MoveIt 
![Execute trajectory image](https://github.com/nyangshawbin/ws_moveit/blob/master/robot/images/moveit_motion_planning.gif)

Launch robot in gazebo

```
roslaunch robot_gazebo robot_gazebo.launch
```

Launch main moveit file

```
roslaunch robot_moveit robot_planning_execution.launch
```

Change state in planning tab of Motion Planning plugin. Plan and execute to visualize change in Gazebo.

### MoveIt Commander Scripting

![Command line control image](https://github.com/nyangshawbin/ws_moveit/blob/master/robot/images/command_line_control.gif)

To control simulated robot in gazebo using [command line](http://docs.ros.org/melodic/api/moveit_tutorials/html/doc/moveit_commander_scripting/moveit_commander_scripting_tutorial.html): 
```
rosrun moveit_commander moveit_commander_cmdline.py
```

## Move Group Cpp Interface

Launch robot in gazebo and main Moveit file as before

```
roslaunch robot_gazebo robot_gazebo.launch

roslaunch robot_moveit robot_planning_execution.launch
```
Run the launch file, use the [RvizVisualToolsGui](http://docs.ros.org/melodic/api/moveit_tutorials/html/doc/quickstart_in_rviz/quickstart_in_rviz_tutorial.html#rviz-visual-tools) panel to step through the demo

```
roslaunch moveit_tutorials move_group_robot.launch
```
### Expected output:
Each step can be visualized in Rviz, and motion executed on Gazebo Robot.

  1. Robot moves arm to pose goal.
  2. Robot moves arm to along cartesian waypoints.
  3. Robot moves its arm to joint goal.
  4. A box object is added into the environment to the left of the arm.
  5. Robot moves its arm to the new pose goal, avoiding collision with the box.
  6. The object is attached to the robot.
  7. The object is detached from the wrist.
  8. The object is removed from the environment.
