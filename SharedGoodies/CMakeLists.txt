cmake_minimum_required( VERSION 3.10 )
include( GenerateExportHeader )
project( SharedGoodies VERSION 1.5.0 )

add_library( Goodies SHARED src/Goodies.cpp )
set_target_properties( Goodies
  PROPERTIES
    DEBUG_POSTFIX _debug
    VERSION ${PROJECT_VERSION}
    CXX_VISIBILITY_PRESET hidden )
target_compile_features( Goodies PRIVATE cxx_std_14 )

generate_export_header( Goodies )

target_include_directories( Goodies
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include> )


install( TARGETS Goodies EXPORT ShGLib LIBRARY DESTINATION lib )
install( DIRECTORY include/Shared DESTINATION include )
install( FILES ${PROJECT_BINARY_DIR}/goodies_export.h DESTINATION include )
install( EXPORT ShGLib NAMESPACE Shared:: CONFIGURATIONS Release Debug DESTINATION cmake )

configure_file( ShGConfig.cmake.in ShGLibConfig.cmake @ONLY )
configure_file( ShGConfigVersion.cmake.in ShGLibConfigVersion.cmake @ONLY )
install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ShGLibConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ShGLibConfigVersion.cmake
  DESTINATION cmake )

set( CPACK_PACKAGE_VERSION ${PROJECT_VERSION} )
include( CPack )

