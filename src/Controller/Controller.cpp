#include "Controller.h"
#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../MidiInBlocks/PrimaryKeyboardMidiInBlock.h"
#include "../Model/Model.h"
#include "../Plugins/AudioMixerPlugin.h"
#include "../Plugins/OrganPlugin.h"
#include "../Utilities/Debug.h"
#include "../Utilities/IntUtilities.h"
#include "../Framework/MvcFramework.h"
#ifdef TESTER
    #include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

Controller::Controller(Model &model, View &view)
    : _model(model), _view(view), _subControllers(*this), _midiInBlocks(*this)
{
    StartTimer();
}

Controller::~Controller()
{
    juce::HighResolutionTimer::stopTimer();
}

void Controller::StartTimer()
{
    juce::HighResolutionTimer::startTimer(1000);
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

void Controller::OnSongChanged(int oldIndex, int newIndex)
{
	
    _model.LoadSong();//TODO
}

void Controller::OnPreviousSong()
{
    _model.LoadSong(); //TODO
}

void Controller::OnNextSong()
{
    _model.LoadSong();//TODO
}

void Controller::WriteSong()
{
    _model.WriteSong();
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

void Controller::hiResTimerCallback() // override
{
     // Debug::Log("#Callback 1Hz");  This gives focus to the script logger window every second
     _model.OnTimer(Model::ETimer::OneSecond);
}

std::string Controller::GetCurrentSongName()
{
     int songIndex = MvcFramework::GetGigPerformerApi().getCurrentSongIndex();
     return MvcFramework::GetGigPerformerApi().getSongName(songIndex);
}
