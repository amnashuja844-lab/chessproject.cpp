#pragma once
#include "Piece.h"
class Knight :
    public Piece
{public:
    Knight(Board* _b, int r, int c, COLOR _clr);
    void print() override;
   virtual bool isLegalMove(int er, int ec)override;

};

