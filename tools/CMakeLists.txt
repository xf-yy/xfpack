include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(xfpack_example example.cpp)
target_link_libraries(xfpack_example xfpack pthread)


