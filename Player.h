#pragma once
#include "GameField.h"
#include "VirtualPlayer.h"

class Player: public VirtualPlayer
{
private:
  void tac_move(GameField& field) const;
	void tic_move(GameField& field) const;
public:
	Player();
  Player(bool is_tic);
	void do_move(GameField& field);
};
