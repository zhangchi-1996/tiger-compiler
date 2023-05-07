cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project(LexicalSyntax)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(FLEX 2.6 REQUIRED)

FLEX_TARGET(LEXER 
    ${PROJECT_SOURCE_DIR}/LexicalSyntax/tiger.lex 
    ${PROJECT_SOURCE_DIR}/lex.cc)

add_executable(LexicalSyntax driver.cc ${FLEX_LEXER_OUTPUTS})