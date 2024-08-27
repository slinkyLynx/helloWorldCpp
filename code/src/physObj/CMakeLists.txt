set(LIBRARY_NAME physObj)

add_library(${LIBRARY_NAME}
	STATIC
	ball.cpp
)

target_sources(${LIBRARY_NAME}
	PRIVATE
	ball.hpp
)

target_include_directories(${LIBRARY_NAME}
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)
