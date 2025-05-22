cmake_minimum_required(VERSION 3.10)
project(WebLeadTool)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/**/*.cpp")
file(GLOB HEADERS "include/**/*.h")


add_executable(weblead ${SOURCES})

target_link_libraries(weblead pqxx pq)
