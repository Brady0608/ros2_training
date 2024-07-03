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
#ifndef SET_TURTLE_VELOCITY__HPP_
#define SET_TURTLE_VELOCITY__HPP_

#include <cmath>
#include <map>
#include <vector>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <rcl_interfaces/msg/floating_point_range.hpp>
#include <rcl_interfaces/msg/parameter.hpp>
#include <rcl_interfaces/msg/parameter_descriptor.hpp>
#include <rcl_interfaces/msg/parameter_type.hpp>
#include <rcl_interfaces/srv/describe_parameters.hpp>
#include <rcl_interfaces/srv/set_parameters_atomically.hpp>


class SetTurtleVelocity: public rclcpp::Node {
 public:
   SetTurtleVelocity(std::string node_name="set_turtle_velocity_node");


 private:
  
   void callback_timer_();
   void call_describe_parameter_service_(std::vector<std::string> names_vector);
   void call_set_parameter_atomically_service_(rcl_interfaces::msg::Parameter parameter);
   void set_velocity_bound_(std::map<std::string, int> names_dict);

   rclcpp::CallbackGroup::SharedPtr                                        callback_group_set_parameter_atomically_service_ptr_;
   rclcpp::Client<rcl_interfaces::srv::DescribeParameters>::SharedPtr      get_describe_parameters_client_ptr_;
   rclcpp::Client<rcl_interfaces::srv::SetParametersAtomically>::SharedPtr set_turtle_velocity_client_ptr_;
   rclcpp::TimerBase::SharedPtr                                            timer_ptr_;

   double control_frequency_ {20.0};
   double acceleration_ {0.001};
   double velocity_ {0.0};
   double velocity_lower_bound_ {-1.0};
   double velocity_upper_bound_ {1.0};

   std::map<std::string, int> request_parameter_dict_ {{"velocity",0}};

};


#endif
