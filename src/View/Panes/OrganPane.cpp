#include "OrganPane.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/TextWidget.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"
#include "../View.h"

static const std::string ROTATOR_SPEED_FAST_TEXT = "FAST";
static const std::string ROTATOR_SPEED_SLOW_TEXT = "SLOW";

OrganPane::OrganPane(View &view, OrganSubModel &organSubModel, int leftPercentage, int topPercentage,
 int widthPercentage, int heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage), _organSubModel(organSubModel)
{
   organSubModel.Subscribe(*this);
}

void OrganPane::Fill() // override
{
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel,
    new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel, true));
}

// 0%             60%          100%
// +---------------+------------+
// | ORGAN         |   Rev 4    |    ORGAN: Title of pane,  Rev 4 = Reverb Amount: 4
// +---------------|            |TH% (Title Box Height %)
// |               +------------+50%
// |     FAST      |   Drv 8    |    FAST : Rotator Speed   Drv 8: (over)Drive: 8
// |               |            |
// +---------------+------------+
void OrganPane::Relayout() // override
{
   
}

void OrganPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   if (changedProperty == ChangedProperties::EChangedProperty::OrganIsEnabled)
   {
      ShowAllWidgets(_organSubModel.IsEnabled());
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::OrganRotatorSpeed)
   {
      TextWidget &textWidget =
       static_cast<TextWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel));
      bool isRotatorSpeedFast = _organSubModel.IsRotatorSpeedFast();
      textWidget.SetText(isRotatorSpeedFast ? ROTATOR_SPEED_FAST_TEXT : ROTATOR_SPEED_SLOW_TEXT);
      textWidget.SetWidgetFillColor(isRotatorSpeedFast ? 1.0 : 0.0, isRotatorSpeedFast ? 0.0 : 1.0, 0.0, 1.0);
   }
}

void OrganPane::ShowAllWidgets(bool show)
{
   for (auto &widgetId : GetWidgets().GetWidgetIds())
   {
      auto &widget = GetWidgets().GetWidget(widgetId);
      widget.Show(show);
   }
}
