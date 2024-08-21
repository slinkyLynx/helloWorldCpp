set(EXECUTABLE_NAME helloWorldCpp)

find_package(glm CONFIG REQUIRED)

add_executable(${EXECUTABLE_NAME}
	test.cpp
	main.cpp
	)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE glm::glm)
