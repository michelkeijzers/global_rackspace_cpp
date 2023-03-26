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
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganPaneBox,
    new ShapeWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganPaneBox, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganPaneTitleTextLabel,
    new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganPaneTitleTextLabel, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel,
    new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganReverbAmountTextLabel,
    new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganReverbAmountTextLabel, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganDriveTextLabel,
    new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDriveTextLabel, false));
}


// 0%             60%          100%
// +---------------+------------+
// | ORGAN         |   Rev 4    |    ORGAN: Title of pane,  Rev 4 = Reverb Amount: 4
// +---------------|            |PTH% (Pane Title Height %)
// |  Rotator Speed+------------+50%
// |     FAST      |   Drv 8    |    FAST : Rotator Speed   Drv 8: (over)Drive: 8
// |               |            |
// +---------------+------------+

const int PANE_TITLE_WIDTH = 60;
const int REVERB_AMOUNT_WIDTH = 100 - PANE_TITLE_WIDTH;
const int DRIVE_WIDTH = REVERB_AMOUNT_WIDTH;
const int ROTATOR_SPEED_WIDTH = PANE_TITLE_WIDTH;

const int REVERB_AMOUNT_HEIGHT = 50;
const int DRIVE_HEIGHT = 100 - REVERB_AMOUNT_HEIGHT;

void OrganPane::Relayout() // override
{
   SetWidgetBounds(WidgetIds::EWidgetId::OrganPaneBox, 0, 0, 100, 100, 0);
   SetWidgetBounds(
    WidgetIds::EWidgetId::OrganPaneTitleTextLabel, 0, 0, PANE_TITLE_WIDTH, GetPaneTitleHeightPercentage(), 0);
	TODO
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
