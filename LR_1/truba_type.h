#pragma once

#include <iostream>;
#include <string>;
#include <fstream>;

struct truba_type
{
	//параметры
	int id;
	double length;
	double diameter;
	bool in_servise;

	//методы
	void vvod();
	void vivod();
	void servise();
	void save();

};

