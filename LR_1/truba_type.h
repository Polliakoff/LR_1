#pragma once

#include <iostream>;
#include <string>;
#include <fstream>;

struct truba_type
{
	//���������
	int id;
	double length;
	double diameter;
	bool in_servise;

	//������
	void vvod();
	void vivod();
	void servise();
	void save();
	void load();

};

