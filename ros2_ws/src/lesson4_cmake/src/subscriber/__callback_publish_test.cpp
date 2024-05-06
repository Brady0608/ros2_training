#include "lesson4_cmake/subscriber.hpp"

void Subscriber::__callback_publish_test(const std_msgs::msg::String::SharedPtr msg_ptr)
{
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "I heard: " << msg_ptr->data
    );
};