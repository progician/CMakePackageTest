cmake_minimum_required( VERSION 3.10 )
project( Foo VERSION 1.2.3 )

add_library( Foo STATIC src/Foo.cpp )
set_target_properties( Foo PROPERTIES DEBUG_POSTFIX _debug )

target_include_directories( Foo
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include> )


install( TARGETS Foo
  EXPORT FooLib
  ARCHIVE DESTINATION lib )
install( DIRECTORY include/Foo
  DESTINATION include )
install( EXPORT FooLib
  NAMESPACE Foo::
  CONFIGURATIONS Release Debug
  DESTINATION cmake )

configure_file( FooLibConfig.cmake.in FooLibConfig.cmake @ONLY )
configure_file( FooLibConfigVersion.cmake.in FooLibConfigVersion.cmake @ONLY )
install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/FooLibConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/FooLibConfigVersion.cmake
  DESTINATION cmake )

set( CPACK_PACKAGE_VERSION ${PROJECT_VERSION} )
include( CPack )
