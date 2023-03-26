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

/* static */ WidgetIds::EWidgetId WidgetIds::GetSetupChannelName(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::SetupChannel1Name) + channelIndex);
}

/* static */ int WidgetIds::GetIndexOfSetupChannelName(WidgetIds::EWidgetId channelName)
{
   return static_cast<int>(channelName) - static_cast<int>(EWidgetId::SetupChannel1Name);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetSetupChannelNumber(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::SetupChannel1Number) + channelIndex);
}

/* static */ int WidgetIds::GetIndexOfSetupChannelNumber(WidgetIds::EWidgetId channelNumber)
{
   return static_cast<int>(channelNumber) - static_cast<int>(EWidgetId::SetupChannel1Number);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetSetupChannelSourceName(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::SetupChannel1SourceName) + channelIndex);
}

/* static */ int WidgetIds::GetIndexOfSetupChannelSourceName(WidgetIds::EWidgetId channelSourceName)
{
   return static_cast<int>(channelSourceName) - static_cast<int>(EWidgetId::SetupChannel1SourceName);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetSetupChannelNextSourceButton(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::SetupChannel1NextSourceButton) + channelIndex);
}

/* static */ int WidgetIds::GetIndexOfSetupChannelNextSourceButton(WidgetIds::EWidgetId channelIndex)
{
   return static_cast<int>(channelIndex) - static_cast<int>(EWidgetId::SetupChannel1NextSourceButton);
}

/* static */ WidgetIds::EWidgetId WidgetIds::GetSetupChannelVolumeOverrideButton(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too low");
   return static_cast<EWidgetId>(static_cast<int>(EWidgetId::SetupChannel1VolumeOverrideButton) + channelIndex);
}

/* static */ int WidgetIds::GetIndexOfSetupChannelVolumeOverrideButton(WidgetIds::EWidgetId channelIndex)
{
   return static_cast<int>(channelIndex) - static_cast<int>(EWidgetId::SetupChannel1VolumeOverrideButton);
}

/// <summary>
/// Filles vector and map, use same order as EWidgetId order.
/// </summary>
void WidgetIds::Fill()
{
   FillSlidersPane();
   FillOrganPane();
   FillFootPedalPane();
   FillSetupChannelsPane();
   FillSetupOrganPane();
   Debug::Assert(_idToNames.size() == static_cast<size_t>(WidgetIds::EWidgetId::Last), __FUNCTION__,
    "Widget ID to Names list does not match");
   Debug::Assert(_nameToIds.size() == static_cast<size_t>(WidgetIds::EWidgetId::Last), __FUNCTION__,
    "Widget Name to IDs list does not match");
}

void WidgetIds::FillSlidersPane()
{
   // Sliders pane
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

   // Primary Keyboard Buttons pane
   for (int buttonIndex = 0; buttonIndex < PrimaryKeyboardButtonsPane::NR_OF_BUTTONS; buttonIndex++)
   {
      const std::string widgetName = "PrimaryKeyboardButton" + std::to_string(buttonIndex + 1);
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetPrimaryKeyboardButton(buttonIndex)));
   }
}

void WidgetIds::FillFootPedalPane()
{
   _idToNames.push_back("LeftFootPedal");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("LeftFootPedal", EWidgetId::LeftFootPedal));
   _idToNames.push_back("RightFootPedal");
   _nameToIds.insert(std::pair<std::string, EWidgetId>("RightFootPedal", EWidgetId::RightFootPedal));
}

void WidgetIds::FillSetupChannelsPane()
{
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
      const std::string widgetName = "SetupChannel" + std::to_string(channelIndex + 1) + "Name";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetSetupChannelName(channelIndex)));
   }
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      const std::string widgetName = "SetupChannel" + std::to_string(channelIndex + 1) + "Number";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetSetupChannelNumber(channelIndex)));
   }
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      const std::string widgetName = "SetupChannel" + std::to_string(channelIndex + 1) + "SourceName";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetSetupChannelSourceName(channelIndex)));
   }
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      const std::string widgetName = "SetupChannel" + std::to_string(channelIndex + 1) + "NextSourceButton";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetSetupChannelNextSourceButton(channelIndex)));
   }
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      const std::string widgetName = "SetupChannel" + std::to_string(channelIndex + 1) + "VolumeOverrideButton";
      _idToNames.push_back(widgetName);
      _nameToIds.insert(
       std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetSetupChannelVolumeOverrideButton(channelIndex)));
   }
}

void WidgetIds::FillSetupChannelWidget(const std::string &widgetName, int channelIndex)
{
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, WidgetIds::GetSetupChannelName(channelIndex)));
}

void WidgetIds::FillSetupOrganPane()
{
   std::string widgetName;
   widgetName = "SetupOrganPaneBox";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::SetupOrganPaneBox));
   widgetName = "SetupOrganTitleTextLabel";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::SetupOrganTitleTextLabel));
   widgetName = "SetupOrganPrimaryKeyboardActiveButton";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::SetupOrganPrimaryKeyboardActiveButton));
   widgetName = "SetupOrganSecondaryKeyboardActiveButton";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::SetupOrganSecondaryKeyboardActiveButton));
   widgetName = "SetupOrganLowestNoteSlider";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::SetupOrganLowestNoteSlider));
   widgetName = "SetupOrganHighestNoteSlider";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::SetupOrganHighestNoteSlider));
   widgetName = "SetupOrganLowestNoteTextLabel";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::SetupOrganLowestNoteTextLabel));
   widgetName = "SetupOrganHighestNoteTextLabel";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::SetupOrganHighestNoteTextLabel));
   widgetName = "SetupOrganSustainPedalActiveButton";
   _idToNames.push_back(widgetName);
   _nameToIds.insert(std::pair<std::string, EWidgetId>(widgetName, EWidgetId::SetupOrganSustainPedalActiveButton));
}

WidgetIds::EWidgetId WidgetIds::GetId(const std::string &name)
{
   auto iterator = _nameToIds.find(name);
   Debug::Assert(iterator != _nameToIds.end(), __FUNCTION__, "Widget " + name + " not found");
   return iterator->second;
}

std::string WidgetIds::GetName(EWidgetId id) { return _idToNames[static_cast<int>(id)]; }
