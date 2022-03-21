param_dict = []
banners = []

ignores = ['__pycache__' , '.vscode']

# banners[0]
banners.append( "\n    ###################################################\n\
    ########### Welcome to ROS2 templates! ############\n\
    ###################################################\n ")

# banners[1]
banners.append( """Select package/project type:\n
    0) exit\n
    1) Ros-control full-project\n
    2) rqt-plugin package (ROS2)\n""" )

# banners[2]
banners.append("""
    #### Ros-control project ####\n\n
    This will create a complete ros-control project including robot description, hardware interface and a minimal hardware demo.\n""" )

# banners[3]
banners.append("""
    #### Ros2 rqt plugin ####\n\n
    This will create a rqt plugin package compatible with ROS2; add this package to an existing workspace and compile it. This will atomatically add the plugin to rqt.\n""" )

# ros2-control workspace (param_dict[0])
param_dict.append( {
	"Package_name"    : "project_default",
} )

# rqt plugin package (param_dict[1])
param_dict.append( {   
	"Package_name"    : "project_default",
	"Namespace" 	    : "namespace_default",
	"classname"		    : "Class_default",
	"Executable_name" : "node_default"
} )

