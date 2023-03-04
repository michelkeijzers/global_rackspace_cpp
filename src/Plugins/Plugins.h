#pragma once

#include <vector>

class Plugin;
class Model;
class View;

class Plugins
{
  public:
    enum class EPluginId
    {
	          Organ
    };

    Plugins(Model &model, View &view);
    ~Plugins();

	 void Fill();
    void Init();
    
	 Plugin &GetPlugin(EPluginId organ);

private:
    std::vector<Plugin *> _plugins;

	 Model &_model;
    View &_view;
};
