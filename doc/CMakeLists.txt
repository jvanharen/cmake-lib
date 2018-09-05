option(BUILD_DOC OFF)

if(BUILD_DOC)
  find_package(Doxygen)
  find_package(Sphinx)
  if(Doxygen_FOUND AND Sphinx_FOUND)
    ### Doxygen target. ###
    set(DOXYGEN_IN  ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message(STATUS "Doxygen build started")
    add_custom_target(doxygen
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Build Doxygen xml files used by sphinx/breathe."
      VERBATIM)
    ### Sphinx html target. ###
    set(SPHINX_BINARY_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
    set(SPHINX_CACHE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/doctrees")
    set(SPHINX_HTML_DIR         "${CMAKE_CURRENT_BINARY_DIR}/html")
    configure_file("${CMAKE_SOURCE_DIR}/doc/conf.py.in"
      "${SPHINX_BINARY_BUILD_DIR}/conf.py" @ONLY)
    add_custom_target(doc
      ${SPHINX_EXECUTABLE}
      -q -b html
      -c "${SPHINX_BINARY_BUILD_DIR}"
      -d "${SPHINX_CACHE_DIR}"
      "${CMAKE_SOURCE_DIR}/doc"
      "${SPHINX_HTML_DIR}"
      DEPENDS doxygen
      COMMENT "Building HTML documentation with Sphinx"
    )
    install(DIRECTORY ${SPHINX_HTML_DIR} DESTINATION ${CMAKE_INSTALL_DOCDIR})
  else(Doxygen_FOUND AND Sphinx_FOUND)
    message(STATUS "Doxygen and Sphinx need to be installed to generate the documentation")
  endif(Doxygen_FOUND AND Sphinx_FOUND)
endif(BUILD_DOC)
