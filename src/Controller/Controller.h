#pragma once

#include <memory>
#include <string>

class OrganController;
class PrimaryKeyboardMidiInBlock;
class Model;
class View;

class Controller 
{
  public:
    Controller(std::shared_ptr<Model> model, std::shared_ptr<View> view);
    
    std::shared_ptr<Model> GetModel();
    std::shared_ptr<View> GetView();

    std::shared_ptr<OrganController> GetOrganController();

    bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

	 void FillControllers();
    void FillMidiInBlocks();

  private:
    std::shared_ptr<Model> _model;
    std::shared_ptr<View> _view;

    std::shared_ptr<OrganController> _organController;

	 std::shared_ptr<PrimaryKeyboardMidiInBlock> _primaryKeyboardMidiInBlock;
};