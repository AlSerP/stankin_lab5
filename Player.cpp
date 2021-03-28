#include "Player.h"
#include <iostream>

using namespace std;

void Player::tac_move(GameField& field) const {
	int x = 0;
	int y = 0;

	bool input_correctness = false;

	while (!input_correctness) {
		cout << "\e[0;33mYou is 'O'\e[0m\n";
		cout << "Choose your move: x y\n";

		string move;
		getline(cin, move);

		x = static_cast<int>(move[0]) - static_cast<int>('0');
		y = static_cast<int>(move[2]) - static_cast<int>('0');

		input_correctness = x > 0 && x < 4 && y > 0 && y < 4;
		if (!input_correctness)
			cout << "Incorrect input. Try again\n";
		if (!field.is_free(x, y)) {
			cout << "You can't place O there\n";
			input_correctness = false;
		}
	}

	field.set_tac(x, y);
}

void Player::tic_move(GameField &field) const {
	int x = 0;
	int y = 0;

	bool input_correctness = false;

	while (!input_correctness) {
		cout << "\e[0;32mYou is 'X'\e[0m\n";
		cout << "Choose your move: x y\n";

		string move;
		getline(cin, move);

		x = static_cast<int>(move[0]) - static_cast<int>('0');
		y = static_cast<int>(move[2]) - static_cast<int>('0');

		input_correctness = x > 0 && x < 4 && y > 0 && y < 4;
		if (!input_correctness)
			cout << "Incorrect input. Try again\n";
		if (!field.is_free(x, y)) {
			cout << "You can't place X there\n";
			input_correctness = false;
		}
	}

	field.set_tic(x, y);
}


Player::Player() {
	this->is_tic = true;
}
Player::Player(bool is_tic) {
	this->is_tic = is_tic;
}
void Player::do_move(GameField &field) {
	if (this->is_tic)
		this->tic_move(field);
	else
		this->tac_move(field);
}
