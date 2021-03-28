#include "AI.h"
#include <iostream>

using namespace std;

void AI::tac_move(GameField &field) const {
	int i;
	do {
		i = rand() % 9;
	} while (!field.is_free(i % 3 + 1, i / 3 + 1));
	cout << "HI1\n";
	
	field.set_tac(i % 3 + 1, i / 3 + 1);		
}

void AI::tic_move(GameField &field) const {
	int i;
	do {
		i = rand() % 9;
	} while (!field.is_free(i % 3 + 1, i / 3 + 1));
	cout << "HI2\n";
	
	field.set_tic(i % 3 + 1, i / 3 + 1);
}


AI::AI(bool is_tic) {
	this->is_tic = is_tic;
}
void AI::do_move(GameField& field) {
	if (this->is_tic)
		this->tic_move(field);
	else
		this->tac_move(field);
}
