#include <iostream>
#include "truba_type.h"
#include "KS_type.h"
#include <string>
#include "func.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	
	//объявление переменных пользовательских типов
	truba_type pipe_1;
	KS_type KS_1;
	
	string selection; //переменная выбора режима работы

	cout << "Вы хотите ввести данные или загрузить их из файла?" <<
		endl << "1 - ввести и сохранить, 2 - загрузить" << endl;
	
	while (true) {

		cin >> selection;

		if (is_int(selection) == true) {

			if (stoi(selection) == 1) {



				//Ввод параметров трубы
				pipe_1.vvod();

				//Вывод введенных параметров трубы
				pipe_1.vivod();

				//Изменение параметра трубы в ремонте/ не в ремонте
				pipe_1.servise();

				//сохранение в файл параметров трубы
				pipe_1.save();

				//Ввод параметров КС
				KS_1.vvod();

				//Вывод введенных параметров КС
				KS_1.vivod();

				//Изменение числа работающих цехов
				KS_1.number_working();

				//сохранение в файл параметров КС
				KS_1.save();

				break;
			}

			else if (stoi(selection) == 2) {
				//загрузка данных трубы
				pipe_1.load();
				//загрузка данных КС
				KS_1.load();
				//вывод данных трубы
				pipe_1.vivod();
				//вывод данных КС
				KS_1.vivod();





				break;
			}

			else {
				cout << "введите цифру 1 или 2 для выбора действия" << endl;
				continue;
			}
		}
		else {
			cout << "введите цифру 1 или 2 для выбора действия" << endl;
		}
	}


	

	

	







	





	
	
	system("Pause");
	return 0;
}