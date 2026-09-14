#pragma once
#include "utility.h"
#include"Player.h"
class Piece;
//Forward Declaration
class Board
{
	Piece* Ps[8][8];
	Piece* sp;
	int sr, sc, er, ec;
	COLOR Turn;
	Player* Players[2];
	bool LP[8][8];
	
public:
	Board();
	void Play();
	void move(int, int, int er, int ec);
	void BoardPrint();
	void PlayerMsg();
	void SelectSrc();
	bool  Isvalidsrc();
	void SelectDist();
	bool isValidDist();
	void UpdateBoard();
	void TurnChange();
	Piece* getAps(int r, int c)
	{
		return Ps[r][c];
	}
	bool ComputeHighLightPos();
	
	void Highlight();
};

