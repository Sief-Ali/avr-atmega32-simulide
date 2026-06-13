# CMake build : library

#configure variables
set(LIB_NAME "${PROJECT_NAME}Lib")

#configure directories
set(LIBRARY_MODULE_PATH "${PROJECT_SOURCE_DIR}/libs")
set(LIBRARY_SRC_PATH  "${LIBRARY_MODULE_PATH}/src" )
set(LIBRARY_INCLUDE_PATH  "${LIBRARY_MODULE_PATH}/include")

#set sources
file(GLOB LIB_HEADER_FILES CONFIGURE_DEPENDS "${LIBRARY_INCLUDE_PATH}/*.h")
file(GLOB LIB_SOURCE_FILES CONFIGURE_DEPENDS
    "${LIBRARY_SRC_PATH}/*.c"
)

#set library
add_library(${LIB_NAME} STATIC
    ${LIB_SOURCE_FILES}
    ${LIB_HEADER_FILES}
)

# expose includes
target_include_directories(${LIB_NAME}
    PUBLIC
        ${LIBRARY_INCLUDE_PATH}
)
target_link_libraries(${LIB_NAME}
    PUBLIC
        avr_options
)

#export vars
set(LIBRARY_INCLUDE_PATH  ${LIBRARY_INCLUDE_PATH} PARENT_SCOPE)
set(LIB_NAME ${LIB_NAME} PARENT_SCOPE)
