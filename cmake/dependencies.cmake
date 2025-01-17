include(FetchContent)

function(fetch_dependency name)
  FetchContent_GetProperties(${name})
  if(NOT ${name}_POPULATED)
    message(STATUS "Fetching and configuring ${name}...")
    list(APPEND CMAKE_MESSAGE_INDENT "  ")

    FetchContent_Populate(${name})
    add_subdirectory(
      ${${name}_SOURCE_DIR}
      ${${name}_BINARY_DIR}
      # we have to set EXCLUDE_FROM_ALL so that dependent targets are not
      # included into the install trees.
      EXCLUDE_FROM_ALL)

    list(POP_BACK CMAKE_MESSAGE_INDENT)
  endif()
endfunction(fetch_dependency)

FetchContent_Declare(
  gp-sdk
  GIT_REPOSITORY https://github.com/gigperformer/gp-sdk.git
  # GIT_TAG origin/beta
  GIT_TAG 6d1b92fbb59fafbf47e38dd80f33d46692fb3425 # v51
  #SOURCE_DIR C:/Users/fdenb/source/repos/gpextensions/gp-sdk.4.6
  # GIT_TAG 39ab2d1aae8194b4c6a11e899360f1d925a25d5c fix 2
  # GIT_TAG f6b1ad94a3af83afd269a327e93ddc6cf94cb1b1
)
FetchContent_MakeAvailable(gp-sdk)
fetch_dependency(gp-sdk)

FetchContent_Declare(
  juce
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG 2f980209cc4091a4490bb1bafc5d530f16834e58 # v6.1.6
)
fetch_dependency(juce)
