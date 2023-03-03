#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
#include "../Model/Model.h"
#include "../Plugins/AudioMixerPlugin.h"
#include "../Plugins/OrganPlugin.h"
#include "../Utilities/Debug.h"
#include "Controller.h"

Controller::Controller(Model &model, View &view)
    : _model(model), _view(view), 
      _primaryKeyboardMidiInBlock(nullptr), _subControllers(*this)
{
}

Controller::~Controller()
{
}

void Controller::Fill()
{
    _subControllers.Fill();

	 _primaryKeyboardMidiInBlock = new PrimaryKeyboardMidiInBlock(*this);
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
    bool processed = false;

    if (deviceName == "PrimaryKeyboardMidiInBlock") // TODO: Move to constant
    {
        processed = _primaryKeyboardMidiInBlock->OnMidiIn(data, length);
    }
    else if (deviceName == "SecondaryKeyboardMidiInBlock")
    {
        // TODO Handle notes for hammond?
    }
    else if (deviceName == "Fcb1010MidiInBlock")
    {
        // TODO Handle sustain, organ rotator switch
    }
    else
    {
        Debug::Error(__FUNCTION__, "Illegal device name: " + deviceName);
    }

    return processed;
}
