#include<iostream>
using namespace std;

class cube
{
public:
	void setL(int l)
	{
		L = l;
	}

	int getL()
	{
		return L;
	}

	void setW(int w)
	{
		W = w;
	}

	int getW()
	{
		return W;
	}

	void setH(int h)
	{
		H = h;
	}

	int getH()
	{
		return H;
	}
	
	int calculateS()
	{
		return 2 * L * W + 2 * W * H + 2 * L * H;
	}

	int calculateV()
	{
		return L * W * H;
	}

	bool issamebyclass(cube& c)
	{
		if (L == c.getL() && W == c.getW() && H == c.getH())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	int L;
	int W;
	int H;

};


bool issame(cube &c1,cube &c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);
	cout << "面积：" << c1.calculateS() << endl;
	cout << "体积：" << c1.calculateV() << endl;
	cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	bool ret = issame(c1, c2);
	if (ret)
	{
		cout << "相同" << endl;
	}
	else
	{
		cout << "不同" << endl;
	}

	ret = c1.issamebyclass(c2);
	if (ret)
	{
		cout << "相同" << endl;
	}
	else
	{
		cout << "不同" << endl;
	}
	system("pause");
	return 0;
}