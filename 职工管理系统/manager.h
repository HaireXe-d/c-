#pragma once
#include<iostream>
#include"worker.h"
using namespace std;


class manager :public Worker
{
public:

	manager(int id, string name, int did);

	virtual void showinfo();

	virtual string getdeptname();
};