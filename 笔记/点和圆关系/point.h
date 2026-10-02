#pragma once
#include<iostream>
using namespace std;

class point
{
public:
	void setx(int X);
	

	int getx();
	

	void sety(int Y);
	

	int gety();
	
private:
	int x;
	int y;
};