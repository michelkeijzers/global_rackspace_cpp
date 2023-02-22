#pragma once

class MixerChannel
{
  public:
    MixerChannel();

    double GetVolume();
    void SetVolume(double volume);

  private:
    double _volume;
};