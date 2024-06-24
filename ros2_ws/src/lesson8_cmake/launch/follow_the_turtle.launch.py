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
# Authors:   Brady Guo (brady_guo@brogent.com)
# Maintance: Brady Guo (brady_guo@brogent.com)
##########################################################################
from launch import LaunchDescription
from launch_ros.actions import Node

THIS_PACKAGE = "lesson8_cmake"


def generate_launch_description() -> LaunchDescription:

    turtlesim_node = Node(
        package="turtlesim",
        name="turtlesim",
        executable="turtlesim_node",
        output="screen"
    )

    teleop_twist_keyboard_node = Node(
        package="lesson7_cmake",
        executable="teleop_in_terminal_exe",
        output="screen",
        prefix="gnome-terminal --",
    )

    follow_the_turtle_node = Node(
        package=THIS_PACKAGE,
        name="followe_the_turtle_node",
        executable="follow_the_turtle_exe",
        output="screen"
    )


    launch_description = LaunchDescription()
    action_list = [turtlesim_node, teleop_twist_keyboard_node, follow_the_turtle_node]
    for action in action_list:
        launch_description.add_action(action)

    return launch_description