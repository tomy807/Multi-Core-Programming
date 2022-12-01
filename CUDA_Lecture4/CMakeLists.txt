enable_language(CUDA)
set(list CUDA_Event Stream ThreadCounting
    )
set(
    CUDA_NVCC_FLAGS
    ${CUDA_NVCC_FLAGS};
    -O3 -gencode arch=compute_22,code=sm_22
    )
find_package(CUDAToolkit REQUIRED)
if(NOT DEFINED CMAKE_CUDA_STANDARD)
    set(CMAKE_CUDA_STANDARD 14)
    set(CMAKE_CUDA_STANDARD_REQUIRED ON)
endif()

if(CUDAToolkit_VERSION_MAJOR EQUAL "10")
    set(CUDA_ARCH
        -gencode=arch=compute_30,code=sm_30
        -gencode=arch=compute_35,code=sm_35
        -gencode=arch=compute_37,code=sm_37
        -gencode=arch=compute_50,code=sm_50
        -gencode=arch=compute_52,code=sm_52
        -gencode=arch=compute_60,code=sm_60
        -gencode=arch=compute_61,code=sm_61
        -gencode=arch=compute_70,code=sm_70
        -gencode=arch=compute_75,code=sm_75
    )
elseif(CUDAToolkit_VERSION_MAJOR EQUAL "11" AND CUDAToolkit_VERSION_MINOR LESS "1")
    set(CUDA_ARCH
        -gencode=arch=compute_35,code=sm_35
        -gencode=arch=compute_37,code=sm_37
        -gencode=arch=compute_50,code=sm_50
        -gencode=arch=compute_52,code=sm_52
        -gencode=arch=compute_60,code=sm_60
        -gencode=arch=compute_61,code=sm_61
        -gencode=arch=compute_70,code=sm_70
        -gencode=arch=compute_75,code=sm_75
        -gencode=arch=compute_80,code=sm_80
    )
elseif(CUDAToolkit_VERSION_MAJOR EQUAL "11")
    set(CUDA_ARCH
        -gencode=arch=compute_35,code=sm_35
        -gencode=arch=compute_37,code=sm_37
        -gencode=arch=compute_50,code=sm_50
        -gencode=arch=compute_52,code=sm_52
        -gencode=arch=compute_60,code=sm_60
        -gencode=arch=compute_61,code=sm_61
        -gencode=arch=compute_70,code=sm_70
        -gencode=arch=compute_75,code=sm_75
        -gencode=arch=compute_80,code=sm_80
        -gencode=arch=compute_86,code=sm_86
    )
else()
    set(CUDA_ARCH
        -gencode=arch=compute_30,code=sm_30
        -gencode=arch=compute_35,code=sm_35
        -gencode=arch=compute_37,code=sm_37
        -gencode=arch=compute_50,code=sm_50
        -gencode=arch=compute_52,code=sm_52
        -gencode=arch=compute_60,code=sm_60
        -gencode=arch=compute_61,code=sm_61
        )
endif()
include_directories(
    ${CUDA_INCLUDE_DIRS} /usr/local/cuda-11.2/samples/common/inc
)


set(CUDA_OPTS
    -O3
    -g
    -Xptxas '-dlcm=cg'
    -Xcompiler '-O3'
    -Xcompiler '-fPIC'
    -Xcompiler '-fopenmp'
    -Xcompiler '-msse4'
    -Xcompiler '-m64'
    -Xcompiler '-mpopcnt'
    -Xcompiler '-g'
    -Xlinker 'muldefs'
)

foreach(loop IN LISTS list)
    add_executable(${loop} ${loop}.cu)
    target_link_libraries(${loop} timer 
    CUDA::cudart
    CUDA::cublas
    CUDA::cublasLt
    CUDA::cufft
    CUDA::cufftw
    CUDA::cusparse)
endforeach()
