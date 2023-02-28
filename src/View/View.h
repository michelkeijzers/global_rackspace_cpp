#pragma once

#include "../Widgets/Widgets.h"
#include <memory>
#include <vector>

class gigperformer::sdk::GigPerformerAPI;
class Model;
class Pane;
class Plugin;

class View
{
  public:
    View(std::shared_ptr<Model> model, gigperformer::sdk::GigPerformerAPI *gig_performer_api);

    void FillWidgets();
    void Init(); // TODO: Change to relayout

    Widgets *GetWidgets();

  private:
    std::vector<std::shared_ptr<Pane>> _panes; //TODO: make separate Panes class

	 std::vector<std::shared_ptr<Plugin>> _plugins; //TODO: Make separate Plugins class

    Widgets _widgets;
};
