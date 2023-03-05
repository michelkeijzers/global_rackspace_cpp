#pragma once

#include <map>
#include <string>
#include <vector>

class WidgetIds
{
  public:
    enum class EWidgetId
    {
        OrganDrawbar1,
        OrganDrawbar2,
        OrganDrawbar3,
        OrganDrawbar4,
        OrganDrawbar5,
        OrganDrawbar6,
        OrganDrawbar7,
        OrganDrawbar8,
        OrganDrawbar9,

        OrganRotatorSpeedTextLabel,
		  OrganDrive,
		  OrganReverbAmount,

        PrimaryKeyboardSlider1,
        PrimaryKeyboardSlider2,
        PrimaryKeyboardSlider3,
        PrimaryKeyboardSlider4,
        PrimaryKeyboardSlider5,
        PrimaryKeyboardSlider6,
        PrimaryKeyboardSlider7,
        PrimaryKeyboardSlider8,
        PrimaryKeyboardSlider9,

        PrimaryKeyboardButton1,
        PrimaryKeyboardButton2,
        PrimaryKeyboardButton3,
        PrimaryKeyboardButton4,
        PrimaryKeyboardButton5,
        PrimaryKeyboardButton6,
        PrimaryKeyboardButton7,
        PrimaryKeyboardButton8,
        PrimaryKeyboardButton9,
        PrimaryKeyboardButton10,
        PrimaryKeyboardButton11,
        PrimaryKeyboardButton12,
        PrimaryKeyboardButton13,

        Last
    };

    WidgetIds();

    void Fill();

    EWidgetId GetId(std::string name);
    std::string GetName(EWidgetId id);

  private:
    std::vector<std::string> _idToNames;
    std::map<std::string, EWidgetId> _nameToIds;
};
