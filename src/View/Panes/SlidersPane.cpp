#include "SlidersPane.h"
#include "../View.h"

SlidersPane::SlidersPane(View &view, MixerSubModel &mixerSubModel) : Pane(view), _mixerSubModel(mixerSubModel)
{
}

void SlidersPane::Init() // override
{
}

void SlidersPane::Fill() // override
{
    //TODO
}

void SlidersPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    // TODO
}