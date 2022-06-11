#include "Fighter.h"

int Fighter::getAttackStrength()
  {
     int attackStrength = m_level + 2*m_force;
     return attackStrength;
  }