#include "Bishop.h"
Bishop::Bishop(Board* _b, int r, int c, COLOR _clr)
	:Piece(_b, r, c, _clr)
{

}
void Bishop::print()
{
	if (clr == WHITE)
	{
		cout << "B";
	}
	else
	{
		cout << "b";
	}
}
bool Bishop::isLegalMove(int er, int ec)

{
	return isDiagonal(this->ri, this->ci, er, ec) and isDiagonalPathClear(b, this->ri, this->ci, er, ec);
 }

