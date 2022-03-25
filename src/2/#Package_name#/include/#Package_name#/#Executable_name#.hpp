#ifndef #classname#_H__
#define #classname#_H__

// ROS2
#include <rclcpp/rclcpp.hpp>

// msgs
#include <std_msgs/msg/float64_multi_array.hpp>
#include <sensor_msgs/msg/joint_state.hpp> 

// Rqt
#include <rqt_gui_cpp/plugin.h>

// Qt
#include <QWidget>

// Custom UI
#include "#Package_name#/ui_#Executable_name#.h"

namespace #Namespace# 
{
  class #classname# : public rqt_gui_cpp::Plugin
  {
    Q_OBJECT
    public:
      #classname#();
      virtual void initPlugin(qt_gui_cpp::PluginContext& context) override;
      virtual void shutdownPlugin() override;
      virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const override;
      virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings) override;

      virtual ~#classname#();

    private:
      Ui::#classname# ui;
      QWidget* widget_;

    protected:
      rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr publisher_custom_1;
      rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscriber_custom_1;
      std_msgs::msg::Float64MultiArray msg_;

    protected slots:
        void pub1Callback();
        void sliderCallback(int);
        void stateCallback(const sensor_msgs::msg::JointState);
  };
} // namespace #Namespace#
#endif // #classname#_H__
