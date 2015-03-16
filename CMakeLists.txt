cmake_minimum_required(VERSION 2.8.4)
project(jointAngles)

include(FindPkgConfig)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(GAZEBO gazebo)
endif()

include(FindBoost)
find_package(Boost ${MIN_BOOST_VERSTION} REQUIRED system filesystem regex)

find_package(Protobuf REQUIRED)

include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})

find_package(Qt4 REQUIRED)


include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
                                  
# another list, this time it includes all header files that should be treated with moc
set(  JOINTANGLE_MOC_HDRS
      dialog.h 
      sliderdoublespinbox.h
commthread.h

)


QT4_WRAP_CPP( JOINTANGLE_MOC_SRCS ${JOINTANGLE_MOC_HDRS} )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp dialog.cpp sliderdoublespinbox.cpp commthread.cpp)
add_executable(jointAngles ${SOURCE_FILES} ${JOINTANGLE_MOC_SRCS})

target_link_libraries(jointAngles ${GAZEBO_LIBRARIES} ${Boost_LIBRARIES} ${PROTOBUF_LIBRARIES} ${QT_LIBRARIES} pthread)
