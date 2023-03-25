cmake_minimum_required(VERSION 3.21)

# language standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED YES)
set(CMAKE_C_EXTENSIONS NO)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Let's choose a name and version for the extension. Change the name to your
# liking. The version should be a string like "1.0".
set(PROJECT_NAME "MK_GlobalRackExtension")
project(${PROJECT_NAME} VERSION 0.1)

include("${CMAKE_CURRENT_LIST_DIR}/cmake/dependencies.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake/juce-shared-library.cmake")

# Define our library including sources, include directories and dependencies
juce_add_shared_library(${PROJECT_NAME})
target_sources(
  ${PROJECT_NAME} 
   PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/LibMain.cpp"
   "${CMAKE_CURRENT_LIST_DIR}/src/LibMain.h" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Framework/MvcFramework.h" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Framework/MvcFramework.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/MidiInBlock.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/MidiInBlock.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/MidiInBlocks.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/MidiInBlocks.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/AudioToCcMidiInBlock.h"
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/AudioToCcMidiInBlock.cpp"
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/PrimaryKeyboardMidiInBlock.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/SecondaryKeyboardMidiInBlock.h"
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/SecondaryKeyboardMidiInBlock.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/FootBoardMidiInBlock.h"
   "${CMAKE_CURRENT_LIST_DIR}/src/MidiInBlocks/FootBoardMidiInBlock.cpp" 
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
   "${CMAKE_CURRENT_LIST_DIR}/src/Model/KeyboardSubModel.h"
   "${CMAKE_CURRENT_LIST_DIR}/src/Model/KeyboardSubModel.cpp"
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/Plugins.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/Plugins.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/Plugin.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/Plugin.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/ExpressionAudioMixerPlugin.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/ExpressionAudioMixerPlugin.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/AudioMixerPlugin.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/AudioMixerPlugin.cpp" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Plugins/AudioToCcPlugin.h" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Plugins/AudioToCcPlugin.cpp" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Plugins/GainAndBalanceControlPlugin.h" 
	"${CMAKE_CURRENT_LIST_DIR}/src/Plugins/GainAndBalanceControlPlugin.cpp" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/OrganPlugin.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/OrganPlugin.cpp"  
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/KeyboardPlugin.h" 
   "${CMAKE_CURRENT_LIST_DIR}/src/Plugins/KeyboardPlugin.cpp"  
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/Debug.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/Debug.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/BoolUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/BoolUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/ColorUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/ColorUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/DoubleUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/DoubleUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/IntUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/IntUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/StringUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/StringUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/VectorUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/VectorUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/MidiUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/MidiUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/SerializationUtilities.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Utilities/SerializationUtilities.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/Controller.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/Controller.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/WindowSubController.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/WindowSubController.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/MixerSubController.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/MixerSubController.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/OrganSubController.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/OrganSubController.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/KeyboardSubController.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/Controller/KeyboardSubController.cpp"
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
	"${CMAKE_CURRENT_LIST_DIR}/src/View/ChangedProperties.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/IObserver.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Observable.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/Pane.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/Pane.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/Panes.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/Panes.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/ChannelsSetupPane.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/ChannelsSetupPane.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/OrganSetupPane.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/OrganSetupPane.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/OrganPane.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/OrganPane.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/PrimaryKeyboardButtonsPane.h"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/PrimaryKeyboardButtonsPane.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/FootBoardPane.cpp"
   "${CMAKE_CURRENT_LIST_DIR}/src/View/Panes/FootBoardPane.cpp"
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
target_link_libraries(
  ${PROJECT_NAME} PRIVATE gigperformer::sdk::cpp juce::juce_audio_basics
                          gigperformer::sdk::cpp juce::juce_gui_basics
                          juce::juce_core juce::juce_events juce::juce_graphics)
target_include_directories(${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_definitions(
  ${PROJECT_NAME} PRIVATE "JUCER_ENABLE_GPL_MODE=1"
                          "JUCE_DISPLAY_SPLASH_SCREEN=0")

# Install the extension on the development machine
install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION "${GIG_PERFORMER_EXTENSIONS_DIRECTORY}"
  RUNTIME DESTINATION "${GIG_PERFORMER_EXTENSIONS_DIRECTORY}")
