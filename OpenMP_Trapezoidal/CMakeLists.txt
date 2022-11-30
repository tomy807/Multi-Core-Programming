add_library(trapezoidal STATIC Trapezoidal.cpp)
target_include_directories(trapezoidal PUBLIC ${CMAKE_SOURCE_DIR}/Trapezoidal)
target_link_libraries(trapezoidal timer OpenMP::OpenMP_CXX)