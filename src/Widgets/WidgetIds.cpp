#include "WidgetIds.h"
#include "../Model/MixerSubModel.h"
#include "../Utilities/Debug.h"
#include "../View/Panes/OrganPane.h"
#include "../View/Panes/PrimaryKeyboardButtonsPane.h"
#include "../View/Panes/SlidersPane.h"
#include <map>
#include <vector>

WidgetIds::WidgetIds() {}

/* static */ WidgetIds::EWidgetId WidgetIds::GetOrganDrawbar(int organDrawbarIndex)
{
   Debug::Assert(organDrawbarIndex >= 0, __FUNCTION__, "organDrawbarIndex too low");
   Debug::Assert(organDrawbarIndex < SlidersPane::NR_OF_SLIDERS, __FUNCTION__, "organDrawbarIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::OrganDrawbar1) + organDrawbarIndex);
}

/* static */ int WidgetIds::GetIndexOfOrganDrawbar(EWidgetId slider)
{
   return static_cast<int>(slider) - static_cast<int>(EWidgetId::OrganDrawbar1);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetPrimaryKeyboardSliderBox(int boxIndex)
{
   Debug::Assert(boxIndex >= 0, __FUNCTION__, "boxIndex too low");
   Debug::Assert(boxIndex < SlidersPane::NR_OF_SLIDERS, __FUNCTION__, "boxIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::PrimaryKeyboardSliderBox1) + boxIndex);
}

/* static */ int WidgetIds::GetIndexOfPrimaryKeyboardSliderBox(WidgetIds::EWidgetId box)
{
   return static_cast<int>(box) - static_cast<int>(EWidgetId::PrimaryKeyboardSliderBox1);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetPrimaryKeyboardSliderNumber(int numberIndex)
{
   Debug::Assert(numberIndex >= 0, __FUNCTION__, "numberIndex too low");
   Debug::Assert(numberIndex < SlidersPane::NR_OF_SLIDERS, __FUNCTION__, "numberIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::PrimaryKeyboardSliderNumber1) + numberIndex);
}

/* static */ int WidgetIds::GetIndexOfPrimaryKeyboardSliderNumber(WidgetIds::EWidgetId box)
{
   return static_cast<int>(box) - static_cast<int>(EWidgetId::PrimaryKeyboardSliderNumber1);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetPrimaryKeyboardSlider(int sliderIndex)
{
   Debug::Assert(sliderIndex >= 0, __FUNCTION__, "sliderIndex too low");
   Debug::Assert(sliderIndex < SlidersPane::NR_OF_SLIDERS, __FUNCTION__, "sliderIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::PrimaryKeyboardSlider1) + sliderIndex);
}

/* static */ int WidgetIds::GetIndexOfPrimaryKeyboardSlider(WidgetIds::EWidgetId slider)
{
   return static_cast<int>(slider) - static_cast<int>(EWidgetId::PrimaryKeyboardSlider1);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetPrimaryKeyboardSliderLevelLeft(int sliderIndex)
{
   Debug::Assert(sliderIndex >= 0, __FUNCTION__, "sliderIndex too low");
   Debug::Assert(sliderIndex < SlidersPane::NR_OF_SLIDERS, __FUNCTION__, "sliderIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::PrimaryKeyboardSlider1LevelLeft) + sliderIndex);
}

/* static */ int WidgetIds::GetIndexOfPrimaryKeyboardSliderLevelLeft(WidgetIds::EWidgetId slider)
{
   return static_cast<int>(slider) - static_cast<int>(EWidgetId::PrimaryKeyboardSlider1LevelLeft);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetPrimaryKeyboardSliderLevelRight(int sliderIndex)
{
   Debug::Assert(sliderIndex >= 0, __FUNCTION__, "sliderIndex too low");
   Debug::Assert(sliderIndex < SlidersPane::NR_OF_SLIDERS, __FUNCTION__, "sliderIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::PrimaryKeyboardSlider1LevelRight) + sliderIndex);
}

/* static */ int WidgetIds::GetIndexOfPrimaryKeyboardSliderLevelRight(WidgetIds::EWidgetId slider)
{
   return static_cast<int>(slider) - static_cast<int>(EWidgetId::PrimaryKeyboardSlider1LevelRight);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetPrimaryKeyboardSliderName(int sliderIndex)
{
   Debug::Assert(sliderIndex >= 0, __FUNCTION__, "sliderIndex too low");
   Debug::Assert(sliderIndex < SlidersPane::NR_OF_SLIDERS, __FUNCTION__, "sliderIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::PrimaryKeyboardSlider1Name) + sliderIndex);
}

/* static */ int WidgetIds::GetIndexOfPrimaryKeyboardSliderName(WidgetIds::EWidgetId slider)
{
   return static_cast<int>(slider) - static_cast<int>(EWidgetId::PrimaryKeyboardSlider1Name);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetPrimaryKeyboardSliderSourceName(int sliderIndex)
{
   Debug::Assert(sliderIndex >= 0, __FUNCTION__, "sliderIndex too low");
   Debug::Assert(sliderIndex < SlidersPane::NR_OF_SLIDERS, __FUNCTION__, "sliderIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::PrimaryKeyboardSlider1SourceName) + sliderIndex);
}

/* static */ int WidgetIds::GetIndexOfPrimaryKeyboardSliderSourceName(WidgetIds::EWidgetId slider)
{
   return static_cast<int>(slider) - static_cast<int>(EWidgetId::PrimaryKeyboardSlider1SourceName);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetPrimaryKeyboardButton(int buttonIndex)
{
   Debug::Assert(buttonIndex >= 0, __FUNCTION__, "buttonIndex too low");
   Debug::Assert(buttonIndex < PrimaryKeyboardButtonsPane::NR_OF_BUTTONS, __FUNCTION__, "buttonIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::PrimaryKeyboardButton1) + buttonIndex);
}

/* static */ int WidgetIds::GetIndexOfPrimaryKeyboardButton(WidgetIds::EWidgetId button)
{
   return static_cast<int>(button) - static_cast<int>(EWidgetId::PrimaryKeyboardButton1);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetPrimaryKeyboardKnob(int knobIndex)
{
   Debug::Assert(knobIndex >= 0, __FUNCTION__, "knobIndex too low");
   Debug::Assert(knobIndex < PrimaryKeyboardButtonsPane::NR_OF_KNOBS, __FUNCTION__, "knobIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::PrimaryKeyboardKnob1) + knobIndex);
}

/* static */ int WidgetIds::GetIndexOfPrimaryKeyboardKnob(WidgetIds::EWidgetId knob)
{
   return static_cast<int>(knob) - static_cast<int>(EWidgetId::PrimaryKeyboardKnob1);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetChannelsSetupName(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::ChannelsSetup1Name) + channelIndex);
}

/* static */ int WidgetIds::GetIndexOfChannelsSetupName(WidgetIds::EWidgetId channelName)
{
   return static_cast<int>(channelName) - static_cast<int>(EWidgetId::ChannelsSetup1Name);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetChannelsSetupNumber(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::ChannelsSetup1Number) + channelIndex);
}

/* static */ int WidgetIds::GetIndexOfChannelsSetupNumber(WidgetIds::EWidgetId channelNumber)
{
   return static_cast<int>(channelNumber) - static_cast<int>(EWidgetId::ChannelsSetup1Number);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetChannelsSetupSourceName(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::ChannelsSetup1SourceName) + channelIndex);
}

/* static */ int WidgetIds::GetIndexOfChannelsSetupSourceName(WidgetIds::EWidgetId channelSourceName)
{
   return static_cast<int>(channelSourceName) - static_cast<int>(EWidgetId::ChannelsSetup1SourceName);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetChannelsSetupNextSourceButton(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::ChannelsSetup1NextSourceButton) + channelIndex);
}

/* static */ int WidgetIds::GetIndexOfChannelsSetupNextSourceButton(WidgetIds::EWidgetId channelIndex)
{
   return static_cast<int>(channelIndex) - static_cast<int>(EWidgetId::ChannelsSetup1NextSourceButton);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetChannelsSetupVolumeOverrideButton(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::ChannelsSetup1VolumeOverrideButton) + channelIndex);
}

/* static */ int WidgetIds::GetIndexOfChannelsSetupVolumeOverrideButton(WidgetIds::EWidgetId channelIndex)
{
   return static_cast<int>(channelIndex) - static_cast<int>(EWidgetId::ChannelsSetup1VolumeOverrideButton);
}

/// <summary>
/// Filles vector and map, use same order as EWidgetId order.
/// </summary>
void WidgetIds::Fill()
{
   FillSlidersPane();
   FillOrganPane();
   FillPrimaryKeyboardButtonsPane();
   FillFootBoardPane();
   FillChannelsSetupPane();
   FillOrganSetupPane();
   Debug::Assert(_idToNames.size() == static_cast<size_t>(WidgetIds::EWidgetId::Last), __FUNCTION__,
    "Widget ID to Names list does not match");
   Debug::Assert(_nameToIds.size() == static_cast<size_t>(WidgetIds::EWidgetId::Last), __FUNCTION__,
    "Widget Name to IDs list does not match");
}

void WidgetIds::FillSlidersPane()
{
   _idToNames.push_back("SlidersPaneBox");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("SlidersPaneBox", EWidgetId::SlidersPaneBox));
   _idToNames.push_back("SlidersPaneTitleTextLabel");
   _nameToIds.insert(
    std::pair<std::string, EWidgetId>("SlidersPaneTitleTextLabel", EWidgetId::SlidersPaneTitleTextLabel));
   _idToNames.push_back("SlidersPaneTabOrgan");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("SlidersPaneTabOrgan", EWidgetId::SlidersPaneBox));
   _idToNames.push_back("SlidersPaneTabChannels1To8");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("SlidersPaneTabChannels1To8", EWidgetId::SlidersPaneBox));
   _idToNames.push_back("SlidersPaneTabChannels9To16");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("SlidersPaneTabChannels9To16", EWidgetId::SlidersPaneBox));
   _idToNames.push_back("SlidersPaneTabChannels16To24");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("SlidersPaneTabChannels16To24", EWidgetId::SlidersPaneBox));
   for (int drawbarIndex = 0; drawbarIndex < OrganPane::NR_OF_DRAWBAR_SLIDERS; drawbarIndex++)
   {
      std::string widgetName = "OrganDrawbar" + std::to_string(drawbarIndex + 1);
      _idToNames.push_back(widgetName);
      _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetOrganDrawbar(drawbarIndex)));
   }
   for (int sliderIndex = 0; sliderIndex < SlidersPane::NR_OF_SLIDERS; sliderIndex++)
   {
      std::string widgetName = "PrimaryKeyboardSlider" + std::to_string(sliderIndex + 1) + "Box";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetPrimaryKeyboardSliderBox(sliderIndex)));
   }
   for (int sliderIndex = 0; sliderIndex < SlidersPane::NR_OF_SLIDERS; sliderIndex++)
   {
      std::string widgetName = "PrimaryKeyboardSlider" + std::to_string(sliderIndex + 1) + "Number";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetPrimaryKeyboardSliderBox(sliderIndex)));
   }
   for (int sliderIndex = 0; sliderIndex < SlidersPane::NR_OF_SLIDERS; sliderIndex++)
   {
      std::string widgetName = "PrimaryKeyboardSlider" + std::to_string(sliderIndex + 1);
      _idToNames.push_back(widgetName);
      _nameToIds.insert(std::pair<std::string, EWidgetId>(
       "PrimaryKeyboardSlider" + std::to_string(sliderIndex + 1), WidgetIds::GetPrimaryKeyboardSlider(sliderIndex)));
   }
   for (int sliderIndex = 0; sliderIndex < SlidersPane::NR_OF_SLIDERS; sliderIndex++)
   {
      std::string widgetName = "PrimaryKeyboardSlider" + std::to_string(sliderIndex + 1) + "LevelLeft";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetPrimaryKeyboardSliderLevelLeft(sliderIndex)));
   }
   for (int sliderIndex = 0; sliderIndex < SlidersPane::NR_OF_SLIDERS; sliderIndex++)
   {
      std::string widgetName = "PrimaryKeyboardSlider" + std::to_string(sliderIndex + 1) + "LevelRight";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetPrimaryKeyboardSliderLevelRight(sliderIndex)));
   }
   for (int sliderIndex = 0; sliderIndex < SlidersPane::NR_OF_SLIDERS; sliderIndex++)
   {
      const std::string widgetName = "PrimaryKeyboardSlider" + std::to_string(sliderIndex + 1) + "Name";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetPrimaryKeyboardSliderName(sliderIndex)));
   }
   for (int sliderIndex = 0; sliderIndex < SlidersPane::NR_OF_SLIDERS; sliderIndex++)
   {
      const std::string widgetName = "PrimaryKeyboardSlider" + std::to_string(sliderIndex + 1) + "SourceName";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetPrimaryKeyboardSliderSourceName(sliderIndex)));
   }
}

 void WidgetIds::FillOrganPane()
{
   _idToNames.push_back("OrganPaneBox");
   _nameToIds.insert(
    std::pair<std::string, EWidgetId>("OrganPaneBox", EWidgetId::OrganPaneBox));
   _idToNames.push_back("OrganPaneTitleTextLabel");
   _nameToIds.insert(
    std::pair<std::string, EWidgetId>("OrganPaneTitleTextLabel", EWidgetId::OrganPaneTitleTextLabel));
   _idToNames.push_back("OrganRotatorSpeedTextLabel");
   _nameToIds.insert(
    std::pair<std::string, EWidgetId>("OrganRotatorSpeedTextLabel", EWidgetId::OrganRotatorSpeedTextLabel));
   _idToNames.push_back("OrganDriveTextLabel");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDriveTextLabel", EWidgetId::OrganRotatorSpeedTextLabel));
   _idToNames.push_back("OrganReverbAmountTextLabel");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganReverbAmountTextLabel", EWidgetId::OrganRotatorSpeedTextLabel));
}

