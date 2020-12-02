cmake_minimum_required(VERSION 3.10)

# project name
project(websockt)

# cpp standard
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "-Wall -lstdc++fs -std=c++17")

include_directories(${PROJECT_SOURCE_DIR}/src/boost)
include_directories(${PROJECT_SOURCE_DIR}/src/inc)
include_directories(${PROJECT_SOURCE_DIR}/src/inc/toml)
include_directories(${PROJECT_SOURCE_DIR}/src/websocket)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/inc/toml)

configure_file(${PROJECT_SOURCE_DIR}/src/websocket/config/websocket_server.toml 
                config/websocket_server.toml)


# generate the executable
add_executable(${PROJECT_NAME}  ${PROJECT_SOURCE_DIR}/src/websocket/websocket_handler.cc
                                ${PROJECT_SOURCE_DIR}/src/websocket/websocket_initialize.cc)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src/boost)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src/inc/toml/toml)

target_link_libraries(${PROJECT_NAME} 
                PUBLIC ${CXX_FILESYSTEM_LIBRARIES}
                cpptoml)