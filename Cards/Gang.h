#include "Battle.h"
#include "Player.h"
#include <deque>
#include <memory>

class Gang : public Battle
{
    std::deque<shared_ptr<Battle>> m_gang;

    public :
    Gang();
    void applyEncounter(Player& player) const override;
}