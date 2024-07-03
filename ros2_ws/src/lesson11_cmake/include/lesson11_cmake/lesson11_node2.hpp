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
* Maintainer: Brady Guo (brady_guo@brogent.com)
*******************************************************************************/
#ifndef LESSON11_NODE2__HPP_
#define LESSON11_NODE2__HPP_


#include <rclcpp/rclcpp.hpp>

using namespace std::chrono;

class Lesson11Node2: public rclcpp::Node {

 public:
    Lesson11Node2(std::string node_name="lesson11_node2_node"): Node(node_name) {
    this->callback_group_4_reentrant_ptr_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    this->callback_group_5_mutually_exclusive_ptr_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);


    this->timer_4_ptr_ = this->create_wall_timer(seconds(1), 
                                             std::bind(&Lesson11Node2::callback_timer_4_, this), 
                                             this->callback_group_4_reentrant_ptr_);       
    this->timer_5_ptr_ = this->create_wall_timer(seconds(1), 
                                             std::bind(&Lesson11Node2::callback_timer_5_, this), 
                                             this->callback_group_5_mutually_exclusive_ptr_);

    }


 private:
   void callback_timer_4_() {

    RCLCPP_INFO(this->get_logger(), "Timer4 call counts: %d", ++this->count_4_);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    RCLCPP_INFO(this->get_logger(), "Callback from Timer 4.");
   
   }
   void callback_timer_5_() {

    RCLCPP_INFO(this->get_logger(), "Timer5 call counts: %d", ++this->count_5_);
    
    std::this_thread::sleep_for(std::chrono::seconds(3));
    RCLCPP_INFO(this->get_logger(), "Callback from Timer 5.");
   
   }
   

   rclcpp::CallbackGroup::SharedPtr callback_group_4_reentrant_ptr_;
   rclcpp::CallbackGroup::SharedPtr callback_group_5_mutually_exclusive_ptr_;

   rclcpp::TimerBase::SharedPtr timer_4_ptr_;
   rclcpp::TimerBase::SharedPtr timer_5_ptr_;

   int count_4_ {0};
   int count_5_ {0};

};


#endif
