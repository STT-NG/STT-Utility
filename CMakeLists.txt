set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB HEADERS include/*.h)
file(GLOB SOURCES src/*.cpp)

source_group("Library Source Files" FILES ${SOURCES})
source_group("Library Header Files" FILES ${HEADERS})

add_library(STTUtil STATIC
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(STTUtil GeomRel)

target_include_directories(STTUtil PUBLIC include/)

install(TARGETS STTUtil DESTINATION lib)
