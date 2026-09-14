#pragma once
#include "Piece.h"
class Rook :
    public Piece
{
public:
    Rook(Board* _b, int r, int c, COLOR _clr);
    void print() override;
    virtual bool isLegalMove(int er, int ec)override;
};



