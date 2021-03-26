# path to benchmark datasets
set(DATASET_PATH "${PROJECT_SOURCE_DIR}/dataset")

add_library(benchmark_definitions INTERFACE)
target_compile_definitions(benchmark_definitions INTERFACE DATASET_PATH=${DATASET_PATH})

# add benchmark targets here ...
add_executable(demo_benchmark demo_benchmark.cpp)
target_link_libraries(demo_benchmark PRIVATE benchmark_definitions ${PROJECT_NAME})
