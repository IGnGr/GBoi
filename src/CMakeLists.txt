add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE "GBoi.cpp" "GBoi.h" "../include/GameROM.h" "GameROM.cpp" "CPU.cpp" "../include/CPU.h" "../include/Utils.h" "Utils.cpp"   "InstructionSet.cpp" "../include/InstructionSet.h" "../include/MMU.h" "MMU.cpp"  "../include/MBC.h" "MBC.cpp" "PPU.cpp" "../include/PPU.h")
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)