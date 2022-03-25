#include "#Package_name#/#Executable_name#.hpp"
#include <pluginlib/class_list_macros.hpp>
#include <QStringList>

PLUGINLIB_EXPORT_CLASS(#Namespace#::#classname#, rqt_gui_cpp::Plugin)
/*PLUGINLIB_EXPORT_CLASS( 
  fully-qualified type of the plugin class
  fully-qualified type of the base class
)*/

namespace #Namespace# {

 
#classname#::#classname#()
  : rqt_gui_cpp::Plugin()
  , widget_(0)
{
  // Constructor is called first before initPlugin function.

  // give QObjects reasonable names
  setObjectName("#classname#");
}

void #classname#::initPlugin(qt_gui_cpp::PluginContext& context)
{
  // access standalone command line arguments
  QStringList argv = context.argv();
  // create QWidget
  widget_ = new QWidget();
  // extend the widget with all attributes and children from UI file
  ui.setupUi(widget_);
  // add widget to the user interface
  context.addWidget(widget_);

  // ROS2 related declaration
  publisher_custom_1 = node_->create_publisher<std_msgs::msg::Float64MultiArray>("/forward_position_controller/commands", 1);
  subscriber_custom_1 = node_->create_subscription<sensor_msgs::msg::JointState>("/joint_states", 1, std::bind(&#classname#::stateCallback,this,std::placeholders::_1));
  // Prepare msg
  msg_.data = {0.0};

  connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderCallback(int)));

  RCLCPP_INFO(rclcpp::get_logger("#classname#"), "Slider plugin init finished.\n");
}

void #classname#::shutdownPlugin()
{
  //unregister all publishers here
  ;
}

void #classname#::saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
{
  //save intrinsic configuration, usually using:
  // instance_settings.setValue(k, v)
  (void) (plugin_settings);
  (void) (instance_settings);
}

void #classname#::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
{
  //restore intrinsic configuration, usually using:
  // v = instance_settings.value(k)
  (void) (plugin_settings);
  (void) (instance_settings);
}

#classname#::~#classname#()
{
    if(widget_)
        delete widget_;
}

void #classname#::sliderCallback(int value)
{
    double converted = ((double)value/50)*3.14;
    msg_.data = {converted};
    //RCLCPP_INFO(rclcpp::get_logger("#classname#"), "New slider value: %f",converted);
    publisher_custom_1->publish(msg_);
}

void #classname#::stateCallback(const sensor_msgs::msg::JointState state_)
{
      int slider_value = (state_.position[0]/3.14)*50; 
      ui.horizontalSlider->setValue(slider_value);
    //RCLCPP_INFO(rclcpp::get_logger("#classname#"), "State value: %f",state_.position[0]);

}

/*bool hasConfiguration() const
{
  return true;
}

void triggerConfiguration()
{
  // Usually used to open a dialog to offer the user a set of configuration
}*/

} // namespace #Namespace#

