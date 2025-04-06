# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QTimer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QTimer_autogen.dir\\ParseCache.txt"
  "QTimer_autogen"
  )
endif()
