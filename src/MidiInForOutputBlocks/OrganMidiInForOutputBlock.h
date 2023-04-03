#include "../View/ChangedProperties.h"
#include "../View/IObserver.h"
#include <string>
#include "MidiInForOutputBlock.h"

class View;
class OrganSubModel;

class OrganMidiInForOutputBlock : public MidiInForOutputBlock, IObserver
{
 public:
   OrganMidiInForOutputBlock(OrganSubModel &organSubModel, const std::string &name);
   virtual void Init();

   void Update(ChangedProperties::EChangedProperty changedProperty);

 protected:
   void HandleNoteOff();
   void HandleNoteOn();
   void HandleSustained();

 private:
   void HandleNoteOnOff(bool noteOn);

   OrganSubModel &_organSubModel;
};
