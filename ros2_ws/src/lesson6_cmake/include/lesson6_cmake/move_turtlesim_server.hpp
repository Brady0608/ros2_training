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
* Author    : Joe Lin (joe_lin@brogent.com)
* Maintainer: Brady Guo (brady_guo@brogent.com)
* Reference : https://google.github.io/styleguide/cppguide.html#Class_Format
*******************************************************************************/
#ifndef MOVE_TURTLESIM_SERVER__HPP_
#define MOVE_TURTLESIM_SERVER__HPP_

#include <cmath>
#include <chrono>
#include <map>
#include <vector>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <lesson_interfaces/srv/move_turtlesim.hpp>
#include "turtlesim_path.h"

class MoveTurtlesimServer: public rclcpp::Node {
 public:
    MoveTurtlesimServer(std::string node_name="move_turtlesim_server_node");

 private:
   void callback_service_(
      const lesson_interfaces::srv::MoveTurtlesim::Request::SharedPtr request_ptr, 
      const lesson_interfaces::srv::MoveTurtlesim::Response::SharedPtr response_ptr);

   void move_line_();
   void move_square_();
   void move_circle_();
   void move_triangle_();
   void stop_();

   const std::map<std::string, std::map<std::string, double>> set_twist_ {
      {"LINE",                   {{"linear_x", 0.2}, {"angular_z", 0.0}}},
      {"SQUARE_FIRST_PERIOD",    {{"linear_x", 2.0}, {"angular_z", 0.0}}},
      {"SQUARE_SECOND_PERIOD",   {{"linear_x", 0.0}, {"angular_z", M_PI_2}}},
      {"CIRCLE",                 {{"linear_x", 1.0}, {"angular_z", M_PI_2}}},
      {"TRIANGLE_FIRST_PERIOD",  {{"linear_x", 0.0}, {"angular_z", -M_PI_4}}},
      {"TRIANGLE_SECOND_PERIOD", {{"linear_x", 2.0}, {"angular_z", 0.0}}},
      {"STOP",                   {{"linear_x", 0.0}, {"angular_z", 0.0}}}
   };

   geometry_msgs::msg::Twist twist_ {};
   rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_ptr_;
   rclcpp::Service<lesson_interfaces::srv::MoveTurtlesim>::SharedPtr service_ptr_;
   std::string service_name_ {"move_turtlesim"};

};


#endif // MOVE_TURTLESIM_SERVER__HPP_