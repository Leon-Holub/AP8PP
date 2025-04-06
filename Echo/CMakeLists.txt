cmake_minimum_required(VERSION 3.16)

project(Echo LANGUAGES C)

add_executable(Echo main.c)

include(GNUInstallDirs)
install(TARGETS Echo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
