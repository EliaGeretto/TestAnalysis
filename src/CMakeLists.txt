add_llvm_library(${PASS_NAME} MODULE TestAnalysis.cpp)
add_library(TestAnalysis::${PASS_NAME} ALIAS ${PASS_NAME})

target_compile_definitions(${PASS_NAME} PRIVATE ${LLVM_DEFINITIONS})
if(${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" OR ${CMAKE_CXX_COMPILER_ID}
                                                STREQUAL "GNU")
  target_compile_options(${PASS_NAME} PRIVATE "-Wall" "-Wextra"
                                              "-Wno-unused-parameter")
endif()

target_include_directories(${PASS_NAME} PRIVATE ${LLVM_INCLUDE_DIRS})
target_link_libraries(${PASS_NAME} PRIVATE Headers)
