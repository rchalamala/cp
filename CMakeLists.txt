project(CP)

cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE SOURCES "library/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp")

add_executable(test ${TASKS} ${SOURCES} ${HEADERS})
add_executable(testrunner testrunner/main.cpp)
add_executable(output output/main.cpp)

add_compile_options(--coverage)
link_libraries(gcov)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLOCAL -pedantic -Wall -Wcast-align -Wcast-qual -Wconversion -Wdouble-promotion -Wduplicated-branches -Wduplicated-cond -Wextra -Wfloat-equal -Wformat=2 -Wlogical-op -Wno-unused-parameter -Wnull-dereference  -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wrestrict -Wshadow -Wshift-overflow=2 -Wsign-compare -Wundef -Wuseless-cast -Wwrite-strings")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=2 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g") #COMMENT FOR VALGRIND
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -g") #COMMENT FOR VALGRIND
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=float-cast-overflow -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=float-divide-by-zero -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-sanitize-recover=all -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector-all -g")
