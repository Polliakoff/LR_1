#include <iostream>
#include "truba_type.h"
#include "KS_type.h"
#include <string>
using namespace std;


int main() {

	setlocale(LC_ALL, "Russian");

	//временные переменные для разных задач
	int temp_int;
	double temp_double;
	string temp_string;
	
	//объявление переменных пользовательских типов
	truba_type pipe_1;
	KS_type KS_1;

	//Ввод параметров трубы
	pipe_1.vvod();

	//Вывод введенных параметров трубы
	pipe_1.vivod();

	//Изменение параметра трубы в ремонте/ не в ремонте



	//Ввод параметров КС
	KS_1.vvod();

	//Вывод введенных параметров КС
	KS_1.vivod();

	//Изменение числа работающих цехов


	

	

	







	





	
	
	system("Pause");
	return 0;
}