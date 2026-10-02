#include<iostream>
using namespace std;
#include"point.h"
#include"circle.h"
/*class point
{
public:
	void setx(int X)
	{
		x = X;
	}

	int getx()
	{
		return x;
	}

	void sety(int Y)
	{
		y = Y;
	}

	int gety()
	{
		return y;
	}
private:
	int x;
	int y;
};*/


/*class circle
{
public:
	void setR(int r)
	{
		R = r;
	}

	int getR()
	{
		return R;
	}

	void setcenter(point center)
	{
		 Center= center;
	}

	point getcenter()
	{
		return Center;
	}

private:
	int R;
	point Center;
};*/

void isincircle(circle &c,point &p)
{
	int distance =
		c.getcenter().getx() - p.getx() * (c.getcenter().getx() - p.getx()) + (c.getcenter().gety() - p.gety()) *
		(c.getcenter().gety() - p.gety());
	int rdistance = c.getR() * c.getR();
	if (distance = rdistance)
	{
		cout << "点在圆上" << endl;
	}
	else if(distance > rdistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}

}

int main()
{
	circle c;
	c.setR(10);
	point center;
	center.setx(10);
	center.sety(0);
	c.setcenter(center);
	point p;
	p.setx(10);
	p.sety(10);
	isincircle(c, p);


	system("pause");
	return 0;
}