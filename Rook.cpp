#include "Rook.h"
Rook::Rook(Board* _b, int r, int c, COLOR _clr)
	:Piece(_b, r, c, _clr)
{

}
void Rook::print()
{
	if (clr == WHITE)
	{
		cout << "R";
	}
	else
	{
		cout << "r";
	}
}
bool Rook::isLegalMove(int er, int ec)

{
	return (isHorizontal(this->ri, this->ci, er, ec))
		and isHorizontalPathClear(b, this->ri, this->ci, er, ec)
		or islVerticalPathClear(b, this->ri, this->ci, er, ec)
		and islVerticalPathClear(b, this->ri, this->ci, er, ec);
}