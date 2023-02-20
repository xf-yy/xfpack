include_directories("./pack")

aux_source_directory("./pack" pack_srcs)

add_library(${PROJECT_NAME} SHARED ${pack_srcs})
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${xfpack_VERSION_MAJOR}.${xfpack_VERSION_MINOR} SOVERSION ${xfpack_VERSION_MAJOR})

target_link_libraries(${PROJECT_NAME} pthread)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

