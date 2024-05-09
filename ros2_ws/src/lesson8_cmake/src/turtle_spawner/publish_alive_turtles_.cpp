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

#include "lesson8_cmake/turtle_spawner.hpp"

void TurtleSpawner::publish_alive_turtles_(){
    auto msg = lesson_interfaces::msg::TurtleArray();
    msg.turtle_array = alive_turtles_.turtle_array;
    alive_turtles_publisher_->publish(msg);
}