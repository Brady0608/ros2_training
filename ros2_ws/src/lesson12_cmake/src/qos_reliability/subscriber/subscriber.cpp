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

#include "lesson12_cmake/qos_reliability/subscriber.hpp"

Subscriber::Subscriber(std::string node_name)
    : Node(node_name) {
        
        auto qos_profile = rclcpp::QoS(10).reliable();
        this->subscriber_ = this->create_subscription<std_msgs::msg::String>("/qos_test", qos_profile, std::bind(&Subscriber::callback_subscriber_, this, std::placeholders::_1));
        


}