#include <memory>

#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
#include "../Plugins/AudioMixerPlugin.h"
#include "../Plugins/OrganPlugin.h"
#include "../Utilities/Debug.h"
#include "Controller.h"

Controller::Controller(std::shared_ptr<Model> model, std::shared_ptr<View> view)
    : _model(model), _view(view), _organSubController(nullptr), _primaryKeyboardMidiInBlock(nullptr)
{
}

void Controller::FillControllers()
{
	//TODO: Create plugins in specific controller classes, not here.
    //std::shared_ptr<AudioMixerPlugin> audioMixerChannels1To16Plugin = std::make_shared<AudioMixerPlugin>(this, true);
    //std::shared_ptr<AudioMixerPlugin> audioMixerChannels17To23Plugin = std::make_shared<AudioMixerPlugin>(this, false);
    _mixerSubController = std::make_shared<MixerSubController>(this);

    std::shared_ptr<OrganPlugin> organPlugin = std::make_shared<OrganPlugin>(this);
    _organSubController = std::make_shared<OrganSubController>(this);
}

void Controller::FillMidiInBlocks()
{
    _primaryKeyboardMidiInBlock = std::make_shared<PrimaryKeyboardMidiInBlock>(this);
}

void Controller::Init()
{
    // TODO: make sub controller list???, iterate through it
    _organSubController->Init();
}

std::shared_ptr<Model> Controller::GetModel()
{
    return _model;
}

std::shared_ptr<View> Controller::GetView()
{
    return _view;
}

std::shared_ptr<MixerSubController> Controller::GetMixerSubController()
{
    return _mixerSubController;
}

std::shared_ptr<OrganSubController> Controller::GetOrganSubController()
{
    return _organSubController;
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