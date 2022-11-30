add_library(timer STATIC DS_timer.cpp)

target_include_directories(timer PUBLIC ${CMAKE_SOURCE_DIR}/DSTimer)
