#pragma once

#include <memory>
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
    Controller(std::shared_ptr<Model> model, std::shared_ptr<View> view);

    std::shared_ptr<Model> GetModel();
    std::shared_ptr<View> GetView();

    std::shared_ptr<MixerSubController> GetMixerSubController();
    std::shared_ptr<OrganSubController> GetOrganSubController();

    bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

    void FillControllers();
    void FillMidiInBlocks();
    void Init();

  private:
    std::shared_ptr<Model> _model;
    std::shared_ptr<View> _view;

    std::shared_ptr<MixerSubController> _mixerSubController;
    std::shared_ptr<OrganSubController> _organSubController;

    std::shared_ptr<PrimaryKeyboardMidiInBlock>
        _primaryKeyboardMidiInBlock; // Make sub controller list, enum for type ?

    std::shared_ptr<WidgetsListener> _widgetsListener;
};
