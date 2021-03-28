#pragma once
#include <string>

class GameField
{
private:
	int field[9] = { 0 };
	int free_squares = 9;
public:
	GameField();
  GameField(std::string str_field); 
	int set_tic(int x, int y);
	int set_tac(int x, int y);
	void show_line(int line_num) const;
	void show() const;
	int check();
	int get_free_squares() const { return free_squares; };
	bool is_free(int x, int y);
  std::string to_string() const;
};
