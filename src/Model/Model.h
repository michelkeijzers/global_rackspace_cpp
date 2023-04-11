#pragma once

#include "../View/Observable.h"
#include "SubModels.h"
#include <string>

class Model : public Observable
{
 public:
   enum class ETimer
   {
      OneSecond
   };

   Model();

   void Fill();
   void Init();

   void OnTimer(ETimer timer);

   SubModel &GetSubModel(SubModels::ESubModelId id);

   bool LoadSong();
   void Deserialize(std::vector<std::string> lines);
   bool WriteSong();

   const std::string &GetVersion();
   void SetVersion(const std::string &version);

   bool IsForcedMode();

 private:
   SubModels _subModels;
   std::string _version;

   bool _forcedMode;

	std::string _currentlyLoadedRackspace;
};
