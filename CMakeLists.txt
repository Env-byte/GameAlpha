cmake_minimum_required(VERSION 3.22)
project(GameAlpha)
set(CMAKE_CXX_STANDARD 23)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}")
include(conanbuildinfo)
SET(CONAN_DISABLE_CHECK_COMPILER true)

conan_basic_setup()
find_package(mariadb-connector-c REQUIRED)
find_package(jsoncpp)
find_package(Boost)

file(GLOB_RECURSE TestProject_SRC "src/*.h" "src/*.cpp")
include_directories("src/public")
add_executable(${PROJECT_NAME} ${TestProject_SRC})

target_link_libraries(${PROJECT_NAME} mariadb-connector-c::mariadb-connector-c)
target_link_libraries(${PROJECT_NAME} jsoncpp::jsoncpp)
target_link_libraries(${PROJECT_NAME} Boost::Boost)
# Use the global target