void WidgetIds::FillPrimaryKeyboardButtonsPane()
{
   _idToNames.push_back("PrimaryKeyboardButtonsPaneBox");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButtonsPaneBox", EWidgetId::OrganPaneBox));
   _idToNames.push_back("PrimaryKeyboardButtonsPaneTitleTextLabel");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButtonsPaneTitleTextLabel", EWidgetId::OrganPaneTitleTextLabel));
   for (int buttonIndex = 0; buttonIndex < PrimaryKeyboardButtonsPane::NR_OF_VISIBLE_BUTTONS; buttonIndex++)
   {
      const std::string widgetName = "PrimaryKeyboardButton" + std::to_string(buttonIndex + 1);
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetPrimaryKeyboardButton(buttonIndex)));
   }
   for (int knobIndex = 0; knobIndex < PrimaryKeyboardButtonsPane::NR_OF_KNOBS; knobIndex++)
   {
      const std::string widgetName = "PrimaryKeyboardKnob" + std::to_string(knobIndex + 1);
      _idToNames.push_back(widgetName);
      _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetPrimaryKeyboardKnob(knobIndex)));
   }
}

void WidgetIds::FillFootBoardPane()
{
   _idToNames.push_back("FootBoardPaneBox");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("FootBoardPaneBox", EWidgetId::FootBoardPaneBox));
   _idToNames.push_back("FootBoardPaneTitleTextLabel");
   _nameToIds.insert(
    std::pair<std::string, EWidgetId>("FootBoardPaneTitleTextLabel", EWidgetId::FootBoardPaneTitleTextLabel));
   _idToNames.push_back("LeftFootPedal");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("LeftFootPedal", EWidgetId::LeftFootPedal));
   _idToNames.push_back("RightFootPedal");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("RightFootPedal", EWidgetId::RightFootPedal));
}

