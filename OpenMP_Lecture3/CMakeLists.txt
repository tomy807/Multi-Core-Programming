set(list 
Dynamic_scheduling Static_scheduling Trapezodial_reduction Guided_scheduling

    )

foreach(loop IN LISTS list)
    add_executable(${loop} ${loop}.cpp)
    target_link_libraries(${loop} timer trapezoidal OpenMP::OpenMP_CXX)
endforeach()
