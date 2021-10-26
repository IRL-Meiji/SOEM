
set(SOURCES position_control.c)
add_executable(position_control ${SOURCES})
target_link_libraries(position_control soem)
install(TARGETS position_control DESTINATION bin)
