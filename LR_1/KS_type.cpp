#include "KS_type.h"
using namespace std;

void KS_type::vvod() {
	cout << endl << "Введите параметры для КС:" << endl;

	cout << "Введите id КС" << endl;
	cin >> this->id;

	cout << "Введите название КС" << endl;
	cin >> this->name;

	cout << "Введите число цехов КС" << endl;
	cin >> this->workshop_number;

	int temp_int; //Временная целочисленая переменная
	
	cout << "Введите число работающих цехов КС (<= числа цехов)" << endl;
	cin >> temp_int;
	
	while (true) {
		if (temp_int <= this->workshop_number) {
			this->working_workshops = temp_int;
			break;
		}
		else cout << "Введите число <= числа цехов"<<endl;
		cin >> temp_int;
	}

	cout << "Ввод парамтеров завершен" << endl;

}

void KS_type::vivod() {
	cout << endl << "Параметры рассматриваемой КС:" << endl;

	cout << "Id КС : " << this->id << endl;

	cout << "Название КС: " << this->name << endl;

	cout << "Число цехов КС: " << this->workshop_number << endl;

	cout << "Число работающих цехов КС: " << this->working_workshops << endl;

}