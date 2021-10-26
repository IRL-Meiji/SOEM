# read_motor
add_executable(read_motor read_motor.c)
target_link_libraries(read_motor soem)
install(TARGETS read_motor DESTINATION bin)


# position_control
add_executable(position_control position_control.c)
target_link_libraries(position_control soem)
install(TARGETS position_control DESTINATION bin)
