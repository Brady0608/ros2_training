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

#include "lesson9_cmake/final_exam.hpp"

FinalExam::FinalExam(std::string node_name)
    : Node(node_name) {
      
    this->declare_parameter("change_bg_frequency", 1.0);
    this->change_bg_frequency_ = this->get_parameter("change_bg_frequency").as_double();
    
    this->describe_parameters_client_ptr_ = this->create_client<rcl_interfaces::srv::DescribeParameters>("describe_parameters");
    this->velocity_get_parameter_client_ptr_ = this->create_client<rcl_interfaces::srv::GetParameters>("get_parameters");
    this->set_bg_parameters_client_ptr_ = this->create_client<rcl_interfaces::srv::SetParametersAtomically>("set_parameters_atomically");

    this->call_get_describe_parameter_service_(this->get_velocity_name_vec_);
    
    this->timer_ptr_ = this->create_wall_timer(std::chrono::milliseconds((int)(1000/this->change_bg_frequency_)), std::bind(&FinalExam::callback_timer_, this));
        
}