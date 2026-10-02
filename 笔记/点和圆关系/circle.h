#pragma once
#include<iostream>
#include"point.h"
using namespace std;
class circle
{
public:
	void setR(int r);
	

	int getR();
	
	void setcenter(point center);
	
	point getcenter();
	

private:
	int R;
	point Center;
};