####################################
# Project hello_avro_cpp           # 
# Plataforms: CentosOs8            #
# Developer: Gelson Rodrigues      #
#                                  #
# Enviroment:                      #
# gcc: 8.0 - used C++17            #
# cmake: 3.2                       #
#                                  #
# Libraries:                       #
#      Boost: 1.66     always      #
#      Avro-C++        option      #
#      Kafkad_C++      option      #
#      Libserdes_c++   option      #
####################################

#Sections
   #Section 0 - Explanation about varaibles and warnings
   #Section 1 - configuration about project
   #Section 2 - Definition for compilation Linux/Win
   #Section 3 - Add extern libraries(boost,xml2..)  
   #Section 4 - Version based on svn(only release)
   #Section 5 - Add new project inside source
   #Section 6 - Set which libs while be in the project   

#Section 0
#----------------  Helpers  -----------------------#

#Section 1
#------------------- Path's to build ----------------------------#

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: Debug Release" FORCE)
endif() 

SET(PROJECT_NAME "hello_avro_cpp") 

project("${PROJECT_NAME}")
cmake_minimum_required (VERSION 3.0)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(IS_DEBUG TRUE) 
elseif(CMAKE_BUILD_TYPE STREQUAL "Release") 
	set(IS_DEBUG FALSE)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")
   
#Section 2
#------------------- Set Global variables----------------------------#
   # cpp flags
  set(CMAKE_CXX_FLAGS "")
  #-D_GLIBCXX_USE_CXX11_ABI=0
  SET(CMAKE_CXX_FLAGS_RELEASE "-std=c++1z -O2 -isystem /usr/local/include -g -lpthread -ldl -lavrocpp -lrdkafka")
  SET(CMAKE_CXX_FLAGS_DEBUG "-std=c++1z -isystem /usr/local/include -g -lpthread -ldl -lavrocpp -lavro -lrdkafka++ -lrdkafka -lcurl -ljansson ")
  SET(LIBRARIES_BIN_PATH /usr/local/lib CACHE STRING "Location .a, .so")
  SET(LIBRARIES_INCLUDE_PATH /usr/local/include CACHE STRING "Location of includes")
 
  #Section 3
#------------------- Add extern Libs ----------------------------#
#Always Boost

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREAD ON)
find_package(Boost REQUIRED COMPONENTS thread system filesystem timer chrono date_time locale signals iostreams )
IF(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)

#Set libraries optionals
option(LIBAVRO_CPP "Enable Avro C++" ON) 
option(LIBKAFKA "Enable Kafka C++" ON) 
option(LIBSERDES "Enable LibSerdes C++" ON)

set(LIBRARIES_LIBRARY_PATH /usr/local/lib)
set(LIBRARIES_INCLUDE_PATH /usr/local/include)

if(LIBAVRO_CPP)
#AVRO DEFINITIONS
SET(avro_INCLUDE_DIR ${LIBRARIES_INCLUDE_PATH}/avro)
SET(avro_LIBRARIES ${LIBRARIES_LIBRARY_PATH}/libavrocpp.so.1.8.2.0)
include_directories(${avro_INCLUDE_DIR})
endif(LIBAVRO_CPP)

if(LIBKAFKA)
#KAFKA DEFINITIONS
SET(kafka_INCLUDE_DIR ${LIBRARIES_INCLUDE_PATH}/avro)
SET(kafka_LIBRARIES  /usr/local/lib64/librdkafka.so.1 /usr/local/lib64/librdkafka++.so )
include_directories(${kafka_INCLUDE_DIR})
endif(LIBKAFKA)

if(LIBSERDES)
#LIBSERDES DEFINITIONS
SET(libserdes_INCLUDE_DIR ${LIBRARIES_INCLUDE_PATH} ${LIBRARIES_INCLUDE_PATH}/libserdes)
SET(libserdes_LIBRARIES  ${LIBRARIES_LIBRARY_PATH}/libserdes++.a ${LIBRARIES_LIBRARY_PATH}/libserdes.a )
include_directories(${kafka_INCLUDE_DIR})
endif(LIBSERDES)

#DL DEFINITIONS
SET(dl_LIBRARIES "/lib64/libdl.so.2")

#PTHREAD DEFINITIONS
SET(pthread_LIBRARIES "/lib64/libpthread.so.0")

#Section 4
#------------------- Version  ----------------------------#

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  SET(IS_DEBUG TRUE)
  SET(Exe_installation ${CMAKE_CURRENT_BINARY_DIR}/Debug)
  SET(Libs_installation ${Exe_installation}/lib)	
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  SET(Exe_installation ${CMAKE_CURRENT_BINARY_DIR}/Release)
  SET(Libs_installation ${Exe_installation}/lib)
  SET(IS_DEBUG FALSE)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")
file(GLOB_RECURSE ${PROJECT_NAME}_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/source/*.hpp")
set (${PROJECT_NAME}_INCLUDE_DIRS "")
foreach (_headerFile ${${PROJECT_NAME}_HEADERS})
  get_filename_component(_dir ${_headerFile} PATH)
  list (APPEND ${PROJECT_NAME}_INCLUDE_DIRS ${_dir})
endforeach()

list(REMOVE_DUPLICATES ${PROJECT_NAME}_INCLUDE_DIRS)
 
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/"
"${CMAKE_CURRENT_SOURCE_DIR}/source/${PROJECT_NAME}")

SET(${PROJECT_NAME}_BUILD_DIRECTORY "${Exe_installation}/${PROJECT_NAME}")
 
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME}_BUILD_DIRECTORY})

 #Section 6
 install(TARGETS ${PROJECT_NAME} DESTINATION bin)   
 SET(${PROJECT_NAME}_TARGET_LIBRARIES            
       ${Boost_FILESYSTEM_LIBRARY}
       ${Boost_THREAD_LIBRARY}
       ${Boost_SYSTEM_LIBRARY}
       ${Boost_THREAD_LIBRARIES}
       ${Boost_DATE_TIME_LIBRARIES}
       ${Boost_FILESYSTEM_LIBRARIES}
       ${Boost_SYSTEM_LIBRARIES}
       ${Boost_TIMER_LIBRARIES}
       ${Boost_CHRONO_LIBRARIES}
       ${Boost_PROGRAM_OPTIONS_LIBRARIES}
       ${Boost_PROGRAM_OPTIONS_LIBRARIES}
       ${avro_LIBRARIES}
       ${kafka_LIBRARIES}
       ${libserdes_LIBRARIES}
    )
 list(REMOVE_DUPLICATES ${PROJECT_NAME}_TARGET_LIBRARIES)
 target_link_libraries(${PROJECT_NAME} ${${PROJECT_NAME}_TARGET_LIBRARIES})

 