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
  publisher_custom_1 = node_->create_publisher<std_msgs::msg::Bool>("topic_name", 1);

  // Prepare msg
  msg_.data = true;

  //TODO Connect with Qt Widget 
  //connect(ui_.pushButton_1, SIGNAL(pressed()), this, SLOT(button1Callback()));
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
  ;
}

void #classname#::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
{
  //restore intrinsic configuration, usually using:
  // v = instance_settings.value(k)
  ;
}

#classname#::~#classname#()
{
    if(widget_)
        delete widget_;
}

void #classname#::pub1Callback()
{
    publisher_custom_1->publish(msg_);
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

