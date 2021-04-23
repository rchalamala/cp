project(library)

file(GLOB_RECURSE HEADER_FILES "*.hpp")
add_library(library INTERFACE ${HEADER_FILES})