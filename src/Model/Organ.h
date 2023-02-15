
enum class EOrganRotatorSpeed
{
    Fast,
    Slow,
    Off
};

class Organ
{
  public:
    Organ();

	 bool IsPresent();
    void SetIsPresent(bool isPresent);

    EOrganRotatorSpeed GetRotatorSpeed();
    void SetRotatorSpeed(EOrganRotatorSpeed rotatorSpeed);
    EOrganRotatorSpeed SwapRotatorSpeed();

  private:
    bool _isPresent;
    EOrganRotatorSpeed _rotatorSpeed;
};