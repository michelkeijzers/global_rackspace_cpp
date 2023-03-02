#include "WidgetIds.h"
#include "../Utilities/Debug.h"
#include <map>

WidgetIds::WidgetIds()
{
}

/// <summary>
/// Filles vector and map, use same order as EWidgetId order.
/// </summary>
void WidgetIds::Fill()
{
    _idToNames.push_back("OrganDrawbar1");
    _idToNames.push_back("OrganDrawbar2");
    _idToNames.push_back("OrganDrawbar3");
    _idToNames.push_back("OrganDrawbar4");
    _idToNames.push_back("OrganDrawbar5");
    _idToNames.push_back("OrganDrawbar6");
    _idToNames.push_back("OrganDrawbar7");
    _idToNames.push_back("OrganDrawbar8");
    _idToNames.push_back("OrganDrawbar9");

    _idToNames.push_back("OrganRotatorSpeedTextLabel");

    _idToNames.push_back("PrimaryKeyboardSlider1");
    _idToNames.push_back("PrimaryKeyboardSlider2");
    _idToNames.push_back("PrimaryKeyboardSlider3");
    _idToNames.push_back("PrimaryKeyboardSlider4");
    _idToNames.push_back("PrimaryKeyboardSlider5");
    _idToNames.push_back("PrimaryKeyboardSlider6");
    _idToNames.push_back("PrimaryKeyboardSlider7");
    _idToNames.push_back("PrimaryKeyboardSlider8");
    _idToNames.push_back("PrimaryKeyboardSlider9");

    _idToNames.push_back("PrimaryKeyboardButton1");
    _idToNames.push_back("PrimaryKeyboardButton2");
    _idToNames.push_back("PrimaryKeyboardButton3");
    _idToNames.push_back("PrimaryKeyboardButton4");
    _idToNames.push_back("PrimaryKeyboardButton5");
    _idToNames.push_back("PrimaryKeyboardButton6");
    _idToNames.push_back("PrimaryKeyboardButton7");
    _idToNames.push_back("PrimaryKeyboardButton8");
    _idToNames.push_back("PrimaryKeyboardButton9");

    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrawbar1", EWidgetId::OrganDrawbar1));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrawbar2", EWidgetId::OrganDrawbar2));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrawbar3", EWidgetId::OrganDrawbar3));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrawbar4", EWidgetId::OrganDrawbar4));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrawbar5", EWidgetId::OrganDrawbar5));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrawbar6", EWidgetId::OrganDrawbar6));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrawbar7", EWidgetId::OrganDrawbar7));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrawbar8", EWidgetId::OrganDrawbar8));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("OrganDrawbar9", EWidgetId::OrganDrawbar9));

    _nameToIds.insert(
        std::pair<std::string, EWidgetId>("OrganRotatorSpeedTextLabel", EWidgetId::OrganRotatorSpeedTextLabel));

    _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButton1", EWidgetId::PrimaryKeyboardButton1));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButton2", EWidgetId::PrimaryKeyboardButton2));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButton3", EWidgetId::PrimaryKeyboardButton3));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButton4", EWidgetId::PrimaryKeyboardButton4));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButton5", EWidgetId::PrimaryKeyboardButton5));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButton6", EWidgetId::PrimaryKeyboardButton6));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButton7", EWidgetId::PrimaryKeyboardButton7));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButton8", EWidgetId::PrimaryKeyboardButton8));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButton9", EWidgetId::PrimaryKeyboardButton9));
    _nameToIds.insert(std::pair<std::string, EWidgetId>("PrimaryKeyboardButton1", EWidgetId::PrimaryKeyboardButton1));

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
