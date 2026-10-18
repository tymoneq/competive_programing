cmake_minimum_required(VERSION 3.15)
project(MojProjekt CXX)

# Opcja wymagana dla clangd do poprawnego działania autouzupełniania!
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Twój plik wykonywalny i pliki źródłowe
add_executable(app G.cpp)