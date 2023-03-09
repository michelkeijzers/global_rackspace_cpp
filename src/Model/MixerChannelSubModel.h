#pragma once

#include "../View/Observable.h"
#include "MixerChannelSubModel.h"
#include "SubModel.h"
#include <string>

class SubModels;

class MixerChannelSubModel : public SubModel, public Observable
{
  public:
    enum class ESource
    {
        PrimaryKeyboard,
        PrimaryKeyboardPads,
        SecondaryKeyboard,

		  Last
    };

    MixerChannelSubModel(SubModels subModels, int channelIndex);

    double GetVolume();
    void SetVolume(double volume);

	 double GetLevelLeft();
    void SetLevelLeft(double level);

    double GetLevelRight();
    void SetLevelRight(double level);
    
	 bool GetGateLeft();
    void SetGateLeft(bool level);

    bool GetGateRight();
    void SetGateRight(bool level);
    
	 const std::string &GetName();
    void SetName(const std::string &name);

	 ESource GetSource();
    std::string GetSourceName();
    void SelectNextSource();

	 bool IsVolumeOverridden();
    void SwapVolumeOverride();

  private:
    int _channelIndex;
    double _volume;
    double _levelLeft;
    double _levelRight;
    bool _gateLeft;
    bool _gateRight;
    
	 std::string _name;
    ESource _source;
     bool _isVolumeOverridden;
};
