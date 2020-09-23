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
	ofstream fout;//�������� ������ ������ � ����
	ifstream fin;//�������� ������ ������ �� �����
	//���������� �������� ���������������� �������� �����
	vector <truba_type> pipes;
	vector <KS_type> KS_es;
	string id_selection;
	bool correct_check = false;//���������� ���������� �������� ������������
	string temp_string;//���������� ��������� ����������
	string selection; //���������� ������ ��������
	int Lines = 0;//����� ����� � ������
	bool prodolzhyt = true;//���������� ���������� ����������� ������ ���������

	while (prodolzhyt == true) {

		cout << "�������� �������� ������� ���������� �����������: " <<
			endl << "1 - �������� ����� " << endl << "2 - �������� �� " << endl
				<< "3 - �������� ���� �������� " << endl << "4 - ������������� ����� " << endl
					<< "5 - ������������� �� " << endl << "6 - ��������� " << endl << "7 - ���������" << endl << "0 - �����" << endl;

		cin >> selection;

		if (is_int(selection) == true) {

			switch (stoi(selection)) {

			case 1:{
				//�������� ����� ������ ����� � ��������� �� � ������ ����
				truba_type temp_truba;
				temp_truba.vvod();
				temp_truba.vivod();
				pipes.push_back(temp_truba);
			}
				break;

			case 2: {
				//�������� ����� ������ �� � ��������� �� � ������ ��
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
				cout <<endl<< "������� id �����, ������� ������ ������������� "<<endl;
				cin >> id_selection;
				if (is_int(id_selection) == true) {
					for (auto i : pipes) {
						if (i.id == stoi(id_selection)) {
							correct_check = true;
							cout << "�� ������ �������� ��� ��������� ���� ����� ��� ������ �����c �������? (all/service)"<<endl;
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
									cout << "������� all ��� service ��������� ������� "<<endl;
								}
							}
							break;
						}	
					}
					if (correct_check == false) {
						cout << "������� ���� �� id c����������� ���� (����� ���������� �������� 3)"<<endl;
					}
				}
			}
				break;
			case 5: {
				cout << endl << "������� id ��, ������� ������ ������������� " << endl;
				cin >> id_selection;
				if (is_int(id_selection) == true) {
					for (auto i : KS_es) {
						if (i.id == stoi(id_selection)) {
							correct_check = true;
							cout << "�� ������ �������� ��� ��������� ���� �� ��� ������ ���������� ���������� ����� �������? (all/workshops)" << endl;
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
									cout << "������� all ��� workshops ��������� ������� "<<endl;
								}
							}
							break;
						}
					}
					if (correct_check == false) {
						cout << "������� ���� �� id c����������� �� (����� ���������� �������� 3)" << endl;
					}
				}
			}
				break;

			case 6: {
				//������� �����
				fout.open("truba.txt");
				fout << "";
				fout.close();
				//���������� ���� � ����
				fout.open("truba.txt", std::ios::app);

				for (auto i : pipes) {
					i.save(fout);
				}
				fout.close();

				//������� �����
				fout.open("KS.txt");
				fout << "";
				fout.close();
				//���������� ���� � ����
				fout.open("KS.txt", std::ios::app);

				for (auto i : KS_es) {
					i.save(fout);
				}
				fout.close();
			}
				break;

			case 7: {
				//��� ����
				//��������� ����� ����� � ������ ����������
				fin.open("truba.txt");
				
				if (fin.is_open() == false) {
					cout << endl << "���� 'truba.txt' �� ������!!!!" << endl;
					break;
				}

				while (std::getline(fin, temp_string)) ++Lines;
				fin.close();
				//��������������� ���� ��������
				fin.open("truba.txt");
				if (Lines == 0) {
					cout << "���� ���������� ���� ����. ��������� ������.";
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

				//��� ��
				//��������� ����� ����� � ������ ����������
				fin.open("KS.txt");

				if (fin.is_open() == false) {
					cout << endl << "���� 'KS.txt' �� ������!!!!" << endl;
					break;
				}

				while (std::getline(fin, temp_string)) ++Lines;
				fin.close();
				//��������������� ���� ��������
				fin.open("KS.txt");
				if (Lines == 0) {
					cout << "���� ���������� �� ����. ��������� ������.";
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
				cout << "������� ����� �� 0 �� 7 ��� ������ ��������" << endl;
			}







			}
		}
		else {
			cout << "������� ����� �� 0 �� 7 ��� ������ ��������" << endl;
		}
		system("pause");
		system("cls");
	}


	

	

	







	





	
	

	return 0;
}