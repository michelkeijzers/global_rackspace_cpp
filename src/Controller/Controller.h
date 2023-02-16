#pragma once

#include <string>

class OrganController;
class PrimaryKeyboardMidiInBlock;
class Model;
class View;

class Controller
{
  public:
    Controller(Model* model, View* view);
    ~Controller();

    Model* GetModel();

    OrganController* GetOrganController();

    bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

	 void FillControllers();
    void FillMidiInBlocks();

  private:
    Model* _model;
    View* _view;

    OrganController* _organController;

	 PrimaryKeyboardMidiInBlock* _primaryKeyboardMidiInBlock;
};