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
	vector<char> items;
	char temp_char;

	while (prodolzhyt == true) {

		cout << "�������� �������� ������� ���������� �����������: " <<
			endl << "1 - �������� ����� " << endl << "2 - �������� �� " << endl
				<< "3 - �������� ���� �������� " << endl << "4 - ������������� ����� " << endl
					<< "5 - ������������� �� " << endl << "6 - ��������� (����� ����������������) " << endl 
						<< "7 - ��������� (����������� ��������� ��������� � ������������ � ������� ������������� ID)" 
							<< endl << "0 - �����" << endl;

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
							cout << "�� ������ �������� ��� ��������� ���� ����� ��� ������ �����c �������?"
								<<endl<<"��� - 1, ������ ������� - 2"<<endl;
							while (true) {
								cin >> temp_string;
								if (temp_string == "1") {
									i.vvod();
									i.vivod();
									break;
								}
								else if (temp_string == "2") {
									i.servise();
									i.vivod();
									break;
								}
								else {
									cout << "������� 1 ��� 2 "<<endl;
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
							cout << "�� ������ �������� ��� ��������� ���� �� ��� ������ ���������� ���������� ����� �������? " 
								<< endl <<"��� - 1, ���-�� ����� - 2";
							while (true) {
								cin >> temp_string;
								if (temp_string == "1") {
									i.vvod();
									i.vivod();
									break;
								}
								else if (temp_string == "2") {
									i.number_working();
									i.vivod();
									break;
								}
								else {
									cout << "������� 1 ��� 2 "<<endl;
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
				fout.open("save.txt");
				fout << "";
				fout.close();
				//���������� ���� � ����
				fout.open("save.txt", std::ios::app);

				for (auto i : pipes) {
					i.save(fout);
				}

				//fout.close();

				//������� �����
				//fout.open("KS.txt");
				//fout << "";
				//fout.close();

				//���������� �� � ����
				//fout.open("save.txt", std::ios::app);

				for (auto i : KS_es) {
					i.save(fout);
				}

				fout.close();
			}
				break;

			case 7: {
				//��������� ����� ����� � ������ ����������
				fin.open("save.txt");
				
				if (fin.is_open() == false) {
					cout << endl << "���� 'save.txt' �� ������!!!!" << endl;
					break;
				}

				while (std::getline(fin, temp_string)) ++Lines;
				
				fin.close();
				//��������������� ���� ��������
				fin.open("save.txt");
				if (Lines == 0) {
					cout << endl << "���� ���������� ���������� ����. ��������� ������." << endl;
				}
				else {
					for (int i = 0; i < Lines; i++) {
						getline(fin, temp_string);
						
						if (temp_string[0] == 't') {
							truba_type temp_truba;
							temp_truba.load(fin, temp_string);
							pipes.push_back(temp_truba);
						}
						else {
							KS_type temp_KS;
							temp_KS.load(fin, temp_string);
							KS_es.push_back(temp_KS);
						}


					}
				}
				fin.close();
				Lines = 0;

				//��� ��
				//��������� ����� ����� � ������ ����������
				//fin.open("KS.txt");

				//if (fin.is_open() == false) {
				//	cout << endl << "���� 'KS.txt' �� ������!!!!" << endl;
				//	break;
				//}

				//while (std::getline(fin, temp_string)) ++Lines;
				//fin.close();
				////��������������� ���� ��������
				//fin.open("KS.txt");
				//if (Lines == 0) {
				//	cout << endl << "���� ���������� �� ����. ��������� ������." << endl;
				//}
				//else {
				//	for (int i = 0; i < Lines; i++) {
				//		KS_type temp_KS;
				//		temp_KS.load(fin);
				//		KS_es.push_back(temp_KS);
				//	}
				//}
				//fin.close();
				//Lines = 0;
					





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