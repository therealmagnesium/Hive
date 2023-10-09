file(GLOB_RECURSE SRC_FILES "source/*.cpp")
add_executable("SandboxApp" "${SRC_FILES}")

target_include_directories("SandboxApp" PUBLIC "${CMAKE_SOURCE_DIR}/Hive/source")

target_link_directories("SandboxApp" PRIVATE "${CMAKE_SOURCE_DIR}/build/Hive")
target_link_libraries("SandboxApp" PRIVATE "Hive")
