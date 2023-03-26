#pragma once

#include <vector>

class Model;
class View;
class Pane;

class Panes
{
 public:
   Panes(Model &model, View &view);
   ~Panes();

   void Fill();
   void Init();

	void AddPane(Pane *pane);

 private:
   std::vector<Pane *> _panes;

   Model &_model;
   View &_view;
};
