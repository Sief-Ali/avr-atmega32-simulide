# CMake build : components

#configure variables
set(COMP_NAME "${PROJECT_NAME}comp")

#configure directories
set(COMPONENTS_MODULE_PATH "${PROJECT_SOURCE_DIR}/src/components")
set(COMPONENTS_SRC_PATH  "${COMPONENTS_MODULE_PATH}/src" )
set(COMPONENTS_INCLUDE_PATH  "${COMPONENTS_MODULE_PATH}/include")

#set sources
file(GLOB COMP_HEADER_FILES CONFIGURE_DEPENDS "${COMPONENTS_INCLUDE_PATH}/*.h")
file(GLOB COMP_SOURCE_FILES CONFIGURE_DEPENDS
    "${COMPONENTS_SRC_PATH}/*.c"
)

#set library
add_library(${COMP_NAME} STATIC
    ${COMP_SOURCE_FILES}
    ${COMP_HEADER_FILES}
)

# expose includes
target_include_directories(${COMP_NAME}
    PUBLIC
        ${COMPONENTS_INCLUDE_PATH}
)
target_link_libraries(${COMP_NAME}
    PUBLIC
        avr_options
)

#export vars
set(COMPONENTS_INCLUDE_PATH  ${COMPONENTS_INCLUDE_PATH} PARENT_SCOPE)
set(COMP_NAME ${COMP_NAME} PARENT_SCOPE)
