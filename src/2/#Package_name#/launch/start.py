from launch import LaunchDescription
from launch_ros.actions import Node


# Note that this is on Eloquent
def generate_launch_description():
    return LaunchDescription([
        Node(
            package='#Package_name#',
            node_executable='#Executable_name#',
            node_name='#Executable_name#',
            output='screen'
        )
    ])