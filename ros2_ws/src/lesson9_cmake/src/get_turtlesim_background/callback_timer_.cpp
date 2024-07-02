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

#include "lesson9_cmake/get_turtlesim_background.hpp"

void GetTurtlesimBackground::callback_timer_() {
    
    std::vector<std::string> turtlesim_bg_name_vec;
    for(const auto& [background_color_name, value] : this->request_parameter_dict_) {
        turtlesim_bg_name_vec.push_back(background_color_name);
    }

    this->get_turtlesim_bg_threads_.push_back(std::make_shared<std::thread>(std::bind(&GetTurtlesimBackground::call_get_parameter_service_, this, turtlesim_bg_name_vec)));

}