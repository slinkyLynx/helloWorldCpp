set(EXECUTABLE_NAME helloWorldCpp)

find_package(glm CONFIG REQUIRED)

add_executable(${EXECUTABLE_NAME}
	main.cpp
)

# Move ball.*pp to a physObj library

target_sources(${EXECUTABLE_NAME}
	PUBLIC
	ball.cpp
	PRIVATE
	ball.hpp
)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE glm::glm)
