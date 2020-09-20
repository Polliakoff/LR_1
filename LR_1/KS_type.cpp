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

void KS_type::number_working() {

	string temp_string; //временная строка

	cout << endl << "Хотите ли вы отключить/включить цех КС? (yes/no)" << endl;
	cin >> temp_string;

	while (true) {

		if (temp_string == "yes") {
			break;
		}
		else if (temp_string == "no") {
			return;
		}
		else {
			cout << "Введите 'yes' или 'no' (строчными буквами)";
		}
		cout << endl;
		cin >> temp_string;
	}




	while (true) {
		cout << endl << "Вы хотите отключить, включить цех или выйти? (on/off/quit)" << endl;
		cin >> temp_string;
		
		if (temp_string == "on") {
			if((this->working_workshops+1)<=this->workshop_number) this->working_workshops++;
			else {
				cout << "Достигнуто максимальное число работающих цехов";
				continue;
			}
			break;
		}
		else if (temp_string == "off") {
			if ((this->working_workshops - 1) >= 0) this->working_workshops--;
			else {
				cout << "Работающих цехов уже нет";
				continue;
			}
			break;
		}
		
		else if (temp_string == "quit") {
			break;
		}
		
		else {
			cout << "Введите 'on', 'off' или 'quit' (строчными буквами)";
		}
		cout << endl;
	}

	cout << "Число работающих цехов на данный момент :" << this->working_workshops << endl;





}