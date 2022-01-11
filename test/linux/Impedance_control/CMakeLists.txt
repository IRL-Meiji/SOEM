# PD_control
add_executable(Impedance_control Impedance_control.c)
target_link_libraries(Impedance_control soem m)
install(TARGETS Impedance_control DESTINATION bin)

