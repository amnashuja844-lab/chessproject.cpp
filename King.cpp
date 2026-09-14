#include "King.h"
King::King(Board* _b, int r, int c, COLOR _clr)
	:Piece(_b, r, c, _clr)
{

}
void King::print()
{
	if (clr == WHITE)
	{
		cout << "K";
	}
	else
	{
		cout << "k";
	}
}
bool King::isLegalMove(int er, int ec)

{
	int dr =abs( er - this->ri);
	int dc = abs(ec - this->ci);
	return dr<=1 and dc<=1 and( (isHorizontal(this->ri, this->ci, er, ec))
		and isHorizontalPathClear(b, this->ri, this->ci, er, ec)
		or islVerticalPathClear(b, this->ri, this->ci, er, ec)
		and islVerticalPathClear(b, this->ri, this->ci, er, ec)
		or isDiagonal(this->ri, this->ci, er, ec) and isDiagonalPathClear(b, this->ri, this->ci, er, ec));
}