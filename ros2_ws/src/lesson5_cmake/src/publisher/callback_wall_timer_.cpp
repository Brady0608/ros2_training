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
* Author    : Joe Lin
* Maintainer: Brady Guo
*******************************************************************************/
#include "lesson5_cmake/publisher.hpp"

void Publisher::callback_wall_timer_()
{
    
    lesson_interfaces::msg::Lunch msg;
    msg = this->__lunch;

    this->publisher_ptr_->publish(msg);
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "I publish message: " << std::to_string(msg.bowls_of_rice);
    );
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "I publish message: " << msg.color_of_bowls.a;
    );
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "I publish message: " << msg.color_of_bowls.r;
    );
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "I publish message: " << msg.color_of_bowls.b;
    );        
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "I publish message: " << msg.color_of_bowls.g;
    );
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "I publish message: " << msg.meats.data()->c_str();
    );

};