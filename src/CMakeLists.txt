add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE "GBoi.cpp" "GBoi.h" "GameROM.h" "GameROM.cpp" "CPU.cpp" "CPU.h" "Utils.h" "Utils.cpp"   "InstructionSet.cpp" "InstructionSet.h" "MMU.h" "MMU.cpp"  )
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)