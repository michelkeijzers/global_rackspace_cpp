#include "LiveSubView.h"
#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "Panes/FootBoardPane.h"
#include "Panes/OrganPane.h"
#include "Panes/Panes.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"
#include "Panes/SlidersPane.h"

LiveSubView::LiveSubView(Model &model, View &view) : SubView(model, view) {}

// 0%                    40%           60%                 80%
// +----------------------+-------------+-------------------+------+ 0%
// |                      | CLOCK/TIMER |                   | FOOT |
// |                      +-------------|   MINI MIXER      | BOARD| 25%
// |     SLIDERS          |   ORGAN     |                   |      |
// |                      +-------------+-------------------+------+ 50%
// |                      |    PRIMARY KEYBOARD BUTTONS (& KNOBS)  |
// +----------------------+----------------------------------------+ 100%

const int SLIDER_WIDTH_PERCENTAGE = 40;
const int CLOCK_TIMER_WIDTH_PERCENTAGE = 20;
const int ORGAN_WIDTH_PERCENTAGE = ORGAN_WIDTH_PERCENTAGE;
const int FOOT_BOARD_WIDTH_PERCENTAGE = 20;
const int MINI_MIXER_WIDTH_PERCENTAGE =
 100 - SLIDER_WIDTH_PERCENTAGE - CLOCK_TIMER_WIDTH_PERCENTAGE - FOOT_BOARD_WIDTH_PERCENTAGE;
const int PRIMARY_KEYBOARD_BUTTONS_WIDTH_PERCENTAGE = 100 - SLIDER_WIDTH_PERCENTAGE;

const int SLIDER_HEIGHT_PERCENTAGE = 100;
const int CLOCK_TIMER_HEIGHT_PERCENTAGE = 25;
const int ORGAN_HEIGHT_PERCENTAGE = 25;
const int MINI_MIXER_HEIGHT_PERCENTAGE = CLOCK_TIMER_HEIGHT_PERCENTAGE + CLOCK_TIMER_HEIGHT_PERCENTAGE;
const int FOOT_BOARD_HEIGTH_PERCENTAGE = MINI_MIXER_HEIGHT_PERCENTAGE;
const int PRIMARY_KEYBOARD_BUTTONS_HEIGHT_PERCENTAGE = 100 - MINI_MIXER_HEIGHT_PERCENTAGE;

void LiveSubView::Fill() // override
{
   OrganSubModel &organSubModel = static_cast<OrganSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Organ));
   MixerSubModel &mixerSubModel = static_cast<MixerSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Mixer));
   KeyboardSubModel &primaryKeyboardSubModel =
    static_cast<KeyboardSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::PrimaryKeyboard));
   KeyboardSubModel &secondaryKeyboardSubModel =
    static_cast<KeyboardSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::SecondaryKeyboard));

   GetPanes().AddPane(new SlidersPane(
    GetView(), GetModel(), mixerSubModel, organSubModel, 0, 0, SLIDER_WIDTH_PERCENTAGE, SLIDER_HEIGHT_PERCENTAGE));
   // GetPanes().AddPane(new ClickTimerPane(GetView(), clockTimerSubModel, SLIDER_WIDTH_PERCENTAGE,
   //  0, CLOCK_TIMER_WIDTH_PERCENTAGE, CLOCK_TIMER_HEIGHT_PERCENTAGE));
   GetPanes().AddPane(new OrganPane(GetView(), organSubModel, SLIDER_WIDTH_PERCENTAGE, CLOCK_TIMER_HEIGHT_PERCENTAGE,
    ORGAN_WIDTH_PERCENTAGE, ORGAN_HEIGHT_PERCENTAGE));
   // GetPanes().AddPane(
   //  new MiniMixerPane(GetView(), mixerSubModel, 100 - SLIDER_WIDTH_PERCENTAGE - CLOCK_TIMER_WIDTH_PERCENTAGE, 0,
   //   MINI_MIXER_WIDTH_PERCENTAGE, MINI_MIXER_HEIGHT_PERCENTAGE));
   GetPanes().AddPane(
    new FootBoardPane(GetView(), primaryKeyboardSubModel, secondaryKeyboardSubModel, 100 - FOOT_BOARD_WIDTH_PERCENTAGE,
     MINI_MIXER_HEIGHT_PERCENTAGE, FOOT_BOARD_WIDTH_PERCENTAGE, FOOT_BOARD_HEIGTH_PERCENTAGE));
   GetPanes().AddPane(
    new PrimaryKeyboardButtonsPane(GetView(), organSubModel, SLIDER_WIDTH_PERCENTAGE, MINI_MIXER_HEIGHT_PERCENTAGE,
     PRIMARY_KEYBOARD_BUTTONS_WIDTH_PERCENTAGE, PRIMARY_KEYBOARD_BUTTONS_HEIGHT_PERCENTAGE));

   /* TODO: Check? Or remove
    * SLIDERS: Left: 0, Top = 0, Width = 481, Height = 381, Right = 481, Bottom = 381
    * CLOCK/TIMER: Left: 481, Top = 0, Width = 164, Height = 85, Right = 645, Bottom = 85
    * ORGAN: Left: 482, Top = 80, Width = 164, Height = 85, Right = 646, Bottom = 165
    * MINI MIXER: Left: 646, Top = 3, Width = 344, Height = 166, Right = 990, Bottom = 169
    * FOOT BOARD: Left: 1009, Top = 2, Width = 52, Height = 166, Right = 1061, Bottom = 168
    * BUTTONS & DIALS Left: 484, Top = 169, Width = 586, Height = 214, Right = 1070, Bottom = 383
    */
   SubView::Fill(); // TODO: Move this function to Add Panes,
                    // instead of fill, so this call can be removed., AddPanes will be a function called
                    // from the baseclass Fill
}
