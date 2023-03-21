#include "../Framework/MvcFramework.h"
#include "../Model/KeyboardSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include "../View/ChangedProperties.h"
#include "KeyboardPlugin.h"
#include <iostream>
#ifdef TESTER
    #include "../../../JuceTester2/NewProject/Source/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

KeyboardPlugin::KeyboardPlugin(View &view, KeyboardSubModel &keyboardSubModel, const std::string &name)
    : Plugin(name, view), _keyboardSubModel(keyboardSubModel)
{
    _keyboardSubModel.Subscribe(*this);
}

void KeyboardPlugin::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
}

