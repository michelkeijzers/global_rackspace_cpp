#include "Controller.h"
#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
#include "../Model/Model.h"
#include "../Plugins/AudioMixerPlugin.h"
#include "../Plugins/OrganPlugin.h"
#include "../Utilities/Debug.h"

Controller::Controller(Model &model, View &view) 
	: _model(model), _view(view), _subControllers(*this), _midiInBlocks(*this)
{
}

Controller::~Controller()
{
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

SubController &Controller::GetSubControllerById(SubControllers::ESubControllerId id)
{
    return _subControllers.GetSubControllerById(id);
}

bool Controller::OnMidiIn(const std::string &deviceName, const uint8_t *data, int length)
{
    return _midiInBlocks.OnMidiIn(deviceName, data, length);
}
