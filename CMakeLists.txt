cmake_minimum_required(VERSION 3.21)

# Let's choose a name and version for the extension. Change the name to your
# liking. The version should be a string like "1.0".
set(PROJECT_NAME "LivePanelExtension")
project(${PROJECT_NAME} VERSION 0.1)

# Import the SDK
include(FetchContent)
FetchContent_Declare(
  gp-sdk
  GIT_REPOSITORY https://github.com/gigperformer/gp-sdk.git
  # GIT_TAG 6c5432518ef42ea0870fb44597e9d1d3780e2f98 # v44
  GIT_TAG 6d1b92fbb59fafbf47e38dd80f33d46692fb3425 # v51
)
FetchContent_MakeAvailable(gp-sdk)

# Define our library including sources, include directories and dependencies
add_library(${PROJECT_NAME} SHARED)
target_sources(
  ${PROJECT_NAME} PRIVATE  
   "${CMAKE_CURRENT_LIST_DIR}/src/LibMain.cpp"
   "${CMAKE_CURRENT_LIST_DIR}/src/LibMain.h" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Framework/MvcFramework.h" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Framework/MvcFramework.cpp" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Midi/MidiMessage.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Midi/MidiMessage.cpp"
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/MidiInBlock.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/MidiInBlock.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/MidiInBlocks.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/MidiInBlocks.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/AudioToCcMidiInBlock.h"
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/AudioToCcMidiInBlock.cpp"
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/PrimaryKeyboardMidiInBlock.cpp" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Model/MixerSubModel.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Model/MixerSubModel.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Model/MixerChannelSubModel.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Model/MixerChannelSubModel.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Model/Model.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Model/Model.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Model/SubModel.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Model/SubModel.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Model/SubModels.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Model/SubModels.cpp"
   "${CMAKE_CURRENT_LIST_DIR}/src/Model/OrganSubModel.h"
   "${CMAKE_CURRENT_LIST_DIR}/src/Model/OrganSubModel.cpp"
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/Plugins.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/Plugins.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/Plugin.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/Plugin.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/AudioMixerPlugin.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/AudioMixerPlugin.cpp" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Plugins/AudioToCcPlugin.h" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Plugins/AudioToCcPlugin.cpp" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Plugins/GainAndBalanceControlPlugin.h" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Plugins/GainAndBalanceControlPlugin.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/OrganPlugin.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/OrganPlugin.cpp"  
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/Debug.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/Debug.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/BoolUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/BoolUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/DoubleUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/DoubleUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/IntUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/IntUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/Controller.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/Controller.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/MixerSubController.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/MixerSubController.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/OrganSubController.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/OrganSubController.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/SubController.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/SubController.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/SubControllers.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/SubControllers.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/View.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/View.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/SubView.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/SubView.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/SubViews.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/SubViews.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/LiveSubView.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/LiveSubView.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/ChannelsSetupSubView.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/ChannelsSetupSubView.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/PluginsSetupSubView.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/PluginsSetupSubView.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/ChangedProperties.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/IObserver.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Observable.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/Pane.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/Pane.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/Panes.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/Panes.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/ChannelsSetupPane.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/ChannelsSetupPane.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/OrganPane.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/OrganPane.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/PrimaryKeyboardButtonsPane.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/PrimaryKeyboardButtonsPane.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/SlidersPane.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/SlidersPane.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/ButtonWidget.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/ButtonWidget.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/ShapeWidget.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/ShapeWidget.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/TextWidget.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/TextWidget.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/ValueWidget.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/ValueWidget.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/Widget.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/Widget.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/WidgetIds.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/WidgetIds.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/Widgets.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/Widgets.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/WidgetsListener.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Widgets/WidgetsListener.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE gigperformer::sdk::cpp)
target_include_directories(${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Language options: this will be a pure C++20 project
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES CXX_STANDARD 20
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS NO)

# Added by myself.
# Enable testing, see https://gitlab.kitware.com/cmake/community/-/wikis/doc/ctest/Testing-With-CTest
# enable_testing()
add_executable(tester tester.cpp)
#add_test(Tester tester)
target_link_libraries(tester PRIVATE ${PROJECT_NAME})

#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Install the extension on the development machine
install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION "${GIG_PERFORMER_EXTENSIONS_DIRECTORY}"
  RUNTIME DESTINATION "${GIG_PERFORMER_EXTENSIONS_DIRECTORY}")
