#pragma once

#include <memory>
#include <string>

#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif


class OrganController;
class PrimaryKeyboardMidiInBlock;
class Model;
class View;
class WidgetsListener;


class Controller 
{
  public:
    Controller(std::shared_ptr<Model> model, std::shared_ptr<View> view,
               gigperformer::sdk::GigPerformerAPI *gigPerformerApi);
    
    std::shared_ptr<Model> GetModel();
    std::shared_ptr<View> GetView();

    std::shared_ptr<OrganController> GetOrganController();

	 gigperformer::sdk::GigPerformerAPI *GetGigPerformerAPI();

    bool OnMidiIn(const std::string &deviceName, const uint8_t *data, int length);

	 void FillControllers();
    void FillMidiInBlocks();

  private:
    std::shared_ptr<Model> _model;
    std::shared_ptr<View> _view;

    std::shared_ptr<OrganController> _organController;

	 std::shared_ptr<PrimaryKeyboardMidiInBlock> _primaryKeyboardMidiInBlock;

	 std::shared_ptr<WidgetsListener> _widgetsListener;

	 gigperformer::sdk::GigPerformerAPI *_gigPerformerApi;
};