#include <iostream>
#include <string>
#include <fstream>
#include "GameField.h"
#include "Player.h"
#include "AI.h"

using namespace std;
// 1 - tic X
// 0 - tac O

void save_game(GameField& field, int game_mode, bool is_tic, bool is_player) {
	string str_save = "";
	str_save = field.to_string() + char(game_mode + int('0')) + char(is_tic + int('0')) + char(is_player + int('0'));
	
	ofstream save_in;
	save_in.open("ttt_save.txt", ofstream::out | ofstream::trunc);
	
	save_in << str_save;
	save_in.close();
}

void clear_save() {
	ofstream save;
	save.open("ttt_save.txt", ofstream::out | ofstream::trunc);
	save.close();
}

void player_vs_ai(GameField& game_field, bool is_tic = true, bool is_player = true) {

	bool is_tic_turn = is_tic;
	bool is_players_turn = is_player;

	bool p1_is_tic = is_tic_turn * is_players_turn + !is_tic_turn * !is_players_turn;
	Player player1(p1_is_tic);
	AI player2(!p1_is_tic);

	bool done = true;
	while (done) {
		game_field.show();
		if (is_players_turn)
			player1.do_move(game_field);
		else
			player2.do_move(game_field);

		is_tic_turn = !is_tic_turn;
		is_players_turn = !is_players_turn;
		save_game(game_field, 1, is_tic_turn, is_players_turn);
		system("clear");
		if (game_field.check() != -1)
			done = false;
	}
}

void player_vs_player(GameField& game_field, bool is_tic=true, bool is_player=true) {
	bool is_tic_turn = is_tic;
	bool is_players_turn = is_player;

	Player player1(true);
	Player player2(false);

	bool done = true;
	while (done) {
		game_field.show();
		if (is_players_turn)
			player1.do_move(game_field);
		else
			player2.do_move(game_field);

		is_tic_turn = !is_tic_turn;
		is_players_turn = !is_players_turn;
		save_game(game_field, 2, is_tic_turn, is_players_turn);
		system("clear");
		if (game_field.check() != -1)
			done = false;
	}
}

int load_saved_game() {
	ifstream save;
	save.open("ttt_save.txt");
	string str_save;
	getline(save, str_save);
	save.close();

	if (str_save.length() != 0) {
		cout << "Do you want to load your last game? 1 - Yes or 2 - No\n";
		string agreement;

		getline(cin, agreement);
		if (agreement[0] == '2')
			return 1;
	}
	if (str_save.length() < 12) {
		cout << "\e[0;33mSaved game loading error\e[0m\n\n";
		return 1;
	}

	GameField field(str_save);
	int game_mode = int(str_save[9]) - int('0');
	bool is_tic = int(str_save[10]) - int('0');
	bool is_player = int(str_save[11]) - int('0');
	
	if (game_mode == 1)
		player_vs_ai(field, is_tic, is_player);
	else
		player_vs_player(field, is_tic, is_player);

	clear_save();
	return 0;
}

int main() {
	while (true) {
		system("clear");
		cout << "Welcome to TicTacToe\n\n";

    if (load_saved_game() == 1) {
			cout << "Choose mode: 1 - 'vs AI', 2 - 'vs Friend'\n";
			string mode;
			getline(cin, mode);

			GameField game_field;
			if (mode[0] == '1') {
				cout << "Choose 1 - \e[0;32m'X'\e[0m, 2 - \e[0;33m'O'\e[0m\n";

				string tic_or_toe;
				getline(cin, tic_or_toe);

				cout << (tic_or_toe[0] == '1') << '\n';
				player_vs_ai(game_field, true, tic_or_toe[0] == '1');
			}
			else {
				player_vs_player(game_field);
			}
			
			clear_save();
			game_field.show();
		}

		cout << "Do you want to restart the game? 1 - Yes or 2 - No?\n";
		string agreement;
		getline(cin, agreement);
		if (agreement[0] == '2') {
			cout << "Bye, come back later!\n";
			break;
		}
	}

	return 0;
}