#include "WidgetsListener.h"
#include "../Controller/Controller.h"
#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../View/Panes/OrganPane.h"
#include "../View/Panes/SlidersPane.h"
#include "../View/View.h"
#include "ButtonWidget.h"
#include "ValueWidget.h"
#include "WidgetIds.h"
#include "Widgets.h"

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

    Debug::Log("@--- On Widget " + widgetName + ": value = " + std::to_string(newValue));

    const int drawbar1Value = (int)(WidgetIds::EWidgetId::OrganDrawbar1);
    if (((int)widgetId >= drawbar1Value) && ((int)widgetId < drawbar1Value + OrganPane::NR_OF_DRAWBAR_SLIDERS))
    {
        OrganSubController &organSubController =
            (OrganSubController &)_controller.GetSubController(SubControllers::ESubControllerId::Organ);
        organSubController.SetDrawbarValue(int(widgetId) - drawbar1Value, newValue);
        processed = true;
    }

    if (!processed && (widgetId == WidgetIds::EWidgetId::PrimaryKeyboardButton9))
    {
        if (ButtonWidget::IsPressed(newValue))
        {
            OrganSubController &organSubController =
                (OrganSubController &)_controller.GetSubController(SubControllers::ESubControllerId::Organ);
            organSubController.SwapRotatorSpeed();
        }
        processed = true;
    }

    if (!processed)
    {
        const int primaryKeyboardSlider1 = (int)(WidgetIds::EWidgetId::PrimaryKeyboardSlider1);
        if (((int)widgetId >= primaryKeyboardSlider1) &&
            ((int)widgetId < primaryKeyboardSlider1 + SlidersPane::NR_OF_SLIDERS))
        {
            ProcessSlider(widgetId, (int)widgetId - primaryKeyboardSlider1, newValue);
            processed = true;
        }
    }

    if (!processed)
    {
        if (widgetId == WidgetIds::EWidgetId::SyncLabelsToMixerButton)
        {
            // TODO;
        }
    }

    if (!processed)
    {
        WidgetIds::EWidgetId Channel1NextSourceButtonId = WidgetIds::EWidgetId::SetupChannel1NextSourceButton;
        if ((widgetId >= Channel1NextSourceButtonId) &&
            ((int)widgetId < (int)Channel1NextSourceButtonId + MixerSubModel::NR_OF_MIXER_CHANNELS))
        {
            if (ButtonWidget::IsPressed(newValue))
            {
                MixerSubController &mixerSubController =
                    (MixerSubController &)_controller.GetSubController(SubControllers::ESubControllerId::Mixer);
                mixerSubController.SelectNextSource((int)widgetId - (int) Channel1NextSourceButtonId);
                processed = true;
            }
        }
    }

    if (!processed)
    {
        WidgetIds::EWidgetId Channel1VolumeOverrideButtonId = WidgetIds::EWidgetId::SetupChannel1VolumeOverrideButton;
        if ((widgetId >= Channel1VolumeOverrideButtonId) &&
            ((int)widgetId < (int)Channel1VolumeOverrideButtonId + MixerSubModel::NR_OF_MIXER_CHANNELS))
        {
            if (ButtonWidget::IsPressed(newValue))
            {
                MixerSubController &mixerSubController =
                    (MixerSubController &)_controller.GetSubController(SubControllers::ESubControllerId::Mixer);
                if (ButtonWidget::IsPressed(newValue))
                {
                    mixerSubController.SetVolumeOverride((int)widgetId - (int)Channel1VolumeOverrideButtonId, newValue);
                    processed = true;
                }
            }
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
        (MixerSubController &)_controller.GetSubController(SubControllers::ESubControllerId::Mixer);
    mixerSubController.SetSliderValue(sliderIndex, newValue);
}
