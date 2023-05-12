add_executable(cbrt_test
  "${CMAKE_CURRENT_SOURCE_DIR}/cbrt_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)
add_executable(cosh_test
  "${CMAKE_CURRENT_SOURCE_DIR}/cosh_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)
add_executable(cub_test
  "${CMAKE_CURRENT_SOURCE_DIR}/cub_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)
add_executable(exp_test
  "${CMAKE_CURRENT_SOURCE_DIR}/exp_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)
add_executable(fabs_test
  "${CMAKE_CURRENT_SOURCE_DIR}/fabs_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)
add_executable(floor_test
  "${CMAKE_CURRENT_SOURCE_DIR}/floor_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)
add_executable(log_test
  "${CMAKE_CURRENT_SOURCE_DIR}/log_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)
add_executable(sinh_test
  "${CMAKE_CURRENT_SOURCE_DIR}/sinh_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)
add_executable(sqr_test
  "${CMAKE_CURRENT_SOURCE_DIR}/sqr_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)
add_executable(sqrt_test
  "${CMAKE_CURRENT_SOURCE_DIR}/sqrt_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)
add_executable(tanh_test
  "${CMAKE_CURRENT_SOURCE_DIR}/tanh_test.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/lib/wrapper.c"
)

target_include_directories(cbrt_test  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(cosh_test  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(cub_test   PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(exp_test   PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(fabs_test  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(floor_test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(log_test   PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(sinh_test  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(sqr_test   PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(sqrt_test  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(tanh_test  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(cbrt_test  ${CMAKE_PROJECT_NAME} m cmocka)
target_link_libraries(cosh_test  ${CMAKE_PROJECT_NAME} m cmocka)
target_link_libraries(cub_test   ${CMAKE_PROJECT_NAME} m cmocka)
target_link_libraries(exp_test   ${CMAKE_PROJECT_NAME} m cmocka)
target_link_libraries(fabs_test  ${CMAKE_PROJECT_NAME} m cmocka)
target_link_libraries(floor_test ${CMAKE_PROJECT_NAME} m cmocka)
target_link_libraries(log_test   ${CMAKE_PROJECT_NAME} m cmocka)
target_link_libraries(sinh_test  ${CMAKE_PROJECT_NAME} m cmocka)
target_link_libraries(sqr_test   ${CMAKE_PROJECT_NAME} m cmocka)
target_link_libraries(sqrt_test  ${CMAKE_PROJECT_NAME} m cmocka)
target_link_libraries(tanh_test  ${CMAKE_PROJECT_NAME} m cmocka)
