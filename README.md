# Templates ROS2

[![Platform](https://img.shields.io/badge/platform-ROS2-blue?style=flat-square)](https://docs.ros.org/en/foxy/index.html)
![GitHub commit activity](https://img.shields.io/github/commit-activity/w/Assistive-Exoskeleton/Templates_ROS2?style=flat-square)

A set of templates to create ros2 projects.\
Each template has a private folder; availables are:

| Template name | Description |
| --- | ----------- |
| `ros2-control` | create a ros2-control basic project |
| `ros2 rqt-plugin` | create a basic custom rqt plugin* compatible with ros2**. | 

\* please see [online doc](https://docs.ros2.org/foxy/api/rclcpp/classrclcpp_1_1Node.html) on how to create publishers/subscribers.\
\** Use Qt-Design / Qt-Creator to edit `.ui` file.  

## Usage
> :warning: This script works only with linux

execute file `main.py` to create your custom package **only using terminal** (please avoid execute into vscode);

Once done, directory is available into result folder, move it to your workspace. 
> :warning: **Remove built folder at the end of the process**: The directory result should be empty.  


## improves
* install rqt plugin locally (if not sourced, errors while opening rqt standalone)
