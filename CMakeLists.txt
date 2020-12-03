cmake_minimum_required(VERSION 3.10)

# project name
project(leybold-socket)

# cpp standard
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "-Wall -lstdc++fs -std=c++17 -lpthread")

if ("$ENV{LEYBOLD_SOURCE_DIR}" STREQUAL "")
    set(ENV{LEYBOLD_SOURCE_DIR} "${PROJECT_SOURCE_DIR}" CACHE INTERNAL "Copied from environment variable")
    message("-- setting $ENV{LEYBOLD_SOURCE_DIR}")
endif()


set(Boost_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/boost)
set(Boost_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/src/boost/stage/lib)
find_package(Boost CONFIG COMPONENTS system filesystem thread)

include_directories(${PROJECT_SOURCE_DIR}/src
                    ${Boost_INCLUDE_DIR} 
                    ${PROJECT_SOURCE_DIR}/src/inc
                    ${PROJECT_SOURCE_DIR}/src/inc/toml
                    ${PROJECT_SOURCE_DIR}/src/websocket
                    )

#link_directories(${Boost_LIBRARY_DIR})



add_subdirectory(${PROJECT_SOURCE_DIR}/src/inc/toml)

configure_file(${PROJECT_SOURCE_DIR}/src/websocket/config/websocket_server.toml 
                config/websocket_server.toml)


# generate the executable
add_executable(${PROJECT_NAME}  ${PROJECT_SOURCE_DIR}/src/websocket/websocket_handler.cc
                                ${PROJECT_SOURCE_DIR}/src/websocket/websocket_initialize.cc
                                )

# header include directories
target_include_directories(${PROJECT_NAME}  PUBLIC ${PROJECT_SOURCE_DIR}/src/boost
                                            PUBLIC ${PROJECT_SOURCE_DIR}
                                            PUBLIC ${PROJECT_SOURCE_DIR}/src/inc/toml/toml)

# libraries
link_libraries(${PROJECT_NAME} 
                PUBLIC ${CXX_FILESYSTEM_LIBRARIES}
                cpptoml
                ${Boost_LIBRARY_DIR} 
                )