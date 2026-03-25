from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    return LaunchDescription([

        Node(
            package='21',
            executable='Talker',
	    name='interncheerleader',
            output='screen'
        ),
        Node(
            package='21',
            executable='Listener',
	    name='him',
            output='screen'
        )
    ])
