cmake_minimum_required(VERSION 3.14)

# These variables must be set BEFORE the project() call below.
set(CMAKE_OSX_DEPLOYMENT_TARGET
    "10.9"
    CACHE STRING "The minimum version of macOS able to run the extension")
set(CMAKE_OSX_ARCHITECTURES
    "arm64;x86_64"
    CACHE STRING "Target CPU architectures for macOS")

# Let's choose a name and version for the extension. Change the name to your
# liking. The version should be a string like "1.0".
set(PROJECT_NAME "HelloGP-CPP") # Change this to your liking
project(${PROJECT_NAME} VERSION 1.0)

# Import the SDK
include(FetchContent)
FetchContent_Declare(
  gp-sdk
  GIT_REPOSITORY https://github.com/gigperformer/gp-sdk.git
  GIT_TAG 6c5432518ef42ea0870fb44597e9d1d3780e2f98 # v44
)
FetchContent_MakeAvailable(gp-sdk)

# Define our library including sources, include directories and dependencies
add_library(${PROJECT_NAME} SHARED)
target_sources(
  ${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/LibMain.cpp"
                          "${CMAKE_CURRENT_LIST_DIR}/src/LibMain.h")
target_link_libraries(${PROJECT_NAME} PRIVATE gigperformer::sdk::cpp)
target_include_directories(${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Language options: this will be a pure C++20 project
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES CXX_STANDARD 20
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS NO)

# Let the compiler help us by enabling lots of diagnostics
if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang|GNU")
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC
      ")
  target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /MTd /W2 /c)
endif()

# Install the extension on the development machine
install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION "/Users/Shared/Gig Performer/Extensions"
  RUNTIME
    DESTINATION
      "$ENV{SystemDrive}\\Users\\Public\\Documents\\Gig Performer\\Extensions")
