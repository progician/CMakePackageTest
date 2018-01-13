cmake_minimum_required( VERSION 3.10 )
project( Bar VERSION 1.0 )

find_package( FooLib REQUIRED )
find_package( ShGLib REQUIRED )

add_executable( Bar src/Bar.cpp )
target_link_libraries( Bar
  PRIVATE
    Foo::Foo
    Shared::Goodies )
