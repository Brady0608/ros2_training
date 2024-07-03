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
from launch_ros.actions import LifecycleNode


def generate_launch_description():
    return LaunchDescription([
        LifecycleNode(package='lesson12_cmake', executable='lifecycle_example_exe',
                      name='managed_scan_node', namespace='', output='screen')
    ])