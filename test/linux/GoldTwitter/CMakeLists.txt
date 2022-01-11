# read_motor
add_executable(read_motor read_motor.c)
target_link_libraries(read_motor soem)
install(TARGETS read_motor DESTINATION bin)

# torque_control
add_executable(torque_control torque_control.c)
target_link_libraries(torque_control soem)
install(TARGETS torque_control DESTINATION bin)

# test_program
add_executable(test_program test_program.c)
target_link_libraries(test_program soem)
install(TARGETS test_program DESTINATION bin)

# PD_control
add_executable(PD_control PD_control.c)
target_link_libraries(PD_control soem m)
install(TARGETS PD_control DESTINATION bin)

# dualmotor_read
add_executable(dualmotor_read dualmotor_read.c)
target_link_libraries(dualmotor_read soem)
install(TARGETS dualmotor_read DESTINATION bin)

