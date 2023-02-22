#include "Widgets.h"
#include "../Utilities/Debug.h"
#include <iostream>
#include <vector>

Widgets::Widgets(gigperformer::sdk::GigPerformerAPI *gigPerformerApi)
{
    std::vector<std::string> widgetNames;

    _gigPerformerApi = gigPerformerApi;
    _gigPerformerApi->getWidgetList(widgetNames, true); // Use global rackspace

    for (std::string widgetName : widgetNames)
    {
        _widgetNames.push_back(widgetName);
    }
}

void Widgets::SetWidgetValue(EWidgetId widgetId, double value)
{
    std::string widgetName = GetWidgetName(widgetId);
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", value = " + std::to_string(value));
    _gigPerformerApi->setWidgetValue(widgetName, value);

	 #ifdef _CONSOLE
	 // Gig Performer automatically calls a callback when a widget value is set that is listened to.

	 #endif

    Debug::LogMethodExit(__FUNCTION__);
}

void Widgets::ShowWidget(EWidgetId widgetId, bool show)
{
    std::string widgetName = GetWidgetName(widgetId);
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", show = " + std::to_string(show));

    _gigPerformerApi->setWidgetCaption(widgetName, std::to_string(show));
    Debug::LogMethodExit(__FUNCTION__);
}

void Widgets::SetWidgetLabelText(EWidgetId widgetId, std::string labelText)
{
    std::string widgetName = GetWidgetName(widgetId);
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", labelText = " + labelText);

    _gigPerformerApi->setWidgetCaption(widgetName, labelText);
    Debug::LogMethodExit(__FUNCTION__);
}

void Widgets::SetWidgetFillColor(EWidgetId widgetId, double red, double green, double blue, double alpha)
{
    std::string widgetName = GetWidgetName(widgetId);
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", red = " + std::to_string(red) +
                                            ", green = " + std::to_string(green) + ", blue = " + std::to_string(blue) +
                                            ", alpha = " + std::to_string(alpha));

    _gigPerformerApi->setWidgetFillColor(widgetName, _gigPerformerApi->RGBAToColor(red, green, blue, alpha));

    Debug::LogMethodExit(__FUNCTION__);
}

void Widgets::AssertIfWidgetDoesNotExist(std::string widgetName)
{
    if (!_gigPerformerApi->widgetExists(widgetName))
    {
        Debug::Assert(false, "Widgets::SetValue", "Widget not found: " + widgetName);
    }
}

/* static */ std::string Widgets::GetWidgetName(EWidgetId widgetId)
{
    std::string widgetName = "";

    switch (widgetId)
    {
    case EWidgetId::OrganRotatorSpeedTextLabel:
        widgetName = "OrganRotatorSpeedTextLabel";
        break;

    case EWidgetId::PrimaryKeyboardButton1:
        widgetName = "Button1";
        break;

    case EWidgetId::PrimaryKeyboardButton2:
        widgetName = "Button2";
        break;

    case EWidgetId::PrimaryKeyboardButton3:
        widgetName = "Button3";
        break;

    case EWidgetId::PrimaryKeyboardButton4:
        widgetName = "Button4";
        break;

    case EWidgetId::PrimaryKeyboardButton5:
        widgetName = "Button5";
        break;

    case EWidgetId::PrimaryKeyboardButton6:
        widgetName = "Button6";
        break;

    case EWidgetId::PrimaryKeyboardButton7:
        widgetName = "Button7";
        break;

    case EWidgetId::PrimaryKeyboardButton8:
        widgetName = "Button8";
        break;

    case EWidgetId::PrimaryKeyboardButton9:
        widgetName = "Button9";
        break;

    case EWidgetId::PrimaryKeyboardSlider1:
        widgetName = "Slider1";
        break;

    case EWidgetId::PrimaryKeyboardSlider2:
        widgetName = "Slider2";
        break;

    case EWidgetId::PrimaryKeyboardSlider3:
        widgetName = "Slider3";
        break;

    case EWidgetId::PrimaryKeyboardSlider4:
        widgetName = "Slider4";
        break;

    case EWidgetId::PrimaryKeyboardSlider5:
        widgetName = "Slider5";
        break;

    case EWidgetId::PrimaryKeyboardSlider6:
        widgetName = "Slider6";
        break;

    case EWidgetId::PrimaryKeyboardSlider7:
        widgetName = "Slider7";
        break;

    case EWidgetId::PrimaryKeyboardSlider8:
        widgetName = "Slider8";
        break;

    case EWidgetId::PrimaryKeyboardSlider9:
        widgetName = "Slider9";
        break;

    default:
        Debug::Error(__FUNCTION__, "Illegal widget ID");
    }

    return widgetName;
}

