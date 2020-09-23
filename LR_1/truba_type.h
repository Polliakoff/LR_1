#pragma once

#include <iostream>;
#include <string>;
#include <fstream>;
#include "func.h"

struct truba_type
{
	//id
private:
	
	static int sId;
	
public:	
	
	//���������
	int id;
	double length;
	double diameter;
	bool in_servise;
	bool is_loaded= false;

	//������
	void vvod();
	void vivod();
	void servise();
	void save(std::ofstream& fout);
	void load(std::ifstream& fin);
	truba_type();
	~truba_type();

};

