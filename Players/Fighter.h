#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

class Fighter : public Player {
public:
   int getAttackStrength() override;
   std::ostream& operator<<(std::ostream& os, const Fighter& r)
}


#endif //EX4_FIGHTER_H