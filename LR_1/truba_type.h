#pragma once

#include <iostream>;
#include <string>;
#include <fstream>;
#include "func.h"

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
	truba_type();
	~truba_type();

};

