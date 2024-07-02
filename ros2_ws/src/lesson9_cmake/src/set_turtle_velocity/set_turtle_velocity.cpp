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

#include "lesson9_cmake/set_turtle_velocity.hpp"

SetTurtleVelocity::SetTurtleVelocity(std::string node_name)
    : Node(node_name) {

        this->set_velocity_bound_(this->request_parameter_dict_);

        this->get_describe_parameters_client_ptr_ = this->create_client<rcl_interfaces::srv::DescribeParameters>("describe_parameters");
        this->set_turtle_velocity_client_ptr_ = this->create_client<rcl_interfaces::srv::SetParametersAtomically>("set_parameters_atomically");
        this->timer_ptr_ = this->create_wall_timer(std::chrono::milliseconds((int)(1000 / this->control_frequency_)), std::bind(&SetTurtleVelocity::callback_timer_, this));




}