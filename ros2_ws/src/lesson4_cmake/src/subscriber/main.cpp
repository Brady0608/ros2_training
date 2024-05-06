#include "lesson4_cmake/subscriber.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);    
    rclcpp::Node::SharedPtr node = std::make_shared<Subscriber>("subscriber_node");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}