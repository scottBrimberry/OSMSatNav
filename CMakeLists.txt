cmake_minimum_required(VERSION 2.6)
project(SatNav)

find_package(Qt4 REQUIRED)

set(CMAKE_CXX_FLAGS "-g -Wall")

include(${QT_USE_FILE})

set (osmdata_SRCS
  osmmap.cpp
  osmnode.cpp
  osmrelation.cpp
  osmrelationmember.cpp
  osmtag.cpp
  osmtaggable.cpp
  osmway.cpp
)

set (satnav_SRCS
  ${osmdata_SRCS}
  xmlparser.cpp
)

add_executable(satnav ${satnav_SRCS})
target_link_libraries(satnav ${QT_LIBRARIES})

#install(TARGETS amaroklicensechecker DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

