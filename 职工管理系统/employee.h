#pragma once
#include<iostream>
#include"worker.h"
using namespace std;


class employee:public Worker
{
public:

	employee(int id, string name, int did);

	virtual void showinfo();

	virtual string getdeptname() ;
};