cmake_minimum_required (VERSION 3.14)

set(PRJ_NAME MathLibrary)

set(PRJ_VER_MAJOR 0)
set(PRJ_VER_MINOR 0)
set(PRJ_VER_PATCH 0)
set(PRJ_VER_REVISION 1)
set(PRJ_VER_CMN ${PRJ_VER_MAJOR}.${PRJ_VER_MINOR}.${PRJ_VER_PATCH})
set(PRJ_VER_FULL ${PRJ_VER_CMN}.${PRJ_VER_REVISION})

message(STATUS [Library Version]:[${PRJ_VER_FULL}])
option (BUILD_SHARED_LIBS "Build the library as shared library" ON)
project(${PRJ_NAME} VERSION ${PRJ_VER_FULL} LANGUAGES CXX )
set (CMAKE_CONFIGURATION_TYPES Debug;Release)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CONFIGURATION_TYPES Debug;Release)

if(NOT $ENV{PRJ_NAME} OR $ENV{PRJ_NAME} EQUAL "")
	set(ENV{PRJ_NAME} "${PROJECT_SOURCE_DIR}/out/lib")
endif()

set(LIB_SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src")
set(LIB_WRAP_PATH "${CMAKE_CURRENT_LIST_DIR}/wrapper/native")

set(
	HEADERS_DIRS
	"${LIB_SRC_PATH}/include/"

	"${LIB_WRAP_PATH}/common/include/"
	"${LIB_WRAP_PATH}/lib/include/"
)

file(GLOB_RECURSE
	SOURCES_FILES
	"${LIB_SRC_PATH}/impl/*.cpp"

	"${LIB_WRAP_PATH}/lib/impl/*.cpp"
)

add_library(${PRJ_NAME} SHARED ${SOURCES_FILES} ${VersionFilesLib})

target_include_directories(${PRJ_NAME} PUBLIC ${HEADERS_DIRS})

if(WIN32)
list(APPEND INTERFACE_HEADER_FILES 
	"${LIB_WRAP_PATH}/common/include/lib_export.h"

	"${LIB_WRAP_PATH}/lib/include/mathlib_api.h"
)
endif (WIN32)

if(WIN32)
    if (CMAKE_BUILD_TYPE MATCHES Debug)
        set(INSTALL_DIR $ENV{PRJ_NAME}/libs/windows_d)
	    install(FILES ${INTERFACE_HEADER_FILES} DESTINATION $ENV{PRJ_NAME}/include)
	    install(TARGETS ${PRJ_NAME} DESTINATION ${INSTALL_DIR})
        install(FILES $<TARGET_PDB_FILE:${PRJ_NAME}> DESTINATION ${INSTALL_DIR} OPTIONAL)
    else()
        set(INSTALL_DIR $ENV{PRJ_NAME}/libs/windows)
	    install(FILES ${INTERFACE_HEADER_FILES} DESTINATION $ENV{PRJ_NAME}/include)
	    install(TARGETS ${PRJ_NAME} DESTINATION ${INSTALL_DIR})
    endif()
endif (WIN32)

if(ANDROID)
    if (CMAKE_BUILD_TYPE MATCHES Debug)
        set(INSTALL_DIR $ENV{PRJ_NAME}/libs/android)
	    install(FILES ${INTERFACE_HEADER_FILES} DESTINATION $ENV{PRJ_NAME}/include)
	    install(TARGETS ${PRJ_NAME} DESTINATION ${INSTALL_DIR})
        install(FILES $<TARGET_PDB_FILE:${PRJ_NAME}> DESTINATION ${INSTALL_DIR} OPTIONAL)
    else()
        set(INSTALL_DIR $ENV{PRJ_NAME}/libs/android)
	    install(FILES ${INTERFACE_HEADER_FILES} DESTINATION $ENV{PRJ_NAME}/include)
	    install(TARGETS ${PRJ_NAME} DESTINATION ${INSTALL_DIR})
    endif()
endif (ANDROID)


