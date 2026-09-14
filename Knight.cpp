#include "Knight.h"
Knight::Knight(Board* _b, int r, int c, COLOR _clr)
	:Piece(_b, r, c, _clr)
{

}
void Knight::print()
{
	if (clr == WHITE)
	{
		cout << "H";
	}
	else
	{
		cout << "h";
	}
}
bool Knight::isLegalMove(int er, int ec)

{
	int dr = abs(er - this->ri);
	int dc = abs(ec - this->ci);
	return (dr == 2 and dc == 1) or (dr == 1 and dc == 2);
}
