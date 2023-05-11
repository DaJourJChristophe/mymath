
FILE(GLOB MyCSources "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

add_library(${CMAKE_PROJECT_NAME} SHARED ${MyCSources})

set_target_properties("${CMAKE_PROJECT_NAME}" PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/libexec"
)

# target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE m)
