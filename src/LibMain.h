#pragma once

#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>

#include <utility> //declarations of unique_ptr
// using std::unique_ptr;

#include "gigperformer/sdk/GPMidiMessages.h"
#include "gigperformer/sdk/GPUtils.h"
#include "gigperformer/sdk/GigPerformerAPI.h"
#include "gigperformer/sdk/types.h"

#include "Framework/MvcFramework.h"

class LibMain : public gigperformer::sdk::GigPerformerAPI
{
  protected:
	private:
     MvcFramework _mvcFramework;

	  MvcFramework *GetMvcFramework();

  public:
    // These must be here but no need to do anything unless you want extra behavior
    explicit LibMain(LibraryHandle handle)
		 : GigPerformerAPI(handle)
    {
    }

#pragma warning(push)
#pragma warning(disable : 26812)
    void OnStatusChanged(GPStatusType status) override
#pragma warning(pop)
    {
        consoleLog("Gig status changed to " + std::to_string(status));
    }

    void OnRackspaceActivated() override
    {
        consoleLog("Rackspace activated");
    }

    void OnSetlistChanged(const std::string &newSetlistName) override
    {
        consoleLog("Setlist switched to: " + newSetlistName);
    }

    void OnModeChanged(int mode) override;

    void OnSwitchToPanelView() override;

    void OnSwitchToWiringView() override;

    void OnTempoChanged(double) override
    {
        consoleLog("Tempo changed");
    }

    void OnGlobalPlayStateChanged(bool playing) override;

    // Now, simply override the callback methods in which you are interested
    // and, in the Initialization method at the end of this class,
    // call RegisterCallback for each of these methods

    void OnWidgetValueChanged(const std::string &widgetName, double newValue) override;

    bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

    // A midi device was added or removed
    void OnMidiDeviceListChanged(std::vector<std::string> &inputs, std::vector<std::string> &outputs) override;

    void OnWidgetCaptionChanged(const std::string &widgetName, const std::string &newCaption) override;

    void OnSongChanged(int oldIndex, int newIndex) override;

    void OnWidgetStateChanged(const std::string &widgetName, int newState) override;

    void Initialization() override;

    std::string GetProductDescription() override;
};
