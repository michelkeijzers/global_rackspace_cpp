#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
#include "../Model/Model.h"
#include "../Plugins/AudioMixerPlugin.h"
#include "../Plugins/OrganPlugin.h"
#include "../Utilities/Debug.h"
#include "Controller.h"

Controller::Controller(Model &model, View &view)
    : _model(model), _view(view), _mixerSubController(nullptr), _organSubController(nullptr),
      _primaryKeyboardMidiInBlock(nullptr)
{
}

Controller::~Controller()
{
    if (_mixerSubController != nullptr)
    {
        delete _mixerSubController;
        _mixerSubController = nullptr;
    }

    if (_organSubController != nullptr)
    {
        delete _organSubController;
        _organSubController = nullptr;
    }

	 if (_primaryKeyboardMidiInBlock != nullptr)
    {
         delete _primaryKeyboardMidiInBlock;
        _primaryKeyboardMidiInBlock = nullptr;
    }
}

void Controller::FillControllers()
{
    // TODO: Create plugins in specific controller classes, not here.
    // std::shared_ptr<AudioMixerPlugin> audioMixerChannels1To16Plugin = std::make_shared<AudioMixerPlugin>(this, true);
    // std::shared_ptr<AudioMixerPlugin> audioMixerChannels17To23Plugin = std::make_shared<AudioMixerPlugin>(this,
    // false);
    _mixerSubController = new MixerSubController(*this);

    // std::shared_ptr<OrganPlugin> organPlugin = std::make_shared<OrganPlugin>(this, );
    _organSubController = new OrganSubController(*this);
}

void Controller::FillMidiInBlocks()
{
    _primaryKeyboardMidiInBlock = new PrimaryKeyboardMidiInBlock(*this) ;
}

void Controller::Init()
{
    // TODO: make sub controller list???, iterate through it
    _organSubController->Init();
}

Model &Controller::GetModel()
{
    return _model;
}

View &Controller::GetView()
{
    return _view;
}

MixerSubController &Controller::GetMixerSubController()
{
    return *_mixerSubController;
}

OrganSubController &Controller::GetOrganSubController()
{
    return *_organSubController;
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
