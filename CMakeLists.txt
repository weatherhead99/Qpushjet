project(Qpushjet)
cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Svg DBus Network)

qt5_wrap_ui(ui_settings.h settings.ui)
qt5_add_resources(resources resources.qrc)

add_executable(qpushjet main.cpp qpushjet.cpp model.cpp client.cpp device.cpp notifications.cpp api.cpp ui_settings.h ${resources})
target_link_libraries(qpushjet Qt5::Widgets Qt5::Svg Qt5::DBus Qt5::Network)
target_include_directories(qpushjet PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
