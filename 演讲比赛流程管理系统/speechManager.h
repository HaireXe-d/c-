#pragma once
#include"speaker.h"
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<algorithm>
#include<functional>
#include<numeric>
#include<deque>
#include<fstream>

class speechManager
{
public:
	speechManager();

	void show_menu();

	void exitsystem();

	vector<int>v1;

	vector<int>v2;

	vector<int>vVictory;

	map<int,speaker>m_speaker;

	int m_Index;

	void initspeech();

	void creatspeaker();

	void startspeech();

	void speechDraw();

	void speechcontest();

	void show_score();

	void saverecord();

	void loadrecord();

	bool fileisempty;

	map<int, vector<string>>m_record;

	void showrecord();

	void clearrecord();

	~speechManager();
};