#ifndef AI_H
#define AI_H

#include <iostream>
#include "Board.h"


class Ai{
 public:
  Ai();
  ~Ai();
 private:
  void aiTurn(int difficulty, Board p1);
  void aiTurnEasy(Board p1);
  void aiTurnMedium(Board p1);
  void aiTurnHard(Board p1);        
};

#endif
