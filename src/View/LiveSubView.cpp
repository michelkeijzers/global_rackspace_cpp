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

void LiveSubView::Fill() // override
{
   OrganSubModel &organSubModel = static_cast<OrganSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Organ));
   MixerSubModel &mixerSubModel = static_cast<MixerSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::Mixer));
   KeyboardSubModel &primaryKeyboardSubModel =
    static_cast<KeyboardSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::PrimaryKeyboard));
   KeyboardSubModel &secondaryKeyboardSubModel =
    static_cast<KeyboardSubModel &>(GetModel().GetSubModel(SubModels::ESubModelId::SecondaryKeyboard));

   GetPanes().AddPane(new SlidersPane(GetView(), GetModel(), mixerSubModel, organSubModel, 0, 0, 100, 100));
   GetPanes().AddPane(new OrganPane(GetView(), organSubModel, 0, 0, 100, 100));
   GetPanes().AddPane(new PrimaryKeyboardButtonsPane(GetView(), organSubModel, 0, 0, 100, 100));
   GetPanes().AddPane(new FootBoardPane(GetView(), primaryKeyboardSubModel, secondaryKeyboardSubModel, 0, 0, 100, 100));

   /*
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
