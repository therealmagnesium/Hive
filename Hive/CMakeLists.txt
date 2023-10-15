file(GLOB_RECURSE SRC_FILES "source/Hive/*.cpp" "source/Platform/*.cpp")
add_library("Hive" "${SRC_FILES}")

target_include_directories("Hive" PUBLIC "${CMAKE_SOURCE_DIR}/vendor/raylib/src")
target_include_directories("Hive" PUBLIC "${CMAKE_SOURCE_DIR}/vendor/entt/include")
target_include_directories("Hive" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/source/Hive")
target_include_directories("Hive" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/source/Platform")

target_link_directories("Hive" PRIVATE "${CMAKE_SOURCE_DIR}/build/vendor/raylib/src")
target_link_libraries("Hive" PRIVATE "raylib")
