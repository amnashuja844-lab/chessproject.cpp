#include "Board.h"
#include"Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Player.h"
#include"utility.h"

using namespace std;
Board::Board()
{

	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
			
		{
			Ps[r][c] = nullptr;
			if (r == 1)
			{
				Ps[r][c] = new Pawn(this, r, c, BLACK);
			}
			else if (r == 6)
			{
				Ps[r][c] =  new Pawn(this, r, c, WHITE);
			}
			else if (r == 0 and (c == 0 or c == 7))
			{
				Ps[r][c] = new Rook(this, r, c, BLACK);
			}
			else if (r == 0 and (c == 1 or c == 6))
			{
				Ps[r][c] = new Knight(this, r, c, BLACK);
			}

			else if (r == 0 and (c == 2 or c == 5))
			{
				Ps[r][c] = new Bishop(this, r, c, BLACK);
			}
			else if (r == 0 and (c == 3))
			{
				Ps[r][c] = new King(this, r, c, BLACK);
			}
			else if (r == 0 and (c == 4))
			{
				Ps[r][c] = new Queen(this, r, c, BLACK);
			}





			else if (r == 7 and (c == 0 or c == 7))
			{
				Ps[r][c] = new Rook(this, r, c, WHITE);
			}
			else if (r == 7 and (c == 1 or c == 6))
			{
				Ps[r][c] = new Knight(this, r, c, WHITE);
			}
			else if (r == 7 and (c == 2 or c == 5))
			{
				Ps[r][c] = new Bishop(this, r, c, WHITE);
			}
			else if (r == 7 and (c == 3))
			{
				Ps[r][c] = new King(this, r, c, WHITE);
			}
			else if (r == 7 and (c == 4))
			{
				Ps[r][c] = new Queen(this, r, c, WHITE);
			}
			else {
				Ps[r][c] = nullptr;
			}
		}
	}

	sp = nullptr;
	sc = sr = er = ec = 0;
	Turn = WHITE;
	string s;
	cout << "Black PLayers Name" << endl;

	cin >> s;
	Players[0] = new Player(s,BLACK);
	
	cout << "White PLayers Name" << endl;

	cin >> s;
	Players[1] = new Player(s, WHITE);

}
void Board::BoardPrint()
{
	system("cls");
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (Ps[r][c] == nullptr)

				cout << "-";

			else

				Ps[r][c]->print();

		}
		cout << endl;
	}
}
void Board::Play()
{

	this->BoardPrint();
	while (true)
	{
		PlayerMsg();
		do {
			do
			{
				do
				{
					SelectSrc();
					if (!Isvalidsrc())
						cout << "Invalid Selection" << endl;

					Highlight();
				} while (!Isvalidsrc());
				SelectDist();
				if (isValidDist() == false)
					cout << "invalid destination" << endl;

			} while (isValidDist() == false);
			if (Ps[sr][sc]->isLegalMove(er, ec) == false)
			{
				cout << "Ilegal Move..." << endl;

			}
		}
	 while (Ps[sr][sc]->isLegalMove(er, ec) == false);

			UpdateBoard();
			TurnChange();
		}
	
	}
		
	



	void Board::move(int src, int sc, int er, int ec)
	{
		Ps[er][ec] = Ps[sr][sc];
		Ps[sr][sc] = nullptr;
	}
	
	void  Board::PlayerMsg()
	{
		cout << Players[Turn]->getname() << " 's Turn"<<endl;

	}
	void  Board::SelectSrc()
	{
		getRowColbyLeftClick(sr, sc);

	}


	void  Board::SelectDist()
	{
		getRowColbyLeftClick(er, ec);
	}
	bool  Board::Isvalidsrc()
	{
		
		
		if (Ps[sr][sc] == nullptr or Ps[sr][sc]->getclr() != Players[Turn]->getclr())
			return true;
			return false;
	}
	
	bool Board::isValidDist()
	{
		
		
	
		if (Ps[er][er] == nullptr or Ps[er][er]->getclr() != Players[Turn]->getclr())
		
			return true;
		
		 return false;

	}
	void Board::UpdateBoard()
	{
		Ps[sr][sc]->Move(er, ec);
		

		BoardPrint();
	}
	void Board::TurnChange()
	{
		if (Turn == BLACK)
			Turn = WHITE;
		else
			Turn = BLACK;
	}
	bool Board::ComputeHighLightPos()
	{
		bool LP[8][8];
		if (Ps[sr][sc] == nullptr)
		{
			return false;
		}
		for (int r = 0; r < 8; r++)
		{
			for (int c = 0; c < 8; c++)
			{
				if (Ps[sr][sc]->isLegalMove(r, c))
				{
					return LP[r][c] = true;
				}
				else
				{
					return LP[r][c] =false;
				}
			}
		}
		return true;
}
	

	void Board::Highlight() {
		if (ComputeHighLightPos() == true)
		{
			for (int r = 0; r < 8; r++)
			{
				for (int c = 0; c < 8; c++)
				{
					if (LP[r][c] == true)
					{
						cout << "*";
					}
					else if (Ps[r][c] != nullptr)
					{
						Ps[r][c]->print();
					}
					else
					{
						cout << " .";
					}
					cout << endl;
				}
				
			}

			
		}
	}