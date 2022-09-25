cmake_minimum_required(VERSION 3.22) # Проверка версии CMake.
project(prog_sem3_lab1_v15) # Название проекта
set(SOURCE_EXE src/main.cpp) # Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB src/function.cpp) # Тоже самое, но для библиотеки

add_library(function STATIC ${SOURCE_LIB}) # Создание статической библиотеки с именем function
add_executable(main ${SOURCE_EXE}) # Создает исполняемый файл с именем main
target_link_libraries(main function) # Линковка программы с библиотекой