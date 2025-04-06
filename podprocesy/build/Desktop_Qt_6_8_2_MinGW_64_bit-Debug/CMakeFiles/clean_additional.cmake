# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\podprocesy_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\podprocesy_autogen.dir\\ParseCache.txt"
  "podprocesy_autogen"
  )
endif()
