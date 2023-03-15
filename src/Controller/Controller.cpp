#include "Controller.h"
#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
#include "../Model/Model.h"
#include "../Plugins/AudioMixerPlugin.h"
#include "../Plugins/OrganPlugin.h"
#include "../Utilities/Debug.h"
#include "../Utilities/IntUtilities.h"

Controller::Controller(Model &model, View &view)
    : _model(model), _view(view), _subControllers(*this), _midiInBlocks(*this)
{
    juce::Timer::startTimerHz(1);
}

Controller::~Controller()
{
    juce::Timer::stopTimer();
}

void Controller::Fill()
{
    _subControllers.Fill();
    _midiInBlocks.Fill();
}

void Controller::Init()
{
    _subControllers.Init();
}

Model &Controller::GetModel()
{
    return _model;
}

View &Controller::GetView()
{
    return _view;
}

SubController &Controller::GetSubController(SubControllers::ESubControllerId id)
{
    return _subControllers.GetSubController(id);
}

bool Controller::OnMidiIn(const std::string &deviceName, const uint8_t *data, int length)
{
    Debug::Log("@--- On Midi In: Device Name = " + deviceName + ", data = " + ConvertDataToString(data, length));

    return _midiInBlocks.OnMidiIn(deviceName, data, length);
}

const std::string Controller::ConvertDataToString(const uint8_t *data, int length)
{
    std::string hexString = "[";
    for (int itemIndex = 0; itemIndex < length; itemIndex++)
    {
        hexString += IntUtilities::ToHexString(data[itemIndex]);
        if (itemIndex < length - 1)
        {
            hexString += ", ";
        }
    }
    hexString += ']';

	 return hexString;
}

void Controller::timerCallback() // override
{
     Debug::Log("#Callback 1Hz");
     _model.OnTimer(Model::ETimer::OneSecond);
}
