cmake_minimum_required(VERSION 3.2)

project(TimerForm)
find_package(Switch REQUIRED)
add_executable(TimerForm ${SWITCH_GUI} TimerForm.cpp)
target_link_libraries(TimerForm Switch.System.Windows.Forms)
