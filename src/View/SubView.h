#pragma once

#include "Panes/Panes.h"

class Model;
class View;

class SubView
{
 public:
   SubView(Model &model, View &view);
	virtual void Fill();
   virtual void Init();

 protected:
   Panes &GetPanes();
   View &GetView();
   Model &GetModel();

 private:
   Panes _panes;
   View &_view;
   Model &_model;
};
