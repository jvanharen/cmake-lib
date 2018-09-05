set(PRG_SRC
  prg_add.c
  prg_sub.c
)

foreach(IPRG_SRC ${PRG_SRC})
  get_filename_component(IPRG ${IPRG_SRC} NAME_WE)
  #### Add executable. ####
  add_executable(${IPRG} ${IPRG_SRC})
  #### Link the current library. ####
  target_link_libraries(${IPRG} ${PROJECT_NAME})
  ### Link a third-party library. ###
  find_package(argp)
  target_link_libraries(${IPRG} ${ARGP_LIBRARIES})
  target_include_directories(${IPRG} PUBLIC ${ARGP_INCLUDE_PATH})
  ### Add compile options to the target. ###
  target_compile_options(${IPRG} PRIVATE -Wall)
  target_compile_options(${IPRG} PRIVATE -Wextra)
  target_compile_options(${IPRG} PRIVATE -pedantic)
  set_property(TARGET    ${IPRG} PROPERTY C_STANDARD 90)
  ### Install the program. ####
  install(TARGETS ${IPRG} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endforeach(IPRG_SRC ${PRG_SRC})
