#include "KS_type.h"
using namespace std;

KS_type::KS_type()
{

}

KS_type::~KS_type()
{

}

void KS_type::vvod() {
	string temp_string;//временная строка
	
	cout << endl << "Введите параметры для КС:" << endl;

	cout << "Введите id КС" << endl;
	
	while (true) {
		cin >> temp_string;

		if (is_int(temp_string) == true) {
			this->id = stoi(temp_string);
			break;
		}
		else {
			cout << "Введите целое число" << endl;
		}

	}

	cout << "Введите название КС" << endl;
	cin >> this->name;

	cout << "Введите число цехов КС" << endl;
	
	while (true) {
		cin >> temp_string;

		if (is_int(temp_string) == true) {
			this->workshop_number = stoi(temp_string);
			break;
		}
		else {
			cout << "Введите целое число" << endl;
		}

	}

	int temp_int; //Временная целочисленая переменная
	
	cout << "Введите число работающих цехов КС (<= числа цехов)" << endl;

	while (true) {
		cin >> temp_string;

		if (is_int(temp_string) == true) {
			temp_int = stoi(temp_string);
		}
		else {
			cout << "Введите целое число" << endl;
			continue;
		}

		if (temp_int <= this->workshop_number) {
			this->working_workshops = temp_int;
			break;
		}
		else {
			cout << "Введите число <= числа цехов" << endl;
			continue;
		}
	}
	
	while (true) {
		if (temp_int <= this->workshop_number) {
			this->working_workshops = temp_int;
			break;
		}
		else cout << "Введите число <= числа цехов"<<endl;
		cin >> temp_int;
	}

	cout << "Введите эффективность КС" << endl;
	
	while (true) {
		cin >> temp_string;

		if (is_double(temp_string) == true) {
			this->effectiveness = stod(temp_string);
			break;
		}
		else {
			cout << "Введите вещественное число" << endl;
		}

	}
	
	this->is_loaded = true;
	cout << "Ввод парамтеров завершен" << endl;

}

void KS_type::vivod() {
	if (this->is_loaded == true) {
		cout << endl << "Параметры рассматриваемой КС:" << endl;

		cout << "Id КС : " << this->id << endl;

		cout << "Название КС: " << this->name << endl;

		cout << "Число цехов КС: " << this->workshop_number << endl;

		cout << "Число работающих цехов КС: " << this->working_workshops << endl;

		cout << "Эффективность КС: " << this->effectiveness << endl;
	}
	else {
		cout << endl << "Структура КС пуста!" << endl;
	}

}
//изменение кол-ва рабочих цехов
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
//сохранение в файл
void KS_type::save() {

	ofstream fout("KS.txt"); // создаём объект класса ofstream для записи и связываем его с файлом truba.txt
	// запись строк в файл
	fout << this->id << "|" << this->name << "|" <<
		this->workshop_number << "|" << this->working_workshops <<"|"<< this->effectiveness << "|" << ";";
	fout.close(); // закрываем файл
}
//загрузка из файла
void KS_type::load() {

	string load_string; //строка в котрую считаем данные из файла
	string temp_string; //временная строка
	ifstream fin("KS.txt"); // открыли файл для чтения
	//проверка на наличие файла
	if (fin.is_open() == false) {
		cout << endl << "ФАЙЛ 'KS.txt' НЕ НАЙДЕН!!!!!" << endl;
		return;
	}
	
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
				this->name = temp_string;
				break;
			case 2:
				this->workshop_number = stoi(temp_string);
				break;

			case 3:
				this->working_workshops = stoi(temp_string);
				break;

			case 4:
				for (int k = 0; k < temp_string.length(); k++) {
					if (temp_string[k] == '.') temp_string[k] = ',';
				}
				this->effectiveness = stod(temp_string);
				cout << endl << "КС успешно загружена из файла!" << endl;
				this->is_loaded = true;
				break;
			}

			temp_string = "";
			j++;
		}
		if (i + 1 <= load_string.length())i++;
		else return;

	}

}