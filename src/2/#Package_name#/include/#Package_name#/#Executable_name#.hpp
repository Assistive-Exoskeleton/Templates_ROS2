#ifndef #classname#_H__
#define #classname#_H__

// ROS2
#include <rclcpp/rclcpp.hpp>

// msgs
#include <std_msgs/msg/bool.hpp>

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
      rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher_custom_1;
      std_msgs::msg::Bool msg_;

    protected slots:
        void pub1Callback();
  };
} // namespace #Namespace#
#endif // #classname#_H__
