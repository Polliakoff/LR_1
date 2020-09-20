#include "truba_type.h"

using namespace std;

void truba_type::vvod() {
	cout << "Введите параметры для Трубы:" << endl;

	cout << "Введите id трубы" << endl;
	cin >> this->id;

	cout << "Введите длину трубы" << endl;
	cin >> this->length;

	cout << "Введите диаметр трубы" << endl;
	cin >> this->diameter;

	string temp_string; //временная строка
	
	cout << "В ремонте ли труба (yes/no)" << endl;
	cin >> temp_string;

	while (true) {

		if (temp_string == "yes") {
			this->in_servise = 1;
			break;
		}
		else if (temp_string == "no") {
			this->in_servise = 0;
			break;
		}
		else {
			cout << "Введите 'yes' или 'no' (строчными буквами)";
		}
		cout << endl;
		cin >> temp_string;
	}

	cout << "Ввод парамтеров завершен"<<endl;

}

void truba_type::vivod() {
	cout << endl <<"Параметры рассматриваемой Трубы:" << endl;

	cout << "Id трубы : "<< this->id << endl;

	cout << "Длина трубы: "<< this->length << endl;

	cout << "Диаметр трубы: "<< this->diameter << endl;

	string temp_string; //временная строка

	if (this->in_servise == 1) temp_string = "yes";
	else temp_string = "no";

	cout << "В ремонте ли труба (yes/no) : "<< temp_string << endl;


}