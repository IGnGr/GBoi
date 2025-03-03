add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE GBoi.cpp GBoi.h)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)