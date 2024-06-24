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
* Author    : Joe Lin (joe_lin@brogent.com)
* Maintainer: Brady Guo (brady_guo@brogent.com)
* Reference : https://google.github.io/styleguide/cppguide.html#Class_Format
*******************************************************************************/

#include "lesson6_cmake/move_turtlesim_server.hpp"

void MoveTurtlesimServer::move_line_() {
  
  RCLCPP_INFO_STREAM(this->get_logger(), "Moving along with a line!");

  this->twist_.linear.x = this->set_twist_.at("LINE").at("linear_x");
  this->twist_.angular.z = this->set_twist_.at("LINE").at("angular_z");
  
  for (int number = 0; number < 5; number++) {
    this->publisher_ptr_->publish(this->twist_);
    rclcpp::sleep_for(std::chrono::milliseconds(1000));
  }
  
  this->stop_();
}