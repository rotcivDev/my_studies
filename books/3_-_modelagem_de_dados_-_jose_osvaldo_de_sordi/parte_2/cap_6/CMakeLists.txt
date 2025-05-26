cmake_minimum_required(VERSION 3.10)
project(acatamento_pedidosTool)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/**/*.cpp")
file(GLOB HEADERS "include/**/*.h")


add_executable(acatamento_pedidos ${SOURCES})

target_link_libraries(acatamento_pedidos pqxx pq)
