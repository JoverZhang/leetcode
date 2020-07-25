include_directories(${PROJECT_SOURCE_DIR}/lib)

aux_source_directory(./ DIR_SOLUTION)

add_executable(main ${DIR_SOLUTION})

target_link_libraries(main leetcode_lib)
