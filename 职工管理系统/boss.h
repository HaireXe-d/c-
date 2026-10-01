#pragma once
#include<iostream>
#include"worker.h"
using namespace std;


class boss :public Worker
{
public:

	boss(int id, string name, int did);

	virtual void showinfo();

	virtual string getdeptname();
};