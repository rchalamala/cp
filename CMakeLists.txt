cmake_minimum_required(VERSION 3.26)
project(CP)

set(CMAKE_CXX_STANDARD 17)

file(GLOB TASK_FILES "tasks/*.cpp")

include_directories(library)
add_subdirectory(library)

add_executable(test ${TASK_FILES})
add_executable(testrunner testrunner/main.cpp)
add_executable(output output/main.cpp)

target_link_libraries(test library)
target_link_libraries(testrunner library)
target_link_libraries(output library)

add_compile_options(--coverage)
#[[
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLOCAL -pedantic -Wall -Wcast-align -Wcast-qual -Wconversion -Wdouble-promotion -Wduplicated-branches -Wduplicated-cond -Wextra -Wfloat-equal -Wformat=2 -Wlogical-op -Wno-unused-parameter -Wnull-dereference  -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wrestrict -Wshadow -Wshift-overflow=2 -Wsign-compare -Wundef -Wuseless-cast -Wwrite-strings")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g") #COMMENT FOR VALGRIND
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -g") #COMMENT FOR VALGRIND
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -g") #COMMENT FOR VALGRIND

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=float-cast-overflow -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=float-divide-by-zero -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-sanitize-recover=all -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector-all -g")
]]
