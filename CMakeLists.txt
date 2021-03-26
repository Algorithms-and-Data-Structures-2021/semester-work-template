cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

# Определите название вашего проекта (должно совпадать с названием репозитория).
# Примечание: замените символ '-' на '_'.
project(semester_work_template CXX)

# === Определение стандарта C++ для всего проекта ===

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === Опции (флаги) ===

option(ENABLE_TESTING "Build unit tests" FALSE)
option(ENABLE_STATIC_CODE_ANALYSIS "Static code analysis during build" TRUE)

# === "Включение" предупреждений компилятора (target) ===

# создание интерфейсной библиотеки (т.е. библиотеки без исходных файлов)
add_library(project_warnings INTERFACE)

# установка параметров компиляции для библиотеки
include(cmake/CompilerWarnings.cmake)   # добавление содержимого CompilerWarnings.cmake в этот файл
set_project_warnings(project_warnings)  # set_project_warnings - определена в файле cmake/CompilerWarnings.cmake

# Примечание: параметры компиляции будут задействованы для всех библиотек и исполняемых файлов,
# которые линкуются с данной интерфейсной библиотекой.

# === Библиотека со структурой данных (target) ===

# синтаксис add_library(<название библиотеки (target)> <тип библиотеки> <список исходных и заголовочных файлов>)
add_library(${PROJECT_NAME} STATIC
        src/data_structure.cpp
        include/data_structure.hpp)

# включить предупреждения компилятора для библиотеки (линковка)
target_link_libraries(${PROJECT_NAME} PRIVATE project_warnings)

# обозначить директорию с заголовочными файлами для библиотеки
target_include_directories(${PROJECT_NAME} PUBLIC include)

# === Подключение подмодулей проекта ===

add_subdirectory(dataset)
add_subdirectory(examples)
#add_subdirectory(benchmark)

# === Тестирование ===

if (ENABLE_TESTING)
    enable_testing()         # включить генерацию тестовых файлов
    add_subdirectory(tests)
endif ()

# === main (target) ===
add_executable(main main.cpp)
target_link_libraries(main PRIVATE project_warnings ${PROJECT_NAME})

if (ENABLE_STATIC_CODE_ANALYSIS)
    include(cmake/StaticAnalyzers.cmake)
endif ()
