#include <iostream>
#include "GameField.h"

using namespace std;

GameField::GameField() {
	for (int i = 0; i < 9; i++)
		field[i] = -1;
}
GameField::GameField(string str_field) {
	for (int i = 0; i < 9; i++)
		field[i] = int(str_field[i]) - int('0') - 1;
}
int GameField::set_tic(int x, int y) {
	int id = (x - 1) + (y - 1) * 3;
	if (field[id] == -1) {
		field[id] = 1;
		free_squares--;
		return 0;
	}
	return 1;
}
int GameField::set_tac(int x, int y) {
	int id = (x - 1) + (y - 1) * 3;
	if (field[id] == -1) {
		field[id] = 0;
		free_squares--;
		return 0;
	}
	return 1;
}

void GameField::show_line(int line_num) const {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			if (field[j + (line_num - 1) * 3] == 1) {
        cout << "\e[0;32m";
				switch (i) {
				case 0:
					cout << "      ";
					break;
				case 1:
					cout << " \\  / ";
					break;
				case 2:
					cout << "  \\/  ";
					break;
				case 3:
					cout << "  /\\  ";
					break;
				case 4:
					cout << " /  \\ ";
					break;
				}
        cout << "\e[0m";
      }
			if (field[j + (line_num - 1) * 3] == 0) {
        cout << "\e[0;33m";
				switch (i) {
				case 0:
					cout << "  __  ";
					break;
				case 1:
					cout << " /  \\ ";
					break;
				case 2:
					cout << " |  | ";
					break;
				case 3:
					cout << " |  | ";
					break;
				case 4:
					cout << " \\__/ ";
					break;
				}
        cout << "\e[0m";
      }
			if (field[j + (line_num - 1) * 3] == -1)
				cout << "      ";
			if (j != 2)
				cout << '|';
		}
		cout << '\n';
	}
}

void GameField::show() const {
	this->show_line(1);
	cout << "______|______|______\n";
	this->show_line(2);
	cout << "______|______|______\n";
	this->show_line(3);
	cout << '\n';

}
int GameField::check() {
	int win = -1;
	// Columns
	for (int x = 0; x < 3; x++) {
		if (field[x] == field[x + 3] && field[x + 3] == field[x + 6]) {
			if (field[x] == 1)
				win = 1;
			if (field[x] == 0)
				win = 0;
		}
	}
	// Lines
	for (int y = 1; y < 4; y++) {
		if (field[(y - 1) * 3] == field[1 + (y - 1) * 3] && field[1 + (y - 1) * 3] == field[2 + (y - 1) * 3]) {
			if (field[(y - 1) * 3] == 1)
				win = 1;
			if (field[(y - 1) * 3] == 0)
				win = 0;
		}
	}
	// Side diagonal
	if (field[0] == field[4] && field[4] == field[8]) {
		if (field[0] == 1)
			win = 1;
		if (field[0] == 0)
			win = 0;
	}
	// Side diagonal
	if (field[2] == field[4] && field[4] == field[6]) {
		if (field[2] == 1)
			win = 1;
		if (field[2] == 0)
			win = 0;
	}

	if (win == 1)
		cout << "\e[0;32mTic wins!\e[0m\n";
	if (win == 0)
		cout << "\e[0;33mToe wins!\e[0m\n";
	if (free_squares == 0 && win == -1) {
		cout << "Draw\n";
		win = 2;
	}
	return win;
}
bool GameField::is_free(int x, int y) {
	return field[(x - 1) + (y - 1) * 3] == -1;
}
string GameField::to_string() const {
	string result = "";
	for (int i = 0; i < 9; i++)
		result += char(field[i] + int('0') + 1);

	return result;
}
// \e[0;32m \e[0m