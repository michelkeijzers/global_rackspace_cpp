#include "WidgetsListener.h"
#include "../Controller/Controller.h"
#include "../Controller/MixerController.h"
#include "../Controller/OrganController.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../View/View.h"
#include "Widgets.h"
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

WidgetsListener::WidgetsListener(std::shared_ptr<Controller> controller,
                                 gigperformer::sdk::GigPerformerAPI *gigPerformerApi)
    : _controller(controller), _gigPerformerApi(gigPerformerApi)
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
        _gigPerformerApi->listenForWidget(Widgets::GetWidgetName(widget), true);
    }
}

void WidgetsListener::OnWidgetValueChanged(const std::string &widgetName, double newValue)
{
    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", newValue = " + std::to_string(newValue));

    Widgets::EWidgetId widgetId = Widgets::GetWidgetId(widgetName);
    switch (widgetId)
    {
    case Widgets::EWidgetId::Drawbar1:
        _controller->GetOrganController()->SetDrawbarValue(0, newValue);
        break;

    case Widgets::EWidgetId::Drawbar2:
        _controller->GetOrganController()->SetDrawbarValue(1, newValue);
        break;

    case Widgets::EWidgetId::Drawbar3:
        _controller->GetOrganController()->SetDrawbarValue(2, newValue);
        break;

    case Widgets::EWidgetId::Drawbar4:
        _controller->GetOrganController()->SetDrawbarValue(3, newValue);
        break;

    case Widgets::EWidgetId::Drawbar5:
        _controller->GetOrganController()->SetDrawbarValue(4, newValue);
        break;

    case Widgets::EWidgetId::Drawbar6:
        _controller->GetOrganController()->SetDrawbarValue(5, newValue);
        break;

    case Widgets::EWidgetId::Drawbar7:
        _controller->GetOrganController()->SetDrawbarValue(6, newValue);
        break;

    case Widgets::EWidgetId::Drawbar8:
        _controller->GetOrganController()->SetDrawbarValue(7, newValue);
        break;

    case Widgets::EWidgetId::Drawbar9:
        _controller->GetOrganController()->SetDrawbarValue(8, newValue);
        break;

    case Widgets::EWidgetId::PrimaryKeyboardButton9:
        if (newValue >= 0.5)
        {
            _controller->GetOrganController()->SwapRotatorSpeed();
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
    std::shared_ptr<MixerController> mixerController = _controller->GetMixerController();
    switch (mixerController->GetPaneSelection())
    {
    case MixerController::EPaneSelection::Channels1To8:
        mixerController->SetChannelVolume(sliderIndex, newValue);
        break;

    case MixerController::EPaneSelection::Channels9To16:
        mixerController->SetChannelVolume(8 + sliderIndex, newValue);
        break;

    case MixerController::EPaneSelection::Channels17To23:
        mixerController->SetChannelVolume(16 + sliderIndex, newValue);
        break;

    case MixerController::EPaneSelection::Drawbars:
        // Not possible, invisible
        Debug::Error(__FUNCTION__, "Widget should be invisible: " + Widgets::GetWidgetName(widgetId));
        break;
    }
}