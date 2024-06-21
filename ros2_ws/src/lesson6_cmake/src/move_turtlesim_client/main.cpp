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
*******************************************************************************/

#include "lesson6_cmake/move_turtlesim_client.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);    
    std::shared_ptr<MoveTurtlesimClient> node = std::make_shared<MoveTurtlesimClient>("move_turtlesim_client_node");
    rclcpp::shutdown();
    return 0;
}