#include <memory>
#include "Controller.h"
#include "../Plugins/OrganPlugin.h"
#include "../MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
#include "../Controller/OrganController.h"

Controller::Controller(std::shared_ptr<Model> model, std::shared_ptr<View> view)
    : _model(model), _view(view), _organController(nullptr), _primaryKeyboardMidiInBlock(nullptr)
{
}


void Controller::FillControllers()
{
    std::shared_ptr<OrganPlugin> organPlugin = std::make_shared<OrganPlugin>("OrganPlugin");
    _organController = std::make_shared<OrganController>(this, organPlugin);
}


void Controller::FillMidiInBlocks()
{
    _primaryKeyboardMidiInBlock = std::make_shared<PrimaryKeyboardMidiInBlock>(this);
}


std::shared_ptr<Model> Controller::GetModel()
{
    return _model;
}


std::shared_ptr<View> Controller::GetView()
{
    return _view;
}


std::shared_ptr<OrganController> Controller::GetOrganController()
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