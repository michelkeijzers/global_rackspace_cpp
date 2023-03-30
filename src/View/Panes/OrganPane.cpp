#include "OrganPane.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/TextWidget.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"
#include "../View.h"
#include <cmath>

static const std::string ROTATOR_SPEED_FAST_TEXT = "FAST";
static const std::string ROTATOR_SPEED_SLOW_TEXT = "SLOW";

OrganPane::OrganPane(View &view, OrganSubModel &organSubModel, double leftPercentage, double topPercentage,
 double widthPercentage, double heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage), _organSubModel(organSubModel)
{
   organSubModel.Subscribe(*this);
}

void OrganPane::Fill() // override
{
   WidgetIds::EWidgetId widgetId;
   widgetId = WidgetIds::EWidgetId::OrganPaneBox;
   GetWidgets().AddWidget(widgetId, new ShapeWidget(GetView().GetWidgetIds(), widgetId, false));
   widgetId = WidgetIds::EWidgetId::OrganPaneTitleTextLabel;
   GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));
   widgetId = WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel;
   GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));
   widgetId = WidgetIds::EWidgetId::OrganReverbAmountTextLabel;
   GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));
   widgetId = WidgetIds::EWidgetId::OrganDriveTextLabel;
   GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));
}

// 0%       60%     100%
// +---------+-------+
// | ORGAN   | Rev 4 |       Rev 4 = Reverb Amount: 4
// +---------|       | PTH% (Pane Title Height %)
// |       . +-------+ 50%
// |   FAST  | Drv 8 |    FAST = Rotator Speed, Dvr 8 = Overdrive 8
// +---------+-------+ 100%

const double PANE_TITLE_WIDTH = 0.6;
const double REVERB_AMOUNT_WIDTH = 1.0 - PANE_TITLE_WIDTH;
const double DRIVE_WIDTH = REVERB_AMOUNT_WIDTH;
const double ROTATOR_SPEED_WIDTH = PANE_TITLE_WIDTH;

const double REVERB_AMOUNT_HEIGHT = 0.5;
const double DRIVE_HEIGHT = 1.0 - REVERB_AMOUNT_HEIGHT;

void OrganPane::Relayout() // override
{
   SetWidgetBounds(WidgetIds::EWidgetId::OrganPaneBox, 0.0, 0.0, 1.0, 1.0, 0.0);
   SetWidgetBounds(
    WidgetIds::EWidgetId::OrganPaneTitleTextLabel, 0.0, 0.0, PANE_TITLE_WIDTH, GetPaneTitleHeightPercentage(), 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel, 0, GetPaneTitleHeightPercentage(),
    PANE_TITLE_WIDTH, 1.0 - GetPaneTitleHeightPercentage(), 0.05);
   SetWidgetBounds(WidgetIds::EWidgetId::OrganReverbAmountTextLabel, PANE_TITLE_WIDTH, 0.0, REVERB_AMOUNT_WIDTH,
    REVERB_AMOUNT_HEIGHT, 0.05);
   SetWidgetBounds(
    WidgetIds::EWidgetId::OrganDriveTextLabel, PANE_TITLE_WIDTH, REVERB_AMOUNT_HEIGHT, DRIVE_WIDTH, DRIVE_HEIGHT, 0.05);
}

void OrganPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   switch (changedProperty)
   {
   case ChangedProperties::EChangedProperty::OrganIsEnabled: ShowAllWidgets(_organSubModel.IsEnabled()); break;
   case ChangedProperties::EChangedProperty::OrganRotatorSpeed: {
      TextWidget &textWidget =
       static_cast<TextWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel));
      bool isRotatorSpeedFast = _organSubModel.IsRotatorSpeedFast();
      textWidget.SetText(isRotatorSpeedFast ? ROTATOR_SPEED_FAST_TEXT : ROTATOR_SPEED_SLOW_TEXT);
      textWidget.SetWidgetFillColor(isRotatorSpeedFast ? 1.0 : 0.0, isRotatorSpeedFast ? 0.0 : 1.0, 0.0, 1.0);
   }
   break;
   case ChangedProperties::EChangedProperty::OrganDrive:
      static_cast<TextWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganDriveTextLabel))
       .SetText(std::to_string(static_cast<int>(std::round(_organSubModel.GetDrive() * 10.0))));
      break;
   case ChangedProperties::EChangedProperty::OrganReverbAmount:
      static_cast<TextWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganReverbAmountTextLabel))
       .SetText(std::to_string(static_cast<int>(std::round(_organSubModel.GetReverbAmount() * 10.0))));
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
