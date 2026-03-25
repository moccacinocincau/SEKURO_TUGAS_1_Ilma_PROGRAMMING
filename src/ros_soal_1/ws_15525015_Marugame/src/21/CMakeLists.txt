cmake_minimum_required(VERSION 3.8)
project(21)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(Talker src/publisher.cpp)
ament_target_dependencies(Talker rclcpp std_msgs)

add_executable(Listener src/subscriber.cpp)
ament_target_dependencies(Listener rclcpp std_msgs)

install(TARGETS
  Talker
  Listener
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
