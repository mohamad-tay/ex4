#include "Wizard"

void Wizard::heal(int const extraHp)
{
     if (extraHp<=0)                   // ??
     {
        return;
     }
     if((m_hp+2*extraHp)>m_maxHp)                            
     {
        m_hp = m_maxHp;
     }
     else
     {
        m_hp += 2*extraHp;
     }
}