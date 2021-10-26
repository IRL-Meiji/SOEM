
set(SOURCES GoldTwitter_transmit.c)
add_executable(GoldTwitter_transmit ${SOURCES})
target_link_libraries(GoldTwitter_transmit soem)
install(TARGETS GoldTwitter_transmit DESTINATION bin)
