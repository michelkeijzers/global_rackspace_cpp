#include "WidgetIds.h"
#include "../Model/MixerSubModel.h"
#include "../Utilities/Debug.h"
#include "../View/Panes/OrganPane.h"
#include "../View/Panes/PrimaryKeyboardButtonsPane.h"
#include "../View/Panes/SlidersPane.h"
#include <map>
#include <vector>

WidgetIds::WidgetIds()
{
}

/// <summary>
/// Filles vector and map, use same order as EWidgetId order.
/// </summary>
void WidgetIds::Fill()
{
    FillSlidersPane();
    FillOrganPane();
    FillSetupChannelsPane();

    // Check if lists are of equal size.
    Debug::Assert(_idToNames.size() == (int)WidgetIds::EWidgetId::Last, __FUNCTION__,
                  "Widget ID to Names list does not match");
    Debug::Assert(_nameToIds.size() == (int)WidgetIds::EWidgetId::Last, __FUNCTION__,
                  "Widget Name to IDs list does not match");
}

void WidgetIds::FillSlidersPane()
{
    // Sliders pane
    for (int drawbarSliderNumber = 1; drawbarSliderNumber <= OrganPane::NR_OF_DRAWBAR_SLIDERS; drawbarSliderNumber++)
    {
        _idToNames.push_back("OrganDrawbar" + std::to_string(drawbarSliderNumber));
        _nameToIds.insert(
            std::pair<std::string, EWidgetId>("OrganDrawbar" + std::to_string(drawbarSliderNumber),
                                              (EWidgetId)((int)EWidgetId::OrganDrawbar1 + drawbarSliderNumber - 1)));
    }

    for (int sliderNumber = 1; sliderNumber <= SlidersPane::NR_OF_SLIDERS; sliderNumber++)
    {
        _idToNames.push_back("PrimaryKeyboardSlider" + std::to_string(sliderNumber));
        _nameToIds.insert(
            std::pair<std::string, EWidgetId>("PrimaryKeyboardSlider" + std::to_string(sliderNumber),
                                              (EWidgetId)((int)EWidgetId::PrimaryKeyboardSlider1 + sliderNumber - 1)));
    }

    for (int sliderNumber = 1; sliderNumber <= SlidersPane::NR_OF_SLIDERS; sliderNumber++)
    {
        const std::string widgetName = "PrimaryKeyboardSlider" + std::to_string(sliderNumber) + "Name";
        _idToNames.push_back(widgetName);
        _nameToIds.insert(std::pair<std::string, EWidgetId>(
            widgetName, (EWidgetId)((int)EWidgetId::PrimaryKeyboardSlider1Name + sliderNumber - 1)));
    }

    for (int sliderNumber = 1; sliderNumber <= SlidersPane::NR_OF_SLIDERS; sliderNumber++)
    {
        const std::string widgetName = "PrimaryKeyboardSlider" + std::to_string(sliderNumber) + "SourceName";
        _idToNames.push_back(widgetName);
        _nameToIds.insert(std::pair<std::string, EWidgetId>(
            widgetName, (EWidgetId)((int)EWidgetId::PrimaryKeyboardSlider1SourceName + sliderNumber - 1)));
    }
}

void WidgetIds::FillOrganPane()
{
    // Organ pane
    _idToNames.push_back("OrganRotatorSpeedTextLabel");
    _nameToIds.insert(
        std::pair<std::string, EWidgetId>("OrganRotatorSpeedTextLabel", EWidgetId::OrganRotatorSpeedTextLabel));

    _idToNames.push_back("OrganDrive");
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrive", EWidgetId::OrganRotatorSpeedTextLabel));

    _idToNames.push_back("OrganReverbAmount");
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganReverbAmount", EWidgetId::OrganRotatorSpeedTextLabel));

    // Primary Keyboard Buttons pane
    for (int buttonNumber = 1; buttonNumber <= PrimaryKeyboardButtonsPane::NR_OF_BUTTONS; buttonNumber++)
    {
        _idToNames.push_back("PrimaryKeyboardButton" + std::to_string(buttonNumber));
        _nameToIds.insert(
            std::pair<std::string, EWidgetId>("PrimaryKeyboardButton" + std::to_string(buttonNumber),
                                              (EWidgetId)((int)EWidgetId::PrimaryKeyboardButton1 + buttonNumber - 1)));
    }
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
        _nameToIds.insert(std::pair<std::string, EWidgetId>(
            widgetName, (EWidgetId)((int)EWidgetId::SetupChannel1Name + channelIndex)));
    }

    for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
    {
        const std::string widgetName = "SetupChannel" + std::to_string(channelIndex + 1) + "Number";
        _idToNames.push_back(widgetName);
        _nameToIds.insert(std::pair<std::string, EWidgetId>(
            widgetName, (EWidgetId)((int)EWidgetId::SetupChannel1Name + channelIndex)));
    }

    for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
    {
        const std::string widgetName = "SetupChannel" + std::to_string(channelIndex + 1) + "SourceName";
        _idToNames.push_back(widgetName);
        _nameToIds.insert(std::pair<std::string, EWidgetId>(
            widgetName, (EWidgetId)((int)EWidgetId::SetupChannel1SourceName + channelIndex)));
    }

    for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
    {
        const std::string widgetName = "SetupChannel" + std::to_string(channelIndex + 1) + "NextSourceButton";
        _idToNames.push_back(widgetName);
        _nameToIds.insert(std::pair<std::string, EWidgetId>(
            widgetName, (EWidgetId)((int)EWidgetId::SetupChannel1NextSourceButton + channelIndex)));
    }

    for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
    {
        const std::string widgetName = "SetupChannel" + std::to_string(channelIndex + 1) + "VolumeOverrideButton";
        _idToNames.push_back(widgetName);
        _nameToIds.insert(std::pair<std::string, EWidgetId>(
            widgetName, (EWidgetId)((int)EWidgetId::SetupChannel1VolumeOverrideButton + channelIndex)));
    }
}

void WidgetIds::FillSetupChannelWidget(const std::string &widgetName, int channelIndex)
{
    _idToNames.push_back(widgetName);
    _nameToIds.insert(std::pair<std::string, EWidgetId>(
        widgetName, (EWidgetId)((int)EWidgetId::SetupChannel1Name + channelIndex - 1)));
}

WidgetIds::EWidgetId WidgetIds::GetId(const std::string &name)
{
    return _nameToIds.find(name)->second;
}

std::string WidgetIds::GetName(EWidgetId id)
{
    return _idToNames[(int)id];
}