/* static */ Widgets::EWidgetId Widgets::GetWidgetId(std::string widgetName)
{
    EWidgetId widgetId = EWidgetId::LastWidget;

    switch (widgetName[0])
    {
    case 'B':
        Debug::Assert(widgetName.length() == 7, __FUNCTION__, "Illegal widget length of " + widgetName);
        Debug::Assert(widgetName[1] == 'u', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[2] == 't', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[3] == 't', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[4] == 'o', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[5] == 'n', __FUNCTION__, "Illegal widget name " + widgetName);

        switch (widgetName[6])
        {
        case '1':
            widgetId = EWidgetId::PrimaryKeyboardButton1;
            break;

        case '2':
            widgetId = EWidgetId::PrimaryKeyboardButton2;
            break;

        case '3':
            widgetId = EWidgetId::PrimaryKeyboardButton3;
            break;

        case '4':
            widgetId = EWidgetId::PrimaryKeyboardButton4;
            break;

        case '5':
            widgetId = EWidgetId::PrimaryKeyboardButton5;
            break;

        case '6':
            widgetId = EWidgetId::PrimaryKeyboardButton6;
            break;

        case '7':
            widgetId = EWidgetId::PrimaryKeyboardButton7;
            break;

        case '8':
            widgetId = EWidgetId::PrimaryKeyboardButton8;
            break;

        case '9':
            widgetId = EWidgetId::PrimaryKeyboardButton9;
            break;

        default:
            Debug::Error(__FUNCTION__, "Illegal slider number of " + widgetName);
        }
        break;

    case 'O':
        Debug::Assert(widgetName.length() == 26, __FUNCTION__, "Illegal widget length of " + widgetName);
        Debug::Assert(widgetName[1] == 'r', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[2] == 'g', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[3] == 'a', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[4] == 'n', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[5] == 'R', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[6] == 'o', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[7] == 't', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[8] == 'a', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[9] == 't', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[10] == 'o', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[11] == 'r', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[12] == 'S', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[13] == 'p', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[14] == 'e', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[15] == 'e', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[16] == 'd', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[17] == 'T', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[18] == 'e', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[19] == 'x', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[20] == 't', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[21] == 'L', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[22] == 'a', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[23] == 'b', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[24] == 'e', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[25] == 'l', __FUNCTION__, "Illegal widget name " + widgetName);
        widgetId = EWidgetId::OrganRotatorSpeedTextLabel;
        break;

    case 'S':
        Debug::Assert(widgetName.length() == 7, __FUNCTION__, "Illegal widget length of " + widgetName);
        Debug::Assert(widgetName[1] == 'l', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[2] == 'i', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[3] == 'd', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[4] == 'e', __FUNCTION__, "Illegal widget name " + widgetName);
        Debug::Assert(widgetName[5] == 'r', __FUNCTION__, "Illegal widget name " + widgetName);
        switch (widgetName[6])
        {
        case '1':
            widgetId = EWidgetId::PrimaryKeyboardSlider1;
            break;

        case '2':
            widgetId = EWidgetId::PrimaryKeyboardSlider2;
            break;

        case '3':
            widgetId = EWidgetId::PrimaryKeyboardSlider3;
            break;

        case '4':
            widgetId = EWidgetId::PrimaryKeyboardSlider4;
            break;

        case '5':
            widgetId = EWidgetId::PrimaryKeyboardSlider5;
            break;

        case '6':
            widgetId = EWidgetId::PrimaryKeyboardSlider6;
            break;

        case '7':
            widgetId = EWidgetId::PrimaryKeyboardSlider7;
            break;

        case '8':
            widgetId = EWidgetId::PrimaryKeyboardSlider8;
            break;

        case '9':
            widgetId = EWidgetId::PrimaryKeyboardSlider9;
            break;

        default:
            Debug::Error(__FUNCTION__, "Illegal slider number of " + widgetName);
        }
        break;

    default:
        Debug::Error(__FUNCTION__, "Illegal widget name " + widgetName);
    }

    return widgetId;
}