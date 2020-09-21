#include "truba_type.h"

using namespace std;

void truba_type::vvod() {
	
	string temp_string;//временная строка

	cout << endl << "Введите параметры для Трубы:" << endl;

	cout << "Введите id трубы" << endl;

	while (true) {
		cin >> temp_string;

		if (is_int(temp_string) == true) {
			this->id = stoi(temp_string);
			break;
		}
		else {
			cout << "Введите целое число"<<endl;
		}

	}

	cout << "Введите длину трубы" << endl;

	while (true) {
		cin >> temp_string;

		if (is_double(temp_string) == true) {
			this->length = stod(temp_string);
			break;
		}
		else {
			cout << "Введите вещественное число" << endl;
		}

	}

	cout << "Введите диаметр трубы" << endl;
	
	while (true) {
		cin >> temp_string;

		if (is_double(temp_string) == true) {
			this->diameter = stod(temp_string);
			break;
		}
		else {
			cout << "Введите вещественное число" << endl;
		}

	}

	
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

void truba_type::servise() {
	
	string temp_string; //временная строка
	
		cout << endl << "Хотите ли вы изменить статус ремонта трубы? (yes/no)" << endl;
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



		cout << endl << "В ремонте ли труба (yes/no)" << endl;
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

		if (this->in_servise == 1) temp_string = "yes";
		else temp_string = "no";

		cout << "В ремонте ли труба теперь (yes/no) : " << temp_string << endl;
	
}


void truba_type::save() {
	
	ofstream fout("truba.txt"); // создаём объект класса ofstream для записи и связываем его с файлом truba.txt
	// запись строк в файл
	fout << this->id<<"|"<< this->length << "|" <<
		this->diameter << "|" <<this->in_servise << "|" << ";";
	fout.close(); // закрываем файл
}

void truba_type::load() {

	string load_string; //строка в котрую считаем данные из файла
	string temp_string; //временная строка
	ifstream fin("truba.txt"); // открыли файл для чтения
	getline(fin, load_string, ';'); // получили оттуда строку
	fin.close(); // закрываем файл
	//счетчики для цикла
	int i = 0;
	int j = 0;
	temp_string = "";//инициализируем временную строку
	while (true) {
		if (load_string[i] != '|') {
			temp_string += load_string[i];
		}
		else {
			switch (j) {
			case 0:
				this->id = stoi(temp_string);
					break;
			case 1:
				for (int k=0;k< temp_string.length();k++) {
					if (temp_string[k] == '.') temp_string[k] = ',';
				}
				this->length = stod(temp_string);
					break;
			case 2:
				for (int k = 0; k < temp_string.length(); k++) {
					if (temp_string[k] == '.') temp_string[k] = ',';
				}
				this->diameter = stod(temp_string);
				break;

			case 3:
				this->in_servise = stoi(temp_string);
				break;
			}
			
			temp_string = "";
			j++;
		}
		if (i + 1 < load_string.length())i++;
		else return;
		
	}
}

