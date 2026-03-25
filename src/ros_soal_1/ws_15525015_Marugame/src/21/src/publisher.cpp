#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Talker : public rclcpp::Node
{
public:
  Talker()
  : Node("interncheerleader"), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
      4s, std::bind(&Talker::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = std_msgs::msg::String();

    // Multi-line message menggunakan raw string literal
    message.data = R"(
hy sobat rekayasawan!
minal aidin
maafin aku yaa kalo misal dalam interaksi kita, dari aku ada ucapan atau respon yang bikin kamu kesel, marah, atau mungkin tersinggung:<
may all your wishes come true and your journey be filled with happiness yeah
happy eid mubarak, [ak]!
semangat terus yapp!
p.s. info next proyek dong, aku maw pamer skin:p eheheh
count: )" + std::to_string(count_++);

    RCLCPP_INFO(this->get_logger(), "%s", message.data.c_str());
    publisher_->publish(message);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Talker>());
  rclcpp::shutdown();
  return 0;
}
