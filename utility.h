#pragma once

#include<windows.h>
#include<conio.h>
#include<iostream>
using namespace std;
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
void SetClr(int clr);
enum  COLOR { BLACK, WHITE };