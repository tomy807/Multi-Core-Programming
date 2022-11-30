find_package(OpenMP)

set(list VecSum if_caluse After_PrivateClause LoopConst_implicitBar 
        Loop_construct Private_clause Private_error ScopeOfVar_1 ScopeOfVar_2
        ScopeOfVar_3 Section_construct Shared_Priavte_Clauses Shared_clause 
        Single_construct VecSum_loopConst firstPrivate lastPrivate lastPrivate2 nowait)

foreach(loop IN LISTS list)
    add_executable(${loop} ${loop}.cpp)
    target_link_libraries(${loop} timer OpenMP::OpenMP_CXX)
endforeach()
