set(PRG      prg_add)
set(PRG_SRC  prg_add.c)


#### Add executable. ####
add_executable(${PRG} ${PRG_SRC})

#### Link the current library. ####
target_link_libraries(${PRG} ${PROJECT_NAME})

### Link a third-party library. ###
find_package(argp)
target_link_libraries(${PRG} ${ARGP_LIBRARIES})
target_include_directories(${PRG} PUBLIC ${ARGP_INCLUDE_PATH})

### Add compile options to the target of the library. ###
target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
target_compile_options(${PROJECT_NAME} PRIVATE -Wextra)
target_compile_options(${PROJECT_NAME} PRIVATE -pedantic)
set_property(TARGET    ${PROJECT_NAME} PROPERTY C_STANDARD 90)

### Install the program. ####
install(TARGETS ${PRG} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
