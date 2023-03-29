#include "LiveSubView.h"
#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "Panes/FootBoardPane.h"
#include "Panes/OrganPane.h"
#include "Panes/Panes.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"
#include "Panes/SlidersPane.h"

LiveSubView::LiveSubView(Model &model, View &view) : SubView(model, view)
{
}

// 0%                    40%           60%                 80%
// +----------------------+-------------+-------------------+------+ 0%
// |                      | CLOCK/TIMER |                   | FOOT |
// |                      +-------------|   MINI MIXER      | BOARD| 25%
// |     SLIDERS          |   ORGAN     |                   |      |
// |                      +-------------+-------------------+------+ 50%
// |                      |    PRIMARY KEYBOARD BUTTONS (& KNOBS)  |
// +----------------------+----------------------------------------+ 100%

const double SLIDER_WIDTH_PERCENTAGE = 0.4;
const double CLOCK_TIMER_WIDTH_PERCENTAGE = 0.2;
const double ORGAN_WIDTH_PERCENTAGE = CLOCK_TIMER_WIDTH_PERCENTAGE;
const double FOOT_BOARD_WIDTH_PERCENTAGE = 0.2;
const double MINI_MIXER_WIDTH_PERCENTAGE =
 1.0 - SLIDER_WIDTH_PERCENTAGE - CLOCK_TIMER_WIDTH_PERCENTAGE - FOOT_BOARD_WIDTH_PERCENTAGE;
const double PRIMARY_KEYBOARD_BUTTONS_WIDTH_PERCENTAGE = 1.0 - SLIDER_WIDTH_PERCENTAGE;

const double SLIDER_HEIGHT_PERCENTAGE = 1.0;
const double CLOCK_TIMER_HEIGHT_PERCENTAGE = 0.25;
const double ORGAN_HEIGHT_PERCENTAGE = 0.25;
const double MINI_MIXER_HEIGHT_PERCENTAGE = CLOCK_TIMER_HEIGHT_PERCENTAGE + CLOCK_TIMER_HEIGHT_PERCENTAGE;
const double FOOT_BOARD_HEIGTH_PERCENTAGE = MINI_MIXER_HEIGHT_PERCENTAGE;
const double PRIMARY_KEYBOARD_BUTTONS_HEIGHT_PERCENTAGE = 1.0 - MINI_MIXER_HEIGHT_PERCENTAGE;

void LiveSubView::Fill() // override
{
   OrganSubModel &organSubModel = static_cast<OrganSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Organ));
   MixerSubModel &mixerSubModel = static_cast<MixerSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Mixer));
   KeyboardSubModel &primaryKeyboardSubModel =
    static_cast<KeyboardSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::PrimaryKeyboard));
   KeyboardSubModel &secondaryKeyboardSubModel =
    static_cast<KeyboardSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::SecondaryKeyboard));

   GetPanes().AddPane(new SlidersPane(
    GetView(), GetModel(), mixerSubModel, organSubModel, 0.0, 0.0, SLIDER_WIDTH_PERCENTAGE, SLIDER_HEIGHT_PERCENTAGE));
   // GetPanes().AddPane(new ClickTimerPane(GetView(), clockTimerSubModel, SLIDER_WIDTH_PERCENTAGE,
   //  0, CLOCK_TIMER_WIDTH_PERCENTAGE, CLOCK_TIMER_HEIGHT_PERCENTAGE));
   GetPanes().AddPane(new OrganPane(GetView(), organSubModel, SLIDER_WIDTH_PERCENTAGE, CLOCK_TIMER_HEIGHT_PERCENTAGE,
    ORGAN_WIDTH_PERCENTAGE, ORGAN_HEIGHT_PERCENTAGE));
   // GetPanes().AddPane(
   //  new MiniMixerPane(GetView(), mixerSubModel, 1.0 - SLIDER_WIDTH_PERCENTAGE - CLOCK_TIMER_WIDTH_PERCENTAGE, 0,
   //   MINI_MIXER_WIDTH_PERCENTAGE, MINI_MIXER_HEIGHT_PERCENTAGE));
   GetPanes().AddPane(
    new FootBoardPane(GetView(), primaryKeyboardSubModel, secondaryKeyboardSubModel, 1.0 - FOOT_BOARD_WIDTH_PERCENTAGE,
     MINI_MIXER_HEIGHT_PERCENTAGE, FOOT_BOARD_WIDTH_PERCENTAGE, FOOT_BOARD_HEIGTH_PERCENTAGE));
   GetPanes().AddPane(
    new PrimaryKeyboardButtonsPane(GetView(), organSubModel, SLIDER_WIDTH_PERCENTAGE, MINI_MIXER_HEIGHT_PERCENTAGE,
     PRIMARY_KEYBOARD_BUTTONS_WIDTH_PERCENTAGE, PRIMARY_KEYBOARD_BUTTONS_HEIGHT_PERCENTAGE));
   SubView::Fill(); // TODO: Move this function to Add Panes,
                    // instead of fill, so this call can be removed., AddPanes will be a function called
                    // from the baseclass Fill
}
