#pragma once

#include "SubControllers.h"
#include <string>

class PrimaryKeyboardMidiInBlock;
class Model;
class View;
class WidgetsListener;

class Controller
{
  public:
    Controller(Model &model, View &view);
    ~Controller();

    Model &GetModel();
    View &GetView();

    bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

    void Fill();
    void Init();

    SubController &GetSubControllerById(SubControllers::ESubControllerId id);

  private:
    Model &_model;
    View &_view;

    SubControllers _subControllers;

    PrimaryKeyboardMidiInBlock *_primaryKeyboardMidiInBlock; // TODO: Make sub controller list, enum for type ?
};
