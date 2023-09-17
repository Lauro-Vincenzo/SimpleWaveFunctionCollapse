cmake_minimum_required(VERSION 3.5)

project(WFCTests LANGUAGES CXX)

enable_testing()
include_directories(../../)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(WFCTests tst_wfctests.cpp)
add_test(NAME WFCTests COMMAND WFCTests)

target_link_libraries(WFCTests PRIVATE Qt${QT_VERSION_MAJOR}::Test)

