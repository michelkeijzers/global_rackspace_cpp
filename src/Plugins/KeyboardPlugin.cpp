#include "KeyboardPlugin.h"
#include "../Framework/MvcFramework.h"
#include "../Model/KeyboardSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"
#include "../View/ChangedProperties.h"
#include <iostream>
#ifdef TESTER
    #include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/GigPerformerAPI.h"
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
    switch (changedProperty)
    {
    case ChangedProperties::EChangedProperty::PrimaryKeyboardSustainEnabled: {
        bool isEnabled = _keyboardSubModel.IsSustainEnabled();
        uint8_t midiMessage[3];
        MidiUtilities::FillCcMessage(midiMessage, 64, MidiUtilities::BoolToMidi(isEnabled));
        MvcFramework::GetGigPerformerApi().injectMidiMessageToMidiInputDevice(GetName(), midiMessage, 3);
        Debug::Log("$ " + GetName() + ": Sustain = " + std::to_string(isEnabled));
    }
    break;
    case ChangedProperties::EChangedProperty::SecondaryKeyboardSustainEnabled: {
        bool isEnabled = _keyboardSubModel.IsSustainEnabled();
        uint8_t midiMessage[3];
        MidiUtilities::FillCcMessage(midiMessage, 64, MidiUtilities::BoolToMidi(isEnabled));
        MvcFramework::GetGigPerformerApi().injectMidiMessageToMidiInputDevice(GetName(), midiMessage, 3);
        Debug::Log("$ " + GetName() + ": Sustain = " + std::to_string(isEnabled));
    }
    break;
    }
}
