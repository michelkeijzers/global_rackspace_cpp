#include "OrganPlugin.h"
#include "../Framework/MvcFramework.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include "../View/ChangedProperties.h"
#include <iostream>
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

static const int PLUGIN_PARAMETER_REVERB_AMOUNT = 4;
static const int PLUGIN_PARAMETER_ROTATOR_SPEED = 8;
static const int PLUGIN_PARAMETERS_UPPDR_DRAWBARS_OFFSET = 20;

OrganPlugin::OrganPlugin(View &view, OrganSubModel &organSubModel, const std::string& name)
    : Plugin(name, view), _organSubModel(organSubModel)
{
    _organSubModel.Subscribe(*this);
}


void OrganPlugin::Init() /* override */
{
}

void OrganPlugin::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (changedProperty == ChangedProperties::EChangedProperty::OrganDrawbar1)
    {
        SetDrawbarValue(1);
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganRotatorSpeed)
    {
        SetRotatorSpeed();
    }
}

void OrganPlugin::SetDrawbarValue(int drawbarIndex)
{
    double drawbarValue = _organSubModel.GetDrawbarValue(0);
    MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), PLUGIN_PARAMETERS_UPPDR_DRAWBARS_OFFSET,
                                                          drawbarValue, true);
    Debug::Log("$ " + GetName() + ": drawbar 1 = " + std::to_string(drawbarValue));
}

void OrganPlugin::SetRotatorSpeed()
{
    double rotatorSpeedFast = _organSubModel.IsRotatorSpeedFast();
    MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), PLUGIN_PARAMETER_ROTATOR_SPEED, rotatorSpeedFast,
                                                          true);
    Debug::Log("$ " + GetName() + ": rotator speed fast = " + std::to_string(rotatorSpeedFast));
}
