
set(SOURCES HogeSlave.c)
add_executable(HogeSlave ${SOURCES})
target_link_libraries(HogeSlave soem)
install(TARGETS HogeSlave DESTINATION bin)
