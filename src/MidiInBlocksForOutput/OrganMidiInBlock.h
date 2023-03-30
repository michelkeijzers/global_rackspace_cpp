#include "../View/ChangedProperties.h"
#include "../View/IObserver.h"
#include <string>

class View;
class OrganSubModel;

class OrganMidiInBlock : public IObserver
{
   OrganMidiInBlock(View &view, OrganSubModel &organSubModel, const std::string &name);
   virtual void Init();
   const std::string GetName();

   void Update(ChangedProperties::EChangedProperty changedProperty);

 protected:
   void HandleNoteOff();
   void HandleNoteOn();
   View &GetView();

 private:
   void HandleNoteOnOff(bool noteOn);

	const std::string _name;
   View &_view;
   OrganSubModel &_organSubModel;
};
