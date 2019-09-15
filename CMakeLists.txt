cmake_minimum_required(VERSION 3.0)
project(MatrixWoR)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS system filesystem unit_test_framework)
link_directories(${Boost_LIBRARY_DIR})

link_libraries(gcov)


add_executable(MatrixWoR
        src/Main.cpp)

add_executable(TestMatrixWoR
        test/Main_test.cpp
        test/Matrix_test.cpp)

target_link_libraries(TestMatrixWoR gcov ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_compile_options(TestMatrixWoR PUBLIC -g -O0 --coverage -ftest-coverage -fprofile-arcs)

