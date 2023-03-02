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

static const std::string PLUGIN_NAME = "Organ"; // Native Instrument, Vintage Organ
static const int PLUGIN_PARAMETER_REVERB_AMOUNT = 4;
static const int PLUGIN_PARAMETER_ROTATOR_SPEED = 8;
static const int PLUGIN_PARAMETERS_UPPDR_DRAWBARS_OFFSET = 20;

OrganPlugin::OrganPlugin(View& view, OrganSubModel& organSubModel) : Plugin(PLUGIN_NAME, view)
{
    organSubModel.Subscribe(*this);
}

void OrganPlugin::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (changedProperty == ChangedProperties::EChangedProperty::Drawbar1)
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
    double drawbarValue = GetView().GetModel().GetOrganSubModel().GetDrawbarValue(0);
    MvcFramework::GetGigPerformerApi().setPluginParameter(PLUGIN_NAME, PLUGIN_PARAMETERS_UPPDR_DRAWBARS_OFFSET,
                                                          drawbarValue, true);
    Debug::Log("$ Plugin: " + PLUGIN_NAME + ", drawbar 1 = " + std::to_string(drawbarValue));
}

void OrganPlugin::SetRotatorSpeed()
{
    double rotatorSpeedFast = GetView().GetModel().GetOrganSubModel().IsRotatorSpeedFast();
    MvcFramework::GetGigPerformerApi().setPluginParameter(PLUGIN_NAME, PLUGIN_PARAMETER_ROTATOR_SPEED, rotatorSpeedFast,
                                                          true);
    Debug::Log("$ Plugin: " + PLUGIN_NAME + ", rotator speed fast = " + std::to_string(rotatorSpeedFast));
}
