#pragma once

#include <string>

class MixerSubController;
class OrganSubController;
class PrimaryKeyboardMidiInBlock;
class Model;
class View;
class WidgetsListener;

class Controller
{
  public:
    Controller(Model& model, View& view);
    ~Controller();

    Model& GetModel();
    View& GetView();

    MixerSubController& GetMixerSubController();
    OrganSubController& GetOrganSubController();

    bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

    void FillControllers();
    void FillMidiInBlocks();
    void Init();

  private:
    Model& _model;
    View& _view;

    MixerSubController* _mixerSubController;
    OrganSubController* _organSubController;

    PrimaryKeyboardMidiInBlock* _primaryKeyboardMidiInBlock; // Make sub controller list, enum for type ?
};
