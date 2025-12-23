cmake_minimum_required(VERSION 3.10)
project(Zodziai)

file(GLOB CPP_H_FILES "*.cpp" "*.h")
file(GLOB TXT_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.txt")

add_executable(Zodziai ${CPP_H_FILES})

# Nukopijuoja txt failus į build katalogą
file(COPY ${TXT_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

