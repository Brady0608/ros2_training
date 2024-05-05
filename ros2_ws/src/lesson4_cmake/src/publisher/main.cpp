#include "lesson4_cmake/publisher.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);    
    rclcpp::Node::SharedPtr node = std::make_shared<Publisher>("publisher_node");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}