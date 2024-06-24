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
* See the License for the specific language governing permissons and
* limitations under the License.
* Author    : Brady Guo
* Maintainer: Brady Guo (brady_guo@brogent.com)
* Reference : https://google.github.io/styleguide/cppguide.html#Class_Format
*******************************************************************************/

#include "lesson7_cmake/teleop_in_terminal.hpp"

void TeleopInTerminal::turn_right() {
  
  this->twist_.linear.x = this->set_twist_.at("TURN_RIGHT").at("linear_x");;
  this->twist_.angular.z = this->set_twist_.at("TURN_RIGHT").at("angular_z");
  this->cmd_vel_publisher_ptr_->publish(this->twist_);
  
}