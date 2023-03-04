#include "WidgetsListener.h"
#include "../Controller/Controller.h"
#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../View/View.h"
#include "WidgetIds.h"
#include "Widgets.h"
#include "ValueWidget.h"
#include "../View/Panes/OrganPane.h"
#include "../View/Panes/SlidersPane.h"

#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif
#include "../Framework/MvcFramework.h"

WidgetsListener::WidgetsListener(Controller &controller, WidgetIds &widgetIds)
    : _controller(controller), _widgetIds(widgetIds)
{
}

void WidgetsListener::OnWidgetValueChanged(const std::string &widgetName, double newValue)
{
    bool processed = false;

    Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", newValue = " + std::to_string(newValue));

    WidgetIds::EWidgetId widgetId = _widgetIds.GetId(widgetName);

    Debug::Log("# Widget " + widgetName + ": value = " + std::to_string(newValue));

    const int drawbar1Value = (int)(WidgetIds::EWidgetId::OrganDrawbar1);
	 if (((int)widgetId >= drawbar1Value) &&
        ((int)widgetId < drawbar1Value + OrganPane::NR_OF_DRAWBAR_SLIDERS))
    {
         OrganSubController &organSubController =
             (OrganSubController &)_controller.GetSubControllerById(SubControllers::ESubControllerId::Organ);
         organSubController.SetDrawbarValue(int(widgetId) - drawbar1Value, newValue);
        processed = true;
    }
    
	 if (!processed && (widgetId == WidgetIds::EWidgetId::PrimaryKeyboardButton9))
    {
        if (ValueWidget::IsButtonPressed(newValue))
        {
            OrganSubController &organSubController =
                (OrganSubController &)_controller.GetSubControllerById(SubControllers::ESubControllerId::Organ);
            organSubController.SwapRotatorSpeed();
        }
        processed = true;
    }

	 if (!processed)
    {
        const int primaryKeyboardSlider1Value = (int)(WidgetIds::EWidgetId::PrimaryKeyboardSlider1);
        if (((int)widgetId >= primaryKeyboardSlider1Value) &&
            ((int)widgetId < primaryKeyboardSlider1Value + SlidersPane::NR_OF_SLIDERS))
        {
            ProcessSlider(widgetId, (int)widgetId - primaryKeyboardSlider1Value, newValue);
            processed = true;
        }
    }

	 if (!processed)
    {
        Debug::Error(__FUNCTION__, "Illegal widgetId");
    }

    Debug::LogMethodExit(__FUNCTION__);
}

void WidgetsListener::ProcessSlider(WidgetIds::EWidgetId widgetId, int sliderIndex, double newValue)
{
    MixerSubController &mixerSubController = 
		 (MixerSubController&) _controller.GetSubControllerById(SubControllers::ESubControllerId::Mixer);
    mixerSubController.SetSliderValue(sliderIndex, newValue);
}
