#include "../View/ChangedProperties.h"
#include <string>
#include "../View/IObserver.h"

class View;
class OrganSubModel;

class OrganMidiInBlock : public IObserver
{
   OrganMidiInBlock(View &view, OrganSubModel &organSubModel, const std::string &name);
   virtual void Init();
   const std::string GetName();

   void Update(ChangedProperties::EChangedProperty changedProperty);
   void HandleNoteOnOff(bool noteOn);

 protected:
   View &GetView();

 private:
   const std::string _name;
   View &_view;
   OrganSubModel &_organSubModel;
};