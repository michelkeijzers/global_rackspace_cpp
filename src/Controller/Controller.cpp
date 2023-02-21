#include <memory>

#include "Controller.h"
#include "../Utilities/Debug.h"
#include "../Plugins/OrganPlugin.h"
#include "../MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
#include "../Controller/OrganController.h"


Controller::Controller(std::shared_ptr<Model> model, std::shared_ptr<View> view,
                       gigperformer::sdk::GigPerformerAPI *gigPerformerApi)
    : _model(model), _view(view), _organController(nullptr), _gigPerformerApi(gigPerformerApi),
	   _primaryKeyboardMidiInBlock(nullptr)
{
}


void Controller::FillControllers()
{
    std::shared_ptr<OrganPlugin> organPlugin = std::make_shared<OrganPlugin>(this);
    _organController = std::make_shared<OrganController>(this, organPlugin);
}


void Controller::FillMidiInBlocks()
{
    _primaryKeyboardMidiInBlock = std::make_shared<PrimaryKeyboardMidiInBlock>(this);
}


void Controller::Init()
{
    // TODO: make sub controller list???
    _organController->Init();
}


std::shared_ptr<Model> Controller::GetModel()
{
    return _model;
}


std::shared_ptr<View> Controller::GetView()
{
    return _view;
}


gigperformer::sdk::GigPerformerAPI *Controller::GetGigPerformerAPI()
{
    return _gigPerformerApi;
}


std::shared_ptr<OrganController> Controller::GetOrganController()
{
    return _organController;
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
        // TODO
    }
    else if (deviceName == "Fcb1010MidiInBlock")
    {
        // TODO 
    }
    else
    {
        Debug::Error(__FUNCTION__, "Illegal device name: " + deviceName);
    }

    return processed;
}