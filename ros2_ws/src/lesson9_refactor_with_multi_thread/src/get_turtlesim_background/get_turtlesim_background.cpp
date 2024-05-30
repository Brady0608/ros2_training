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

#include "lesson9_refactor_with_multi_thread/get_turtlesim_background.hpp"

GetTurtlesimBackground::GetTurtlesimBackground(std::string node_name)
    : Node(node_name) {
     
    this->request_parameter_dict_ = {{TurtlesimBackgroundName::BackgroundB, 0},
                                     {TurtlesimBackgroundName::BackgroundG, 1},
                                     {TurtlesimBackgroundName::BackgroundR, 2}};
    //  this->get_background_parameter_client_ = this->customic_create_client_<rcl_interfaces::srv::GetParameters>("get_parameters");
    this->get_background_parameter_client_ = this->create_client<rcl_interfaces::srv::GetParameters>("get_parameters"); 
    this->timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&GetTurtlesimBackground::callback_timer_,this));  
     

}