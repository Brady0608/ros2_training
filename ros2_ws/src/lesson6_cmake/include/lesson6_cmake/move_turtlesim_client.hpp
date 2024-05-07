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
* Reference : https://google.github.io/styleguide/cppguide.html#Class_Format
*******************************************************************************/
#ifndef MOVE_TURTLESIM_CLIENT__HPP_
#define MOVE_TURTLESIM_CLIENT__HPP_

#include <chrono>
#include <rclcpp/rclcpp.hpp>
#include <lesson_interfaces/srv/move_turtlesim.hpp>
#include "turtlesim_path.hpp"

class MoveTurtlesimClient: public rclcpp::Node{
 public:
  MoveTurtlesimClient(
    std::string node_name="move_turtlesim_client_node",
    std::string path="line")
      : Node(node_name) {

    RCLCPP_INFO_STREAM(this->get_logger(), "Initializing...");
    this->client_ = this->create_client<lesson_interfaces::srv::MoveTurtlesim>(this->service_name_);
    RCLCPP_INFO_STREAM(this->get_logger(), "Initialized!!");
    
    while (!this->client_->wait_for_service(std::chrono::duration<double>(1.0))) {
      if (!rclcpp::ok()) {
        RCLCPP_ERROR_STREAM(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
        return;
      }
      RCLCPP_INFO_STREAM(
        this->get_logger(), 
        "Service '" << this->service_name_ << "' not available, waiting again.."
      );
    } 

    RCLCPP_INFO_STREAM(this->get_logger(), "Calling service '" this->service_name_ << "'!!");
    lesson_interfaces::srv::MoveTurtlesim::Request::SharedPtr request{ 
        std::make_shared<lesson_interfaces::srv::MoveTurtlesim::Request>()};
    request->path = path;

    rclcpp::Client<lesson_interfaces::srv::MoveTurtlesim>::FutureAndRequestId future{
        this->client_->async_send_request(request)};

    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) == rclcpp::FutureReturnCode::SUCCESS)
        RCLCPP_INFO_STREAM(this->get_logger(), "Successfull to call serive '" << this->service_name_ << "'");
    else
        RCLCPP_ERROR_STREAM(this->get_logger(), "Failed to call service '" << this->service_name_ << "'");

  }

 private:
   rclcpp::Client<lesson_interfaces::srv::MoveTurtlesim>::SharedPtr client_;      
   std::string service_name_ {"move_turtlesim"};
};


#endif // MOVE_TURTLESIM_SERVER__HPP_