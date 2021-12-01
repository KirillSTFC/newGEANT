cmake_minimum_required(VERSION 2.6 FATAL_ERROR) #[[check Cmake minimum version. our version should be less, or it will be fatal error]]
project(nSimulation)#[[Name of project which we want to start]]
find_package(Geant4 REQUIRED ui_all vis_all) #[[it is required Geant4 package and we also added User interface and visualization/////////]]
include (${Geant4_USE_FILE}) #[[]]

find_package(ROOT REQUIRED) #[[it is required Geant4 package and we also added User interface and visualization/////////]]
include (${ROOT_USE_FILE}) #[[]]


#include_directories(${PROJECT_SOURCE_DIR})
file(GLOB sources ${POJECT_SOURCE_DIR}/*.cc) #[[project source is the folder where CmakeLists.txt is positioned. We have told that it should take all cc files from the project source]]
file(GLOB headers ${POJECT_SOURCE_DIR}/*.hh)#[[Same for the header files]]
file(GLOB MACRO_FILES "*.mac") #adding macro files
file (COPY ${MACRO_FILES} DESTINATION ${PROJECT_BINARY_DIR})#it means thaat it copies all files we creatrd in the project folder into build folder.
add_executable (nsim nsim.cc ${sources} ${headers})#[[Name of the executable and the source file. we also telling it to use sources and header files]u]]
target_link_libraries(nsim ${Geant4_LIBRARIES}) #[[Connect libraries which we istalled with geant4]]

add_custom_target(nSimulation DEPENDS nsim)#connect project name and executable
