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
#ifndef PUBLISHER__HPP_
#define PUBLISHER__HPP_

#include <chrono>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <lesson_interfaces/msg/lunch.hpp>

/**
 * @class Publisher
 * @brief publish std_msgs/String message with timer for testing
*/
class Purple{
public:
    double R = 106.0;
    double G = 90.0;
    double B = 205.0;
    double A = 1.0;
};


class Publisher: public rclcpp::Node
{
private:

    int counter_ = 0;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<lesson_interfaces::msg::Lunch>::SharedPtr publisher_ptr_;
    lesson_interfaces::msg::Lunch __lunch;
    Purple color;
    
    /**
     * @brief publish topic
    */
    void callback_wall_timer_();

public:

    /**
     * @brief constructor
    */
    Publisher(const std::string node_name="publisher_node"): Node(node_name)
    {
        
        this->__lunch.color_of_bowls.r = this->color.R;
        this->__lunch.color_of_bowls.g = this->color.G;
        this->__lunch.color_of_bowls.b = this->color.B;
        this->__lunch.color_of_bowls.a = this->color.A;
        this->__lunch.bowls_of_rice = 2;
        this->__lunch.meats = {"fish", "pork"};
        this->__lunch.vegetables = {"spinach", "tomato"};

        this->publisher_ptr_ = this->create_publisher<lesson_interfaces::msg::Lunch>("lunch", 10);
        this->timer_ = this->create_wall_timer(
            std::chrono::milliseconds(1000),
            std::bind(&Publisher::callback_wall_timer_, this)
        );
    }

};

#endif // PUBLISHER__HPP_