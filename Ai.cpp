#include "Ai.h"


Ai::Ai(){
  std::cout<<"hello"<<std::endl;
}

Ai::~Ai(){
  std::cout<<"oof";
}

void Ai::aiTurn(int diff, Board p1){
  switch(diff){
  case 0:
    aiTurnEasy(p1);
    break;
  case 1:
    aiTurnMedium(p1);
    break;
  case 2:
    aiTurnHard(p1);
    break;
  default:
    std::cout<<"error on ai difficulty";
  }
}

void Ai::aiTurnEasy(Board p1){
}

void Ai::aiTurnMedium(Board p1){
}
void Ai::aiTurnHard(Board p1){
}

