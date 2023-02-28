#include "WidgetsListener.h"
#include "../Controller/Controller.h"
#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../View/View.h"
#include "Widgets.h"
#include "WidgetIds.h"
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif
#include "../Framework/MvcFramework.h"

WidgetsListener::WidgetsListener(std::shared_ptr<Controller> controller, WidgetIds& widgetIds)
    : _controller(controller), _widgetIds(widgetIds)
{
}

void WidgetsListener::OnWidgetValueChanged(const std::string &widgetName, double newValue)
{
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", newValue = " + std::to_string(newValue));

	 WidgetIds::EWidgetId widgetId = _widgetIds.GetId(widgetName);
    switch (widgetId)
     {
    case WidgetIds::EWidgetId::OrganDrawbar1:
        _controller->GetOrganSubController()->SetDrawbarValue(0, newValue);
        break;

    case WidgetIds::EWidgetId::OrganDrawbar2:
        _controller->GetOrganSubController()->SetDrawbarValue(1, newValue);
        break;

    case WidgetIds::EWidgetId::OrganDrawbar3:
        _controller->GetOrganSubController()->SetDrawbarValue(2, newValue);
        break;

    case WidgetIds::EWidgetId::OrganDrawbar4:
        _controller->GetOrganSubController()->SetDrawbarValue(3, newValue);
        break;

    case WidgetIds::EWidgetId::OrganDrawbar5:
        _controller->GetOrganSubController()->SetDrawbarValue(4, newValue);
        break;

    case WidgetIds::EWidgetId::OrganDrawbar6:
        _controller->GetOrganSubController()->SetDrawbarValue(5, newValue);
        break;

    case WidgetIds::EWidgetId::OrganDrawbar7:
        _controller->GetOrganSubController()->SetDrawbarValue(6, newValue);
        break;

    case WidgetIds::EWidgetId::OrganDrawbar8:
        _controller->GetOrganSubController()->SetDrawbarValue(7, newValue);
        break;

    case WidgetIds::EWidgetId::OrganDrawbar9:
        _controller->GetOrganSubController()->SetDrawbarValue(8, newValue);
        break;

    case WidgetIds::EWidgetId::PrimaryKeyboardButton9:
        if (newValue >= 0.5)
        {
            _controller->GetOrganSubController()->SwapRotatorSpeed();
        }
        break;

    case WidgetIds::EWidgetId::PrimaryKeyboardSlider1:
        ProcessSlider(widgetId, 0, newValue);
        break;

    case WidgetIds::EWidgetId::PrimaryKeyboardSlider2:
        ProcessSlider(widgetId, 1, newValue);
        break;

    case WidgetIds::EWidgetId::PrimaryKeyboardSlider3:
        ProcessSlider(widgetId, 2, newValue);
        break;

    case WidgetIds::EWidgetId::PrimaryKeyboardSlider4:
        ProcessSlider(widgetId, 3, newValue);
        break;

    case WidgetIds::EWidgetId::PrimaryKeyboardSlider5:
        ProcessSlider(widgetId, 4, newValue);
        break;

    case WidgetIds::EWidgetId::PrimaryKeyboardSlider6:
        ProcessSlider(widgetId, 5, newValue);
        break;

    case WidgetIds::EWidgetId::PrimaryKeyboardSlider7:
        ProcessSlider(widgetId, 6, newValue);
        break;

    case WidgetIds::EWidgetId::PrimaryKeyboardSlider8:
        ProcessSlider(widgetId, 7, newValue);
        break;

    case WidgetIds::EWidgetId::PrimaryKeyboardSlider9:
        // TODO: Main volume
        break;

    default:
        Debug::Error(__FUNCTION__, "Illegal widgetId");
        break;
    }

    Debug::LogMethodExit(__FUNCTION__);
}

void WidgetsListener::ProcessSlider(WidgetIds::EWidgetId widgetId, int sliderIndex, double newValue)
{
    std::shared_ptr<MixerSubController> mixerSubController = _controller->GetMixerSubController();
    // switch (mixerSubController->GetPaneSelection())
    //{
    // case MixerSubController::EPaneSelection::Channels1To8:
    //   mixerSubController->SetChannelVolume(sliderIndex, newValue);
    //   break;

    // case MixerSubController::EPaneSelection::Channels9To16:
    //    mixerSubController->SetChannelVolume(8 + sliderIndex, newValue);
    //    break;

    // case MixerSubController::EPaneSelection::Channels17To23:
    //    mixerSubController->SetChannelVolume(16 + sliderIndex, newValue);
    //    break;

    // case MixerSubController::EPaneSelection::Drawbars:
    //    // Not possible, invisible
    //    Debug::Error(__FUNCTION__, "Widget should be invisible: " + Widgets::GetWidgetName(widgetId));
    //    break;
    //}
}
