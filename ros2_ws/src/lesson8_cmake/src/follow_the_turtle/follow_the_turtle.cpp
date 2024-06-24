/*******************************************************************************
* Copyright 2024 BROGENT TECHNOLOGIES INC.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
* Author    : Brady Guo 
* Maintainer: Brady Guo (brady_guo@brogent.com)
*******************************************************************************/

#include "lesson8_cmake/follow_the_turtle.hpp"

FollowTheTurtle::FollowTheTurtle(std::string node_name)
        : Node(node_name) {
  
    this->turtle2_spawn_client_ptr_ = this->create_client<turtlesim::srv::Spawn>("spawn");
    this->turtle1_pose_subscriber_ptr_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, std::bind(&FollowTheTurtle::callback_turtle1_pose_, this, std::placeholders::_1));
    this->turtle2_pose_subscriber_ptr = this->create_subscription<turtlesim::msg::Pose>(turtle2_name_ + "/pose", 10, std::bind(&FollowTheTurtle::callback_turtle2_pose_, this, std::placeholders::_1));
    this->turtle2_cmd_vel_publisher_ptr_ = this->create_publisher<geometry_msgs::msg::Twist>("/"+turtle2_name_+"/cmd_vel", 10);
    this->control_loop_ptr_ = this->create_wall_timer(std::chrono::milliseconds(10),std::bind(&FollowTheTurtle::callback_control_loop_, this));
    this->call_turtlesim_spawn_service_();

}