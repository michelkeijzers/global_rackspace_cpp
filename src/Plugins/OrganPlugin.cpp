#include "OrganPlugin.h"
#include "../Utilities/BoolUtilities.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/Debug.h"
#include <iostream>
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

OrganPlugin::OrganPlugin(View *view, std::shared_ptr<OrganSubModel> organSubModel)
    : Plugin("Organ", view)
{
    organSubModel->Subscribe(*this);
}

void OrganPlugin::Update(const std::string &changedProperty) /* override */
{
    if (changedProperty == "Drawbar1")
    {
        MvcFramework::GetGigPerformerApi()->setPluginParameter("Organ", 10, 0.3, true); //TODO: Use abstraction ???
        Debug::Log("SetPluginParameter: Organ 10 0.3 true");
	 }
}

void OrganPlugin::SetDrawbarValue(int drawbarIndex, double newValue)
{
    Debug::LogMethodEntry(__FUNCTION__, "DrawbarIndex = " + std::to_string(drawbarIndex) +
                                            ", newValue = " + std::to_string(newValue));

	 MvcFramework::GetGigPerformerApi()->setPluginParameter(GetName(), 16 + drawbarIndex, newValue,
                                                              true); // TODO: Check number + make const

    Debug::LogMethodExit(__FUNCTION__);
}

void OrganPlugin::SetRotatorSpeedFast(bool fast)
{
    Debug::LogMethodEntry(__FUNCTION__, "fast: " + std::to_string(fast));

    MvcFramework::GetGigPerformerApi()->setPluginParameter(GetName(), 8, BoolUtilities::ToDouble(fast), true); // TODO: Make const

    Debug::LogMethodExit(__FUNCTION__);
}
