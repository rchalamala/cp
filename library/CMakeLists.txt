project(library)

file(GLOB_RECURSE HEADERS "*.hpp")
add_library(library INTERFACE ${HEADERS})