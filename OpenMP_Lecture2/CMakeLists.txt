set(list 
        Barrier Barrier_Step Trapezodial_Critical_Locking

    )

foreach(loop IN LISTS list)
    add_executable(${loop} ${loop}.cpp)
    target_link_libraries(${loop} timer trapezoidal OpenMP::OpenMP_CXX)
endforeach()
