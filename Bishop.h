#pragma once
#include "Piece.h"
class Bishop :
    public Piece
{
public:
    Bishop(Board* _b, int r, int c, COLOR _clr);
    void print() override;
    virtual bool isLegalMove(int er, int ec) ;
};

