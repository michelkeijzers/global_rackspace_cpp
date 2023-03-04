#include "GainAndBalanceControlPlugin.h"
#include "../Controller/Controller.h"
#include "../Framework/MvcFramework.h"
#include "../Model/MixerSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include <iostream>

#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

const int GAIN_PARAMETER = 0;

GainAndBalanceControlPlugin::GainAndBalanceControlPlugin(View &view, MixerSubModel &mixerSubModel,
                                   const std::string &name)
    : Plugin(name, view), _mixerSubModel(mixerSubModel)
{
    _mixerSubModel.Subscribe(*this);
}

void GainAndBalanceControlPlugin::Init() /* override */
{
}

void GainAndBalanceControlPlugin::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (changedProperty == ChangedProperties::EChangedProperty::MasterVolume)
    {
        double newVolume = _mixerSubModel.GetMasterVolume();

        MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), GAIN_PARAMETER, newVolume, true);
        Debug::Log("$ " + GetName() + ": new volume = " + std::to_string(newVolume));
    }
}