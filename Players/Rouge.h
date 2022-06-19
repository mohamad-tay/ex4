#ifndef EX4_ROUGE_H
#define EX4_ROUGE_H

class Rouge : public Player {
public:
  void addCoins(int const coins) override;
  friend std::ostream& operator<<(std::ostream& os, const Rogue& r);
}


#endif //EX4_ROUGE_H
