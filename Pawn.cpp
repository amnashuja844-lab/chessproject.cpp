#include "Pawn.h"
#include"Piece.h"

Pawn::Pawn(Board* _b, int r, int c, COLOR _clr)
	:Piece(_b, r, c, _clr)
{

}
void Pawn::print()
{
	if (clr == WHITE)
	{
		cout << "P";
	}
	else
	{
		cout << "p";
	}
}
bool Pawn::isLegalMove(int er, int ec)

{
	return  isVertical(this->ri, this->ci, er, ec)
	and islVerticalPathClear(b, this->ri, this->ci, er, ec);
		
	}
	