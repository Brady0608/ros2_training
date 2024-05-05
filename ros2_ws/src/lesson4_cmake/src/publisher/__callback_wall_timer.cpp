#include "lesson4_cmake/publisher.hpp"

void Publisher::__callback_wall_timer()
{
    this->__counter += 1;
    std::ostringstream oss {};
    oss << "Publish number: " << this->__counter;
    std_msgs::msg::String msg;
    msg.data = oss.str();
    this->__publisher_ptr->publish(msg);
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "I publish message: " << msg.data
    );
};