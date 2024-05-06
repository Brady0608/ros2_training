#ifndef PUBLISHER__HPP_
#define PUBLISHER__HPP_

#include <chrono>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include "lesson_interfaces/msg/lunch.hpp"

/**
 * @class Publisher
 * @brief publish std_msgs/String message with timer for testing
*/
class Publisher: public rclcpp::Node
{
private:
    int __counter = 0;
    rclcpp::TimerBase::SharedPtr __timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr __publisher_ptr;

    /**
     * @brief publish topic
    */
    void __callback_wall_timer();

public:

    /**
     * @brief constructor
    */
    Publisher(const std::string node_name="publisher_node"): Node(node_name)
    {
        this->__publisher_ptr = this->create_publisher<std_msgs::msg::String>("publish_test", 10);
        this->__timer = this->create_wall_timer(
            std::chrono::milliseconds(1000),
            std::bind(&Publisher::__callback_wall_timer, this)
        );
    }

};

#endif // PUBLISHER__HPP_