#include "PrimaryKeyboardButtonsPane.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/ButtonWidget.h"
#include "../../Widgets/WidgetIds.h"
#include "../ChangedProperties.h"
#include "../View.h"
#include "Pane.h"

/* static */ const std::string PrimaryKeyboardButtonsPane::WIDGET_BUTTON_NAME = "BUTTON_";
static const int NR_OF_BUTTONS = 13;

PrimaryKeyboardButtonsPane::PrimaryKeyboardButtonsPane(View &view, OrganSubModel &organSubModel, double leftPercentage,
 double topPercentage, double widthPercentage, double heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage), _organSubModel(organSubModel)
{
   organSubModel.Subscribe(*this);
}

void PrimaryKeyboardButtonsPane::Fill()
{
   for (int buttonIndex = 0; buttonIndex < NR_OF_BUTTONS; buttonIndex++)
   {
      WidgetIds::EWidgetId widgetId = WidgetIds::GetPrimaryKeyboardButton(buttonIndex);
      GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
   }
}



//   v CHANNEL_WIDTH * 50%
//     v CHANNEL_WIDTH * 75%
//       v CHANNEL_WIDTH
// 0%       20%      30%             50%             75%             100%
// +---------+--------+---------------+---------------+---------------+ 0%
// | SLIDERS |  ORGAN |  CHANNELS 1-8 | CHANNELS 9-16 | CHANNEL 17-24 |
// +-----+---+--------+---------------+---------------+---------+-----+ PTH% (0%)
// | C18 | ..................... 9 ............................ | C26 |
// +-+-+-+------------------------------------------------------+-+-+-+ 10%
// |s|m|m|                                                      |s|m|m|
// |l|e|e|                                                      |l|e|e|
// |i|t|t| ..................... 9 ............................ |i|t|t|
// |d|e|e|                                                      |d|e|e|
// |e|r|r|                                                      |e|r|r|
// |r|L|R|                                                      |r|L|R|
// +-+-+-+------------------------------------------------------+-+-+-+ 70%
// |Name | ..................... 9 ............................ |Mastr|
// |-----+------------------------------------------------------+-----+ 90%
// | Src | ..................... 9 ............................ | Src |
// |-----+------------------------------------------------------+-----+ 100%




// 0%          100%
// +------------+ 0%
// | FOOT BOARD |
// +------------+ PTH% (0%)
// | Left Pedal |
// +------------+ 50% 
// |Right Pedal |
// +------------+ 100%


// CLOCK/TIMER
// 0%             50%       100%
// +-------------------------+
// | CLOCK / TIMER           |
// +--------------+----------+ PTH% (0%)
// | Current Time | 34:37:01 |
// +--------------+----------+ 50%
// | Song Time    |    03:01 |
// +--------------+----------+ 100%


// MINI MIXER
//    v CHANNEL_WIDTH * 50%
//       v CHANNEL_WIDTH
// +----------------------------------------------+ 0%
// |                   MINI MIXER                 |
// +--+--+----------------------------------+--+--+ PTH% (0%)
// | 1| 1|                                  |12|12|
// | L| R|                                  | L| R| 
// +--+--+ ................. 12 ........... +--+--+ 40%
// |  1  |                                  | 12  |
// +--+--+----------------------------------+--+--+ 50%
// |13|13|                                  |24|24|
// | L| R|                                  | L| R|
// +--+--+ ................. 12 ........... +--+--+ 90%
// | 13  |                                  | 24  |
// +--+--+----------------------------------+--+--+ 100%



// 0%   100%/#BUTTONS,  100%/#KNOBS
// 0%      v BUTTON_WIDTH
//          v KNOB_WIDTH
// +-------------------------------------------------------------+ 0%
// |              M-AUDIO OXYGEN 61 BUTTONS & KNOBS              |
// +-------+---------------------------------------------+-------+ PTH% (0%)
// |  C18  | ........................ 9 ................ |  C26  | 
// +--------+                                           +--------+ 50%
// |  C10   |........................ 8 ................|   C27  |
// +--------+-------------------------------------------+--------+ 100%

void PrimaryKeyboardButtonsPane::Relayout() // override
{
   // TODO RELAYOUT
}

void PrimaryKeyboardButtonsPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   switch (changedProperty)
   {
   case ChangedProperties::EChangedProperty::OrganRotatorSpeed: {
      Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardButton9);
      static_cast<ButtonWidget &>(widget).SetPressed(_organSubModel.IsRotatorSpeedFast());
   }
   break;
   }
}
