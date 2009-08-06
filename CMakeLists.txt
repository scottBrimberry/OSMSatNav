cmake_minimum_required(VERSION 2.6)
project(SatNav)

find_package(Qt4 REQUIRED)

set(CMAKE_CXX_FLAGS "-g -Wall")

set(QT_USE_QTSQL true)
include(${QT_USE_FILE})

set (osmdata_SRCS
  database.cpp
  osmmap.cpp
  osmnode.cpp
  osmrelation.cpp
  osmrelationmember.cpp
  osmtag.cpp
  osmtaggable.cpp
  osmway.cpp
  osmxml.cpp
)

set (satnav_SRCS
  ${osmdata_SRCS}
  main.cpp
)

add_executable(satnav ${satnav_SRCS})
target_link_libraries(satnav ${QT_LIBRARIES} ${QT_QTSQL_LIBRARY})

#install(TARGETS amaroklicensechecker DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

