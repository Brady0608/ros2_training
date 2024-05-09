cmake_minimum_required(VERSION 3.8)
project(lesson8_cmake)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(lesson_interfaces REQUIRED)
find_package(turtlesim REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# include 
include_directories(include)

# add executable
## move_turtlesim_server_exe
add_executable(turtle_spawner_exe
  src/turtle_spawner/call_spawn_service_.cpp
  src/turtle_spawner/main.cpp
  src/turtle_spawner/callback_spawn_turtle_timer_.cpp
  src/turtle_spawner/publish_alive_turtles_.cpp
)

ament_target_dependencies(turtle_spawner_exe rclcpp geometry_msgs lesson_interfaces turtlesim)


# install program
install(TARGETS
  turtle_spawner_exe
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
