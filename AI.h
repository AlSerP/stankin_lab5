#pragma once
#include "GameField.h"
#include "VirtualPlayer.h"

class AI: public VirtualPlayer
{
private:
	void tic_move(GameField& field) const;
	void tac_move(GameField& field) const;
public:
	AI(bool is_tic);
	void do_move(GameField& field);
};
