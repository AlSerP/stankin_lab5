#pragma once

class VirtualPlayer
{
protected:
	bool is_tic;
	int wins;
public:
  VirtualPlayer();
  
	void add_win();
};
