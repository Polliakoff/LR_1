#pragma once

#include <iostream>;
#include <string>;
#include <fstream>;

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


};

