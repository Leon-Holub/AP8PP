# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\sprites_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\sprites_autogen.dir\\ParseCache.txt"
  "sprites_autogen"
  )
endif()
