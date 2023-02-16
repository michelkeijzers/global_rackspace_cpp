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

// MVC
#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"
#include <memory>

class LibMain : public gigperformer::sdk::GigPerformerAPI
{
  protected:
    int GetPanelCount() override;
    std::string GetPanelName(int index) override;
    std::string GetPanelXML(int index) override;

    // These are for creating menu items in Gig Performer that can be used to
    // trigger external functions provided by the extension developer
    int GetMenuCount() override;
    std::string GetMenuName(int index) override;
    void InvokeMenu(int itemIndex) override;


  public:
    // These must be here but no need to do anything unless you want extra behavior
    explicit LibMain(LibraryHandle handle)
		 : GigPerformerAPI(handle),
		  _controller(nullptr), _model(nullptr), _view(nullptr)
    {
    }

    ~LibMain() override
    {
        delete _controller;
        delete _model;
        delete _view;
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

    int RequestGPScriptFunctionSignatureList(GPScript_AllowedLocations location,
                                             ExternalAPI_GPScriptFunctionDefinition **list) override;

    // This MUST be defined in your class
    std::string GetProductDescription() override;

    // MVC
    Model* _model;
    View* _view;
    Controller* _controller;
};
