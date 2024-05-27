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
#ifndef PUBLISHER__HPP_
#define PUBLISHER__HPP_


#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <rclcpp/qos.hpp>



class Publisher: public rclcpp::Node{
 public:
    Publisher(std::string node_name="publisher_node");


 private:
 
   void callback_timer_();

   rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
   rclcpp::TimerBase::SharedPtr timer_;
   int msg_id_;

    


};


#endif
