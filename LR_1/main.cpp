#include <iostream>
#include "truba_type.h"
#include "KS_type.h"
#include <string>
#include "func.h"
#include <vector>
#include <fstream>
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	ofstream fout;//создание потока вывода в файл
	ifstream fin;//создание потока вывода из файла
	//объявление массивов пользовательских структур типов
	vector <truba_type> pipes;
	vector <KS_type> KS_es;
	string id_selection;
	bool correct_check = false;//логическая переменная проверки правильности
	string temp_string;//врмененная строковая переменная
	string selection; //переменная выбора действия
	int Lines = 0;//Число строк в файлах
	bool prodolzhyt = true;//логическая переменная продолжения работы программы

	while (prodolzhyt == true) {

		cout << "Выберите действие которое необходимо осуществить: " <<
			endl << "1 - Добавить трубу " << endl << "2 - Добавить КС " << endl
				<< "3 - Просмотр всех объектов " << endl << "4 - Редактировать трубу " << endl
					<< "5 - Редактировать КС " << endl << "6 - Сохранить (Файлы перезаписываются) " << endl 
						<< "7 - Загрузить (Загруженные структуры добавятся к существующим)" 
							<< endl << "0 - Выйти" << endl;

		cin >> selection;

		if (is_int(selection) == true) {

			switch (stoi(selection)) {

			case 1:{
				//создание новой пустой трубы и помещение ее в вектор труб
				truba_type temp_truba;
				temp_truba.vvod();
				temp_truba.vivod();
				pipes.push_back(temp_truba);
			}
				break;

			case 2: {
				//создание новой пустой КС и помещение ее в вектор КС
				KS_type temp_KS;
				temp_KS.vvod();
				temp_KS.vivod();
				KS_es.push_back(temp_KS);

			}
				break;
			case 3: {

				for (auto i : pipes) {
					i.vivod();
				}

				for (auto i : KS_es) {
					i.vivod();
				}
				
			}
				break;

			case 4: {
				cout <<endl<< "Введите id Трубы, которую хотите редактировать "<<endl;
				cin >> id_selection;
				if (is_int(id_selection) == true) {
					for (auto i : pipes) {
						if (i.id == stoi(id_selection)) {
							correct_check = true;
							cout << "Ви хотите изменить все параметры этой трубы или только статуc ремонта? (all/service)"<<endl;
							while (true) {
								cin >> temp_string;
								if (temp_string == "all") {
									i.vvod();
									i.vivod();
									break;
								}
								else if (temp_string == "service") {
									i.servise();
									i.vivod();
									break;
								}
								else {
									cout << "Введите all или service строчными буквами "<<endl;
								}
							}
							break;
						}	
					}
					if (correct_check == false) {
						cout << "Введите один из id cуществующих труб (можно посмотреть командой 3)"<<endl;
					}
				}
			}
				break;
			case 5: {
				cout << endl << "Введите id КС, которую хотите редактировать " << endl;
				cin >> id_selection;
				if (is_int(id_selection) == true) {
					for (auto i : KS_es) {
						if (i.id == stoi(id_selection)) {
							correct_check = true;
							cout << "Ви хотите изменить все параметры этой КС или только количество работающих цехов ремонта? (all/workshops)" << endl;
							while (true) {
								cin >> temp_string;
								if (temp_string == "all") {
									i.vvod();
									i.vivod();
									break;
								}
								else if (temp_string == "workshops") {
									i.number_working();
									i.vivod();
									break;
								}
								else {
									cout << "Введите all или workshops строчными буквами "<<endl;
								}
							}
							break;
						}
					}
					if (correct_check == false) {
						cout << "Введите один из id cуществующих КС (можно посмотреть командой 3)" << endl;
					}
				}
			}
				break;

			case 6: {
				//очистка файла
				fout.open("truba.txt");
				fout << "";
				fout.close();
				//сохранение труб в файл
				fout.open("truba.txt", std::ios::app);

				for (auto i : pipes) {
					i.save(fout);
				}
				fout.close();

				//очистка файла
				fout.open("KS.txt");
				fout << "";
				fout.close();
				//сохранение труб в файл
				fout.open("KS.txt", std::ios::app);

				for (auto i : KS_es) {
					i.save(fout);
				}
				fout.close();
			}
				break;

			case 7: {
				//для труб
				//Посчитаем число строк в файлах сохранений
				fin.open("truba.txt");
				
				if (fin.is_open() == false) {
					cout << endl << "ФАЙЛ 'truba.txt' НЕ НАЙДЕН!!!!" << endl;
					break;
				}

				while (std::getline(fin, temp_string)) ++Lines;
				fin.close();
				//Непосредственно сама загрузка
				fin.open("truba.txt");
				if (Lines == 0) {
					cout << endl << "Файл сохранений Труб Пуст. Загружать нечего." << endl;
				}
				else {
					for (int i = 0; i < Lines; i++) {
						truba_type temp_truba;
						temp_truba.load(fin);
						pipes.push_back(temp_truba);
					}
				}
				fin.close();
				Lines = 0;

				//для КС
				//Посчитаем число строк в файлах сохранений
				fin.open("KS.txt");

				if (fin.is_open() == false) {
					cout << endl << "ФАЙЛ 'KS.txt' НЕ НАЙДЕН!!!!" << endl;
					break;
				}

				while (std::getline(fin, temp_string)) ++Lines;
				fin.close();
				//Непосредственно сама загрузка
				fin.open("KS.txt");
				if (Lines == 0) {
					cout << endl << "Файл сохранений КС Пуст. Загружать нечего." << endl;
				}
				else {
					for (int i = 0; i < Lines; i++) {
						KS_type temp_KS;
						temp_KS.load(fin);
						KS_es.push_back(temp_KS);
					}
				}
				fin.close();
				Lines = 0;
					





			}
				break;
			
			case 0: {
				prodolzhyt = false;
			}
				break;

			default: {
				cout << "введите цифру от 0 до 7 для выбора действия" << endl;
			}







			}
		}
		else {
			cout << "введите цифру от 0 до 7 для выбора действия" << endl;
		}
		system("pause");
		system("cls");
	}


	

	

	







	





	
	

	return 0;
}