void WidgetIds::FillChannelsSetupPane()
{
   _idToNames.push_back("ChannelsSetupPaneBox");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("ChannelsSetupPaneBox", EWidgetId::ChannelsSetupPaneBox));
   _idToNames.push_back("ChannelsSetupPaneTitleTextLabel");
   _nameToIds.insert(
    std::pair<std::string, EWidgetId>("ChannelsSetupPaneTitleTextLabel", EWidgetId::FootBoardPaneTitleTextLabel));
   _idToNames.push_back("SyncLabelsToMixerButton");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("SyncLabelsToMixerButton", EWidgetId::SyncLabelsToMixerButton));
   _idToNames.push_back("ChannelIndexTextLabel");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("ChannelIndexTextLabel", EWidgetId::ChannelIndexTextLabel));
   _idToNames.push_back("NextSourceTextLabel");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("NextSourceTextLabel", EWidgetId::NextSourceTextLabel));
   _idToNames.push_back("VolumeOverrideTextLabel");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("VolumeOverrideTextLabel", EWidgetId::VolumeOverrideTextLabel));
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      const std::string widgetName = "ChannelsSetup" + std::to_string(channelIndex + 1) + "Name";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetChannelsSetupName(channelIndex)));
   }
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      const std::string widgetName = "ChannelsSetup" + std::to_string(channelIndex + 1) + "Number";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetChannelsSetupNumber(channelIndex)));
   }
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      const std::string widgetName = "ChannelsSetup" + std::to_string(channelIndex + 1) + "SourceName";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetChannelsSetupSourceName(channelIndex)));
   }
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      const std::string widgetName = "ChannelsSetup" + std::to_string(channelIndex + 1) + "NextSourceButton";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetChannelsSetupNextSourceButton(channelIndex)));
   }
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      const std::string widgetName = "ChannelsSetup" + std::to_string(channelIndex + 1) + "VolumeOverrideButton";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetChannelsSetupVolumeOverrideButton(channelIndex)));
   }
}

