include(${CMAKE_CURRENT_LIST_DIR}/Rs232.cmake)  

get_filename_component(ZLIB_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(ZLIB_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

SET(RS232_LIBRARIES Rs232)    

set(Rs232_FOUND TRUE)