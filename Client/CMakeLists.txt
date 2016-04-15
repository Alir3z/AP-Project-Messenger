cmake_minimum_required(VERSION 3.3)
project(Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SOURCE_FILES main.cpp Sources/SourceFiles/Client.cpp Sources/HeaderFiles/Client.h Sources/HeaderFiles/Interface.h Sources/SourceFiles/Interface.cpp Sources/HeaderFiles/Connection.h Sources/SourceFiles/Connection.cpp Sources/HeaderFiles/LoginMenu.h Sources/SourceFiles/LoginMenu.cpp Sources/HeaderFiles/ChatWindow.h Sources/SourceFiles/ChatWindow.cpp)
add_executable(Client ${SOURCE_FILES})

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Multimedia REQUIRED)
qt5_use_modules(Client Core Widgets Gui Multimedia)
target_link_libraries(Client Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Multimedia)