void WidgetIds::FillOrganSetupPane()
{
   std::string widgetName;
   widgetName = "OrganSetupPaneBox";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::OrganSetupPaneBox));
   widgetName = "OrganSetupPaneTitleTextLabel";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::OrganSetupPaneTitleTextLabel));
   widgetName = "OrganSetupPrimaryKeyboardActiveButton";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::OrganSetupPrimaryKeyboardActiveButton));
   widgetName = "OrganSetupSecondaryKeyboardActiveButton";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::OrganSetupSecondaryKeyboardActiveButton));
   widgetName = "OrganSetupLowestNoteSlider";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::OrganSetupLowestNoteSlider));
   widgetName = "OrganSetupHighestNoteSlider";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::OrganSetupHighestNoteSlider));
   widgetName = "OrganSetupLowestNoteTextLabel";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::OrganSetupLowestNoteTextLabel));
   widgetName = "OrganSetupHighestNoteTextLabel";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::OrganSetupHighestNoteTextLabel));
   widgetName = "OrganSetupSustainPedalActiveButton";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::OrganSetupSustainPedalActiveButton));
}

WidgetIds::EWidgetId WidgetIds::GetId(const std::string &name)
{
   auto iterator = _nameToIds.find(name);
   Debug::Assert(iterator != _nameToIds.end(), __FUNCTION__, "Widget " + name + " not found");
   return iterator->second;
}

std::string WidgetIds::GetName(EWidgetId id) { return _idToNames[static_cast<int>(id)]; }
