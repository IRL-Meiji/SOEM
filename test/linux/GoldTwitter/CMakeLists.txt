# read_motor
add_executable(read_motor read_motor.c)
target_link_libraries(read_motor soem)
install(TARGETS read_motor DESTINATION bin)


# position_control
add_executable(position_control position_control.c)
target_link_libraries(position_control soem m)
install(TARGETS position_control DESTINATION bin)


# test_program
add_executable(test_program test_program.c)
target_link_libraries(test_program soem)
install(TARGETS test_program DESTINATION bin)

# dualmotor_read
add_executable(dualmotor_read dualmotor_read.c)
target_link_libraries(dualmotor_read soem)
install(TARGETS dualmotor_read DESTINATION bin)
