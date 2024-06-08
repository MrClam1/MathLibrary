cmake_minimum_required(VERSION 3.14)

set(PRJ_NAME CipherControlSystemLibrary)
set(PRJ_NAME_DESC "SDKHardwareWrap")

set(PRJ_VER_MAJOR 1)
set(PRJ_VER_MINOR 2)
set(PRJ_VER_PATCH 8)
set(PRJ_VER_REVISION 8)
set(PRJ_VER_CMN "${PRJ_VER_MAJOR}.${PRJ_VER_MINOR}.${PRJ_VER_PATCH}")
set(PRJ_VER_FULL "${PRJ_VER_CMN}.${PRJ_VER_REVISION}")

project(
    ${PRJ_NAME}
    VERSION ${PRJ_VER_FULL}
    LANGUAGES CXX)

set(LIB_SRC_PATH "${CMAKE_CURRENT_LIST_DIR}")

file(GLOB_RECURSE
	LIB_SRC_FILES
	"${LIB_SRC_PATH}/cipher/impl/*.cpp"
	"${LIB_SRC_PATH}/functions/impl/*.cpp"
	"${LIB_SRC_PATH}/types/impl/*.cpp"
)
set(LIB_HEADER_PATH
	"${LIB_SRC_PATH}/cipher/include/"
	"${LIB_SRC_PATH}/functions/include/"
	"${LIB_SRC_PATH}/types/include/"
)

add_library (${PRJ_NAME} STATIC ${LIB_SRC_FILES})
target_include_directories(${PRJ_NAME} PUBLIC ${LIB_HEADER_PATH})
#target_link_libraries(${PRJ_NAME} PUBLIC ${PRJ_SDK_COMMON} ${PRJ_SDK_USB})