#include <iostream>
#include "truba_type.h"
#include "KS_type.h"
#include <string>
using namespace std;


int main() {

	setlocale(LC_ALL, "Russian");

	//временные переменные дл€ разных задач
	int temp_int;
	double temp_double;
	string temp_string;
	
	//объ€вление переменных пользовательских типов
	truba_type pipe_1;
	KS_type KS_1;

	//¬вод параметров трубы
	cout << "¬ведите параметры дл€ “рубы:"<<endl;
	
	cout << "¬ведите id трубы"<<endl;
	cin >> pipe_1.id;
	cout<< endl;

	cout << "¬ведите длину трубы" << endl;
	cin >> pipe_1.length;
	cout << endl;

	cout << "¬ведите диаметр трубы" << endl;
	cin >> pipe_1.diameter;
	cout << endl;

	cout << "¬ ремонте ли труба (yes/no)" << endl;
	cin >> temp_string;
	cout << endl;

	while (true) {

		if (temp_string == "yes") {
			pipe_1.in_servise = 1;
			break;
		}
		else if (temp_string == "no") {
			pipe_1.in_servise = 0;
			break;
		}
		else {
			cout << "¬ведите 'yes' или 'no' (строчными буквами)";
		}
		cout << endl;
		cin >> temp_string;
	}

	

	

	







	





	
	
	system("Pause");
	return 0;
}