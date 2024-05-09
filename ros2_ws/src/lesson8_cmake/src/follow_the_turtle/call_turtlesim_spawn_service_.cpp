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

#include "lesson8_cmake/follow_the_turtle.hpp"

void FollowTheTurtle::call_turtlesim_spawn_service_(){
    auto client = this->create_client<turtlesim::srv::Spawn>("spawn");
    while (client->wait_for_service(std::chrono::seconds(1))){
        RCLCPP_WARN(this->get_logger(), "Waiting for \"/spawn\" service...");
    }

    auto request = std::make_shared<turtlesim::srv::Spawn::Request>();
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_real_distribution<float> dist_xy(0.0,this->turtlesim_bound_);
    std::uniform_real_distribution<float> dist_theta(0.0,2*M_PI);
    request->name = this->turtle2_name_;
    request->x = dist_xy(gen);
    request->y = dist_xy(gen);
    request->theta = dist_theta(gen);
    auto future = client->async_send_request(request);
    try {
        auto response = future.get();
        if (response->name != "") {
            RCLCPP_INFO(this->get_logger(), "Turtle %s spawned successfully!", response->name.c_str());
        }
    }
    catch (const std::exception &e) {
        RCLCPP_ERROR(this->get_logger(), "Service call failed.");
    }







    
}