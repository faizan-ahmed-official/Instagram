cmake_minimum_required(VERSION 3.16)

project(INSTAGRAM VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Network Gui Sql)

set (SOURCES 
    src/InstaNavBar.cpp
    src/InstaStories.cpp
    src/InstaStory.cpp
    src/InstaHeader.cpp
    src/InstaPostDelegate.cpp
    src/ScrollBar.cpp
    src/Instagram.cpp
    src/core/Database.cpp
    src/core/Database.h
)

set(HEADERS
    include/ScrollBar.h
    include/InstaNavBar.h
    include/InstaPostDelegate.h
    include/InstaPostRoles.h
    include/InstaStories.h
    include/InstaStory.h
    include/InstaHeader.h
    include/Instagram.h
)

add_executable(INSTAGRAM
    main.cpp
    resources/resources.qrc
    app.rc
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(
    INSTAGRAM PRIVATE
    Qt6::Core
    Qt6::Network
    Qt6::Gui
    Qt6::Widgets
    Qt6::Sql
)

set_target_properties(INSTAGRAM PROPERTIES WIN32_EXECUTABLE TRUE)