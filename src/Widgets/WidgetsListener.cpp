#include "WidgetsListener.h"
#include "../Controller/Controller.h"
#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../View/View.h"
#include "Widgets.h"
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif
#include "../Framework/MvcFramework.h"

WidgetsListener::WidgetsListener(std::shared_ptr<Controller> controller) : _controller(controller)
{
}

void WidgetsListener::SetListeners()
{
    for (auto widget :
         {Widgets::EWidgetId::PrimaryKeyboardButton1, Widgets::EWidgetId::PrimaryKeyboardButton2,
          Widgets::EWidgetId::PrimaryKeyboardButton3, Widgets::EWidgetId::PrimaryKeyboardButton4,
          Widgets::EWidgetId::PrimaryKeyboardButton5, Widgets::EWidgetId::PrimaryKeyboardButton6,
          Widgets::EWidgetId::PrimaryKeyboardButton7, Widgets::EWidgetId::PrimaryKeyboardButton8,
          Widgets::EWidgetId::PrimaryKeyboardButton9, // Buttons
          Widgets::EWidgetId::Slider1, Widgets::EWidgetId::Slider2, Widgets::EWidgetId::Slider3,
          Widgets::EWidgetId::Slider4, Widgets::EWidgetId::Slider5, Widgets::EWidgetId::Slider6,
          Widgets::EWidgetId::Slider7, Widgets::EWidgetId::Slider8, Widgets::EWidgetId::Slider9}) // Sliders
    {
        MvcFramework::GetGigPerformerApi()->listenForWidget(Widgets::GetWidgetName(widget), true);
    }
}

void WidgetsListener::OnWidgetValueChanged(const std::string &widgetName, double newValue)
{
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", newValue = " + std::to_string(newValue));

    Widgets::EWidgetId widgetId = Widgets::GetWidgetId(widgetName);
    switch (widgetId)
    {
    case Widgets::EWidgetId::Drawbar1:
        _controller->GetOrganSubController()->SetDrawbarValue(0, newValue);
        break;

    case Widgets::EWidgetId::Drawbar2:
        _controller->GetOrganSubController()->SetDrawbarValue(1, newValue);
        break;

    case Widgets::EWidgetId::Drawbar3:
        _controller->GetOrganSubController()->SetDrawbarValue(2, newValue);
        break;

    case Widgets::EWidgetId::Drawbar4:
        _controller->GetOrganSubController()->SetDrawbarValue(3, newValue);
        break;

    case Widgets::EWidgetId::Drawbar5:
        _controller->GetOrganSubController()->SetDrawbarValue(4, newValue);
        break;

    case Widgets::EWidgetId::Drawbar6:
        _controller->GetOrganSubController()->SetDrawbarValue(5, newValue);
        break;

    case Widgets::EWidgetId::Drawbar7:
        _controller->GetOrganSubController()->SetDrawbarValue(6, newValue);
        break;

    case Widgets::EWidgetId::Drawbar8:
        _controller->GetOrganSubController()->SetDrawbarValue(7, newValue);
        break;

    case Widgets::EWidgetId::Drawbar9:
        _controller->GetOrganSubController()->SetDrawbarValue(8, newValue);
        break;

    case Widgets::EWidgetId::PrimaryKeyboardButton9:
        if (newValue >= 0.5)
        {
            _controller->GetOrganSubController()->SwapRotatorSpeed();
        }
        break;

    case Widgets::EWidgetId::Slider1:
        ProcessSlider(widgetId, 0, newValue);
        break;

    case Widgets::EWidgetId::Slider2:
        ProcessSlider(widgetId, 1, newValue);
        break;

    case Widgets::EWidgetId::Slider3:
        ProcessSlider(widgetId, 2, newValue);
        break;

    case Widgets::EWidgetId::Slider4:
        ProcessSlider(widgetId, 3, newValue);
        break;

    case Widgets::EWidgetId::Slider5:
        ProcessSlider(widgetId, 4, newValue);
        break;

    case Widgets::EWidgetId::Slider6:
        ProcessSlider(widgetId, 5, newValue);
        break;

    case Widgets::EWidgetId::Slider7:
        ProcessSlider(widgetId, 6, newValue);
        break;

    case Widgets::EWidgetId::Slider8:
        ProcessSlider(widgetId, 7, newValue);
        break;

    case Widgets::EWidgetId::Slider9:
        // TODO: Main volume
        break;

    default:
        Debug::Error(__FUNCTION__, "Illegal widgetId");
        break;
    }

    Debug::LogMethodExit(__FUNCTION__);
}

void WidgetsListener::ProcessSlider(Widgets::EWidgetId widgetId, int sliderIndex, double newValue)
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
