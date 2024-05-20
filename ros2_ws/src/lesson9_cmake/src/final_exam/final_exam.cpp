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
* Maintainer: Brady Guo
*******************************************************************************/

#include "lesson9_cmake/final_exam.hpp"

FinalExam::FinalExam(std::string node_name)
    : Node(node_name) {
    
    this->rgb_upper_bound_ = 255;
    this->rgb_lower_bound_ = 0;
    this->velocity_upper_bound_ = 1.0;
    this->velocity_lower_bound_ = -1.0;
    this->velocity_ = 0.0;
    this->has_to_change_color_ = true;
    this->get_velocity_name_vec_ = {"velocity"};

    this->describe_parameters_client_ = this->create_client<rcl_interfaces::srv::DescribeParameters>("describe_parameters");
    this->velocity_get_parameter_client_ = this->create_client<rcl_interfaces::srv::GetParameters>("get_parameters");
    this->set_bg_parameters_client_ = this->create_client<rcl_interfaces::srv::SetParametersAtomically>("set_parameters_atomically");

    this->call_get_describe_parameter_service_(this->get_velocity_name_vec_);
    
    this->timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&FinalExam::callback_timer_, this));
        
}