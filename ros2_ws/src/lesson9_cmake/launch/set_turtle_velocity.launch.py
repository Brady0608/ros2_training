#!/usr/bin/env python3
##########################################################################
# Copyright 2024 BROGENT TECHNOLOGIES INC.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Authors:   Brady Guo 
# Maintance: Brady Guo (brady_guo@brogent.com)
##########################################################################

from launch import LaunchDescription
from launch_ros.actions import Node

THIS_PACKAGE = "lesson9_cmake"


def generate_launch_description() -> LaunchDescription:

    turtlesim_node_name = "turtlesim"
    turtlesim_instance = Node(
        package="turtlesim",
        name=turtlesim_node_name,
        executable="turtlesim_node",
        output="screen"
    )

    remap_topic = [("cmd_vel", "/turtle1/cmd_vel")]
    turtle_draw_circle_node_name = "turtle_draw_circle_with_parameter_node"
    turtle_draw_circle_with_parameter_instance = Node(
        package=THIS_PACKAGE,
        name=turtle_draw_circle_node_name,
        executable="turtle_draw_circle_with_parameter_exe",
        output="screen",
        remappings=remap_topic
    )

    remap_topic_service = [
        ("describe_parameters", f"/{turtle_draw_circle_node_name}/describe_parameters"),
        ("set_parameters_atomically", f"/{turtle_draw_circle_node_name}/set_parameters_atomically")
    ]
    set_turtle_velocity_instance = Node(
        package=THIS_PACKAGE,
        name="set_turtle_velocity_node",
        executable="set_turtle_velocity_exe",
        output="screen",
        remappings=remap_topic_service,
    )

    rqt_reconfigure_node = Node(
        package="rqt_reconfigure",
        name="rqt_reconfigure",
        executable="rqt_reconfigure",
        output="screen"
    )

    launch_description = LaunchDescription()
    action_list = [
        turtlesim_instance, turtle_draw_circle_with_parameter_instance,
        set_turtle_velocity_instance, rqt_reconfigure_node
    ]
    for action in action_list:
        launch_description.add_action(action)

    return launch_description