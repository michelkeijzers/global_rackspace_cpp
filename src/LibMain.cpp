#include "LibMain.h"

#include "Utilities/Debug.h"
#include "Widgets/WidgetsListener.h"
#include <cstdint>
#include <memory>


using GPUtils = gigperformer::sdk::GPUtils;

template <typename T> void Ignore(T const &) noexcept
{
}

// define an XML string describing your product
const std::string XMLProductDescription = "<Library>"
                                          "  <Product "
                                          "    Name=\"Live Panel Extension\""
                                          "    Version=\"0.1\""
                                          "    BuildDate=\"02/02/2023\">"
                                          "  </Product> "
                                          "  <Description>Global Rackspace for GigPerformer</Description>"
                                          "  <ImagePath>/Path/To/ImageFile/foo.jpg</ImagePath>"
                                          "</Library>";

std::string pathToMe;

void LibMain::OnModeChanged(int mode)
{
    consoleLog(std::string(" Switching to mode: ") + ((mode == GP_SetlistMode) ? "Setlist" : "FrontBack"));
}

void LibMain::OnSwitchToPanelView()
{
    consoleLog(" Switching to panel view");
    setPlayheadState(true);

    int count = getPluginParameterCount("Legend", false);
    consoleLog(std::to_string(count));

    std::string p1 = getPluginParameterName("Legend", 1, false);
    consoleLog(p1);
}

void LibMain::OnSwitchToWiringView()
{
    consoleLog(" Switching to wiring view");
    setPlayheadState(false);

    setBPM(99);
}

void LibMain::OnGlobalPlayStateChanged(bool playing)
{
    Ignore(playing);
}

void LibMain::OnWidgetValueChanged(const std::string &widgetName, double newValue)
{
    _mvcFramework.GetWidgetsListener().OnWidgetValueChanged(widgetName, newValue);

    // int noteNumber = (int)GPUtils::Scale(newValue, 0.0, 1.0, 36, 96);
    // GPMidiMessage n = GPMidiMessage::makeNoteOnMessage(noteNumber, 64, 0);
    // const std::string device = "MIDI Monitor (Untitled)";
    // sendMidiMessageToMidiOutDevice(device, n);
}

bool LibMain::OnMidiIn(const std::string &deviceName, const uint8_t *data, int length)
{
    return _mvcFramework.GetController().OnMidiIn(deviceName, data, length);
}

void LibMain::OnMidiDeviceListChanged(std::vector<std::string> &inputs, std::vector<std::string> &outputs)
{
    for (std::size_t i = 0; i < inputs.size(); i++)
    {
        std::string &name = inputs[i];
        consoleLog("Input found: " + name);
    }

    Ignore(outputs);
}

void LibMain::OnWidgetCaptionChanged(const std::string &widgetName, const std::string &newCaption)
{
    Ignore(widgetName);
    consoleLog("Widget caption changed: " + newCaption);
}

void LibMain::OnSongChanged(int oldIndex, int newIndex)
{
    _mvcFramework.GetController().Init();
}

void LibMain::OnWidgetStateChanged(const std::string &widgetName, int newState)
{
    consoleLog("Widget " + widgetName + ": " + ((newState == 0) ? "created" : "removed"));
}

void LibMain::Initialization()
{
    // Do any initialization that you need
    Debug::SetGigPerformerApi(this);
    Debug::LogHeaders(true);

    _mvcFramework.Init();

    // Finally, register all the methods that you are going to actually use,
    // i.e, the ones you declared above as override
    registerCallback("OnSongChanged");
    registerCallback("OnStatusChanged");
    registerCallback("OnMidiIn");
    registerCallback("OnMidiDeviceListChanged");
    registerCallback("OnWidgetValueChanged");
    registerCallback("OnWidgetStateChanged");
    registerCallback("OnWidgetCaptionChanged");
    registerCallback("OnGlobalPlayStateChanged");
    registerCallback("OnModeChanged");
    registerCallback("OnSwitchToPanelView");
    registerCallback("OnSwitchToWiringView");
    registerCallback("OnTempoChanged");
    registerCallback("OnSetlistChanged");
    registerCallback("OnRackspaceActivated");

	 //TODO: not printed (probably GP clears screen afterwards)
	 consoleLog("------------------------------------------");
    consoleLog("Version 0.02");
    consoleLog("path to library " + getPathToMe());
    consoleLog("------------------------------------------");
}

std::string LibMain::GetProductDescription()
{
    return XMLProductDescription;
}

MvcFramework *LibMain::GetMvcFramework()
{
    return &_mvcFramework;
}

namespace gigperformer
{
namespace sdk
{
GigPerformerAPI *CreateGPExtension(LibraryHandle handle)
{
    return new LibMain(handle);
}
} // namespace sdk
} // namespace gigperformer
