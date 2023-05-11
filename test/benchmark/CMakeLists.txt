add_executable(cbrt_bm_test
  "${CMAKE_CURRENT_SOURCE_DIR}/cbrt_test.cpp"
)
add_executable(cub_bm_test
  "${CMAKE_CURRENT_SOURCE_DIR}/cub_test.cpp"
)
add_executable(exp_bm_test
  "${CMAKE_CURRENT_SOURCE_DIR}/exp_test.cpp"
)
add_executable(fabs_bm_test
  "${CMAKE_CURRENT_SOURCE_DIR}/fabs_test.cpp"
)
add_executable(floor_bm_test
  "${CMAKE_CURRENT_SOURCE_DIR}/floor_test.cpp"
)

target_include_directories(cbrt_bm_test  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(cub_bm_test   PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(exp_bm_test   PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(fabs_bm_test  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(floor_bm_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(cbrt_bm_test  ${CMAKE_PROJECT_NAME} benchmark)
target_link_libraries(cub_bm_test   ${CMAKE_PROJECT_NAME} benchmark)
target_link_libraries(exp_bm_test   ${CMAKE_PROJECT_NAME} benchmark)
target_link_libraries(fabs_bm_test  ${CMAKE_PROJECT_NAME} benchmark)
target_link_libraries(floor_bm_test ${CMAKE_PROJECT_NAME} benchmark)
