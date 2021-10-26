
set(SOURCES GoldTwitter_Torque.c)
add_executable(GoldTwitter_Torque ${SOURCES})
target_link_libraries(GoldTwitter_Torque soem)
install(TARGETS GoldTwitter_Torque DESTINATION bin)
