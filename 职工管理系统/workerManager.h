#pragma once
#include<fstream>
#define FILENAME "empfile.txt"
#include"worker.h"
#include<iostream>
using namespace std;

class WorkerManager
{
public:
	WorkerManager();

	void save();

	bool m_fileisempty;

	int get_empnum();

	void init_emp();

	void showemp();

	void delemp();

	void showmenu();

	void exitsystem();

	int m_empnum;

	int isexist(int id);

	void modemp();

	void findemp();

	void sortemp();

	void cleanall();

	Worker** m_emparray;

	void add_emp();


	~WorkerManager();
};