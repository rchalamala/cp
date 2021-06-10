project(library)

file(GLOB_RECURSE HEADER_FILES "*.hpp")
add_library(library INTERFACE)
target_sources(library INTERFACE  ${HEADER_FILES})