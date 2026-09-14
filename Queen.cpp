#include "Queen.h"
Queen::Queen(Board* _b, int r, int c, COLOR _clr)
	:Piece(_b, r, c, _clr)
{

}
void Queen::print()
{
	if (clr == WHITE)
	{
		cout << "Q";
	}
	else
	{
		cout << "q";
	}
}
bool Queen::isLegalMove(int er, int ec)

{
	return (isHorizontal(this->ri, this->ci, er, ec))
		and isHorizontalPathClear(b, this->ri, this->ci, er, ec)
		or islVerticalPathClear(b, this->ri, this->ci, er, ec)
		and islVerticalPathClear(b, this->ri, this->ci, er, ec)
		or isDiagonal(this->ri, this->ci, er, ec) and isDiagonalPathClear(b, this->ri, this->ci, er, ec);
}