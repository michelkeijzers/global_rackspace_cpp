#include "WidgetsListener.h"
#include "../Controller/Controller.h"
#include "../Controller/MixerController.h"
#include "../Controller/OrganController.h"
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
    for (auto widget : {Widgets::EWidgetId::PrimaryKeyboardButton1, Widgets::EWidgetId::PrimaryKeyboardButton2,
                        Widgets::EWidgetId::PrimaryKeyboardButton3, Widgets::EWidgetId::PrimaryKeyboardButton4,
                        Widgets::EWidgetId::PrimaryKeyboardButton5, Widgets::EWidgetId::PrimaryKeyboardButton6,
                        Widgets::EWidgetId::PrimaryKeyboardButton7, Widgets::EWidgetId::PrimaryKeyboardButton8,
                        Widgets::EWidgetId::PrimaryKeyboardButton9, // Buttons
                        Widgets::EWidgetId::PrimaryKeyboardSlider1, Widgets::EWidgetId::PrimaryKeyboardSlider2,
                        Widgets::EWidgetId::PrimaryKeyboardSlider3, Widgets::EWidgetId::PrimaryKeyboardSlider4,
                        Widgets::EWidgetId::PrimaryKeyboardSlider5, Widgets::EWidgetId::PrimaryKeyboardSlider6,
                        Widgets::EWidgetId::PrimaryKeyboardSlider7, Widgets::EWidgetId::PrimaryKeyboardSlider8,
                        Widgets::EWidgetId::PrimaryKeyboardSlider9}) // Sliders
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
    case Widgets::EWidgetId::PrimaryKeyboardButton9:
        if (newValue >= 0.5)
        {
            _controller->GetOrganController()->SwapRotatorSpeed();
        }
        break;

	case Widgets::EWidgetId::PrimaryKeyboardSlider1:
        _controller->GetMixerController()->SetChannelVolume(0, newValue);
        break;

    default:
        Debug::Error(__FUNCTION__, "Illegal widgetId");
        break;
    }

    Debug::LogMethodExit(__FUNCTION__);
}
