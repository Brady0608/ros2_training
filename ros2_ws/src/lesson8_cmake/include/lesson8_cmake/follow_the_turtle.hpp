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
#ifndef FOLLOW_THE_TURTLE__HPP_
#define FOLLOW_THE_TURTLE__HPP_

#include <cmath>
#include <geometry_msgs/msg/twist.hpp>
#include <random>
#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>
#include <turtlesim/srv/spawn.hpp>


class FollowTheTurtle: public rclcpp::Node {
 public:
      FollowTheTurtle(std::string node_name="follow_the_turtle_node");

 private:

      /**
    * @brief asdad
    * @param turtle_pose_ptr asdasd
    * 
    * @return
 */
      void callback_turtle1_pose_(const turtlesim::msg::Pose::SharedPtr turtle1_pose_ptr) {
         this->turtle1_pose_ = *turtle1_pose_ptr.get();
         this->check_turtle1_up = true;
      }

      void callback_turtle2_pose_(const turtlesim::msg::Pose::SharedPtr turtle2_pose_ptr) {
         this->turtle2_pose_ = *turtle2_pose_ptr.get();
         this->check_turtle2_up = true;
      }
      void callback_control_loop_();
      void call_turtlesim_spawn_service_();
      
      rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr turtle1_pose_subscriber_ptr_;
      rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr turtle2_pose_subscriber_ptr;
      rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr turtle2_cmd_vel_publisher_ptr_;
      rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr turtle2_spawn_client_ptr_;
      rclcpp::TimerBase::SharedPtr control_loop_ptr_;
      
      turtlesim::msg::Pose turtle1_pose_;
      turtlesim::msg::Pose turtle2_pose_;

      double p_controller_coefficient_ {1.0};
      double turtlesim_bound_ {11.0};
      bool check_turtle1_up {false};
      bool check_turtle2_up {false};
      std::string turtle2_name_ {"turtle2"};

};


#endif
