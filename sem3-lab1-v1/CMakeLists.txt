cmake_minimum_required(VERSION 3.22) # Минимальная версия Cmake

project(sem3-lab1-v1) # Название проекта

set(CMAKE_CXX_STANDARD 11) # Версия стандарта C++

set(SOURCE_EXE src/main.cpp) # Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB src/function.cpp) # Установка переменной со списком исходников для библиотеки

add_library(function STATIC ${SOURCE_LIB}) # Создание статической библиотеки

add_executable(main ${SOURCE_EXE}) # Создаие исполняеого файла

target_link_libraries(main function) # Линковка программы с библиотекой