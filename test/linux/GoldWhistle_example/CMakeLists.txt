
set(SOURCES GoldWhistle_example.c)
add_executable(GoldWhistle_example ${SOURCES})
target_link_libraries(GoldWhistle_example soem)
install(TARGETS GoldWhistle_example DESTINATION bin)
