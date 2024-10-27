cmake_minimum_required(VERSION 3.16)

project(Logger)

set (CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME}
                ./log_categories.h
                ./debug_logger_component.h
                ./project_definitions.h
                ./singleton.h
                ./main.cpp)
