#include "Piece.h"
#include "Board.h"
class Board;
Piece::Piece(Board* _b, int r, int c, COLOR _clr)
{
	this->b = _b;
	this->ri = r;
	this->ci = c;
	this->clr = _clr;
}
void Piece::Move(int er, int ec)
{
	if (this == nullptr)
		return;
	if (b != nullptr)
	{
		b->move(this->ri, this->ci, er, ec);
		this->ri = er;
		this->ci = ec;
	}
}
COLOR  Piece::getclr()
{
	return clr;
}
 bool Piece:: isHorizontal(int sr, int sc, int er, int ec)
{
	 return sr == er;

}
 bool Piece::isVertical(int sr, int sc, int er, int ec)
{
	 return sc == ec;
}
 bool Piece::isDiagonal(int sr, int sc, int er, int ec)
{
	 int dr = abs(sr - er);
	 int dc = abs(sc - ec);
		 return dr == dc;
}
 bool Piece::isHorizontalPathClear(Board*b,int sr, int sc, int er, int ec)
{
	 if (sc < ec) //left to right
	 {
		 for (int c = sc + 1; c < ec; c++)
			 if (b->getAps(sr, c) != nullptr)
				 return false;
		 return true;
	 }
	 else //right to left
	 {
		 for (int c = ec + 1; c < sc; c++)
			 if (b->getAps(sr, c) != nullptr)
				 return false;
		 return true;
	 }

}
 bool Piece::islVerticalPathClear(Board* b,int sr, int sc, int er, int ec)
{

	 if (sr < er) //left to right
	 {
		 for (int r = sr + 1; r < er; r++)
			 if (b->getAps(r, sc) != nullptr)
				 return false;
		 return true;
	 }
	 else //right to left
	 {
		 for (int r = er + 1; r < sr; r++)
			 if (b->getAps(r, sc) != nullptr)
				 return false;
		 return true;
	 }
}
 bool Piece::isDiagonalPathClear(Board* b, int sr, int sc, int er, int ec)
 {

	 if (er > sr)
	 {
		 if (ec > sc)
		 {
			 for (int r = sr + 1, c = sc + 1; r < er; r++, c++)
			 {
				 if (b->getAps(r, c) != nullptr)
				 {
					 return false;
				 }
			 }
			 return true;
		 }
	 }








	 else
	 {
		 for (int r = sr + 1, c = sc - 1; r < er; r++, c--)
		 {
			 if (b->getAps(r, c) != nullptr)
			 {
				 return false;
			 }
		 }

		 return true;
	 }





	 if (er < sr)
 {
	 if (ec > sc)
	 {
		 for (int r = sr - 1, c = sc + 1; r > er; r--, c++)
		 {
			 if (b->getAps(r, c) != nullptr)
			 {
				 return false;
			 }
		 }


		 return true;
 }
 }

		 else
		 {
			 if (ec > sc)
			 {
			 for (int r = sr - 1,  c = sc - 1; r > er; r--, c--)
			 {
				 if (b->getAps(r, c) != nullptr)
				 {
							 return false;
					 }
					 }
					 return true;
				 }
		 }
	 
	 }	 
