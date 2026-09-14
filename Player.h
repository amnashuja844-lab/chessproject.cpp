#pragma once
#include<string>
using namespace std;
#include "utility.h"
class Player
{
	string name;
	COLOR clr;
public:
	Player(string s, COLOR _clr)
	{
		name = s;
		clr = _clr;
	}
	COLOR getclr()
	{
		return clr;
	}
	string getname()
	{
		return name;
	}
};

