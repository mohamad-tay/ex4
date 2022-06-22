#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include "Player.h"

class Rogue : public Player {
public:
  Rogue(const std::string& name);
  void addCoins(int const coins) override;
  friend std::ostream& operator<<(std::ostream& os, const Rogue& r);
  virtual void abstract() override;
};


#endif //EX4_ROGUE_H
