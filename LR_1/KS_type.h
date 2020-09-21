#pragma once

#include <iostream>;
#include <string>;
#include <fstream>;
#include "func.h"

struct KS_type
{
	//параметры
	int id;
	std::string name;
	int workshop_number;
	int working_workshops;
	double effectiveness;

	//методы	
	void vvod();
	void vivod();
	void number_working();
	void save();
	void load();
	KS_type();
	~KS_type();



};

