#include "Controller.h"
#include "../Plugins/OrganPlugin.h"
#include "../MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
#include "../Controller/OrganController.h"

Controller::Controller(Model* model, View* view)
    : _model(model), _view(view), _organController(nullptr), _primaryKeyboardMidiInBlock(nullptr)
{
}


Controller::~Controller()
{
    delete _organController;
    delete _primaryKeyboardMidiInBlock;
}


void Controller::FillControllers()
{
    OrganPlugin* organPlugin = new OrganPlugin("OrganPlugin"); // Delete somewhere, change to class var
    _organController = new OrganController(this, organPlugin);
}


void Controller::FillMidiInBlocks()
{
    _primaryKeyboardMidiInBlock = new PrimaryKeyboardMidiInBlock(this);
}


Model* Controller::GetModel()
{
    return _model;
}


OrganController* Controller::GetOrganController()
{
    return _organController;
}


bool Controller::OnMidiIn(const std::string &deviceName, const uint8_t *data, int length)
{
    bool processed = false;

    if (deviceName == "PrimaryKeyboardMidiInBlock")
    {
        processed = _primaryKeyboardMidiInBlock->OnMidiIn(data, length);
    }
    else if (deviceName == "SecondaryKeyboardMidiInBlock")
    {
        // TODO
    }
    else if (deviceName == "Fcb1010MidiInBlock")
    {
        // TODO
    }
    else
    {
        // TODO: Error
    }

    return processed;
}