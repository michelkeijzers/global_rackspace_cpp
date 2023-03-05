#include "WidgetIds.h"
#include "../Utilities/Debug.h"
#include "../View/Panes/OrganPane.h"
#include "../View/Panes/PrimaryKeyboardButtonsPane.h"
#include "../View/Panes/SlidersPane.h"
#include <map>

WidgetIds::WidgetIds()
{
}

/// <summary>
/// Filles vector and map, use same order as EWidgetId order.
/// </summary>
void WidgetIds::Fill()
{
    for (int drawbarSliderNumber = 1; drawbarSliderNumber <= OrganPane::NR_OF_DRAWBAR_SLIDERS; drawbarSliderNumber++)
    {
        _idToNames.push_back("OrganDrawbar" + std::to_string(drawbarSliderNumber));
        _nameToIds.insert(
            std::pair<std::string, EWidgetId>("OrganDrawbar" + std::to_string(drawbarSliderNumber),
                                              (EWidgetId)((int)EWidgetId::OrganDrawbar1 + drawbarSliderNumber - 1)));
    }

    _idToNames.push_back("OrganRotatorSpeedTextLabel");
    _nameToIds.insert(
        std::pair<std::string, EWidgetId>("OrganRotatorSpeedTextLabel", EWidgetId::OrganRotatorSpeedTextLabel));

    _idToNames.push_back("OrganDrive");
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrive", EWidgetId::OrganRotatorSpeedTextLabel));

    _idToNames.push_back("OrganReverbAmount");
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganReverbAmount", EWidgetId::OrganRotatorSpeedTextLabel));

    for (int sliderNumber = 1; sliderNumber <= SlidersPane::NR_OF_SLIDERS; sliderNumber++)
    {
        _idToNames.push_back("PrimaryKeyboardSlider" + std::to_string(sliderNumber));
        _nameToIds.insert(
            std::pair<std::string, EWidgetId>("PrimaryKeyboardSlider" + std::to_string(sliderNumber),
                                              (EWidgetId)((int)EWidgetId::PrimaryKeyboardSlider1 + sliderNumber - 1)));
    }
    for (int buttonNumber = 1; buttonNumber <= PrimaryKeyboardButtonsPane::NR_OF_BUTTONS; buttonNumber++)
    {
        _idToNames.push_back("PrimaryKeyboardButton" + std::to_string(buttonNumber));
        _nameToIds.insert(
            std::pair<std::string, EWidgetId>("PrimaryKeyboardButton" + std::to_string(buttonNumber),
                                              (EWidgetId)((int)EWidgetId::PrimaryKeyboardButton1 + buttonNumber - 1)));
    }

    Debug::Assert(_idToNames.size() == (int)WidgetIds::EWidgetId::Last, __FUNCTION__,
                  "Widget ID to Names list does not match");
    Debug::Assert(_nameToIds.size() == (int)WidgetIds::EWidgetId::Last, __FUNCTION__,
                  "Widget Name to IDs list does not match");
}

WidgetIds::EWidgetId WidgetIds::GetId(std::string name)
{
    return _nameToIds[name];
}

std::string WidgetIds::GetName(EWidgetId id)
{
    return _idToNames[(int)id];
}
