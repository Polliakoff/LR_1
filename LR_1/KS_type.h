#pragma once

#include <iostream>;
#include <string>;
#include <fstream>;
#include "func.h"
#include <limits>

struct KS_type
{
	//id
private:

	static int sId;


public:

	//���������
	int id;
	std::string name;
	int workshop_number;
	int working_workshops;
	double effectiveness;
	bool is_loaded = false;

	//������	
	void vvod();
	void vivod();
	void number_working();
	void save(std::ofstream& fout);
	void load(std::ifstream& fin, std::string load_string);
	KS_type();
	~KS_type();






};

