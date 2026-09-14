#pragma once
#include "utility.h"
class Board;
class Piece
{
protected:
	static bool isHorizontal(int sr,int sc,int er,int ec);
	 static bool isVertical(int sr, int sc, int er, int ec);
	 static bool isDiagonal (int sr, int sc, int er, int ec);
	 static bool isHorizontalPathClear(Board*b ,int sr, int sc, int er, int ec);
	 static bool islVerticalPathClear(Board* b,int sr, int sc, int er, int ec);
	 static bool isDiagonalPathClear(Board* b,int sr, int sc, int er, int ec);
	int ri, ci;
	COLOR clr;
	Board* b;
public:
	Piece(Board* _b, int r, int c, COLOR _clr);
	virtual void print() = 0;//Abstract Class.
	//nechey ane wali class define karegi har player ka apna print
	virtual bool isLegalMove(int er, int ec) = 0;//pure virtual function.
	void Move(int er, int ec);
	COLOR getclr();
};

