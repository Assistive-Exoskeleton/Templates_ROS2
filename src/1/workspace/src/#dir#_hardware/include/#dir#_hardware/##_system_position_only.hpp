// Copyright 2020 ros2_control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef #Pname#_HARDWARE__#Pname#_SYSTEM_POSITION_ONLY_HPP_
#define #Pname#_HARDWARE__#Pname#_SYSTEM_POSITION_ONLY_HPP_

#include <memory>
#include <string>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"
#include "#Pname#_hardware/visibility_control.h" //make visible outside DSO (dynamic shared object)

using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

namespace raspberry_ros2_control_test
{
  class #Pname#SystemPositionOnlyHardware : public hardware_interface::SystemInterface
  {
    public:
      RCLCPP_SHARED_PTR_DEFINITIONS(#Pname#SystemPositionOnlyHardware); //same as python shared pointers (search for C++ smart pointers)

      ROS2_CONTROL_DEMO_HARDWARE_PUBLIC   //visibility attribute, make the object interface outside the DSO
      CallbackReturn on_init(const hardware_interface::HardwareInfo & info) override;

      ROS2_CONTROL_DEMO_HARDWARE_PUBLIC
      CallbackReturn on_configure(const rclcpp_lifecycle::State & previous_state) override;

      ROS2_CONTROL_DEMO_HARDWARE_PUBLIC
      std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

      ROS2_CONTROL_DEMO_HARDWARE_PUBLIC
      std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

      ROS2_CONTROL_DEMO_HARDWARE_PUBLIC
      CallbackReturn on_activate(const rclcpp_lifecycle::State & previous_state) override;

      ROS2_CONTROL_DEMO_HARDWARE_PUBLIC
      CallbackReturn on_deactivate(const rclcpp_lifecycle::State & previous_state) override;

      ROS2_CONTROL_DEMO_HARDWARE_PUBLIC
      hardware_interface::return_type read() override;

      ROS2_CONTROL_DEMO_HARDWARE_PUBLIC
      hardware_interface::return_type write() override;

    private:
      // Parameters for the #Pname# simulation
      double hw_start_sec_;
      double hw_stop_sec_;
      double hw_slowdown_;

      // Store the command for the simulated robot
      std::vector<double> hw_commands_;
      std::vector<double> hw_states_;
  };

}  // namespace ros2_control_demo_hardware

#endif  // ROS2_CONTROL_DEMO_HARDWARE__#Pname#_SYSTEM_POSITION_ONLY_HPP_
