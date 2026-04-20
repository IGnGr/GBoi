add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE "GBoi.cpp" "GBoi.h" "GameROM.cpp" "CPU.cpp" "Utils.cpp"   "InstructionSet.cpp" "MMU.cpp" "MBC.cpp" "PPU.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)