#include <iostream>
#include "truba_type.h"
#include "KS_type.h"
#include <string>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");

	//������� �������
	vector <truba_type> pipes;
	vector <KS_type> KS_es;

	string temp_string;//���������� ��������� ���������� (��������� ������ �. �. ������������ �����������)

	while (true) {

		cout << "�������� �������� ������� ���������� �����������: " <<
			endl << "1 - �������� ����� " << endl << "2 - �������� �� " << endl
				<< "3 - �������� ���� �������� " << endl << "4 - ������������� ����� " << endl
					<< "5 - ������������� �� " << endl << "6 - ��������� (����� ����������������) " << endl 
						<< "7 - ��������� (����������� ��������� ��������� � ������������ � ������� ������������� ID)" 
							<< endl << "0 - �����" <<endl<<"����: ";
		
		double selection; //���������� ������ ��������
		cin >> selection;

		if (cin.good() && !(selection - floor(selection))) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			switch (int(selection)) {

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

				if (pipes.size() == 0 && KS_es.size() == 0) {
					cout << endl << "�� ������ ������ � ����������� ������ ��� �� ������ �������"<<endl;
				}
				else {
					for (auto i : pipes) {
						i.vivod();
					}

					for (auto i : KS_es) {
						i.vivod();
					}
				}
				
			}
				break;

			case 4: {
				cout <<endl<< "������� id �����, ������� ������ ������������� "<<endl;
				double id_selection;
				bool correct_check = false;
				cin >> id_selection;
				if (cin.good() && !(id_selection - floor(id_selection))) {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					for (size_t i = 0; i < pipes.size();i++ ) {
						if (pipes[i].id == id_selection) {
							correct_check = true;
							cout << "�� ������ �������� ��������� ���� ����� ��� ������ �����c �������?"
								<<endl<<"��������� - 1, ������ ������� - 2"<<endl;
							while (true) {
								cin >> temp_string;
								if (temp_string == "1") {
									pipes[i].vvod();
									pipes[i].vivod();
									break;
								}
								else if (temp_string == "2") {
									pipes[i].servise();
									pipes[i].vivod();
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
				else {
					cout << "������� ���� �� id c����������� ���� (����� ���������� �������� 3)" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
				break;
			case 5: {
				cout << endl << "������� id ��, ������� ������ ������������� " << endl;
				double id_selection;
				bool correct_check = false;
				cin >> id_selection;
				if (cin.good() && !(id_selection - floor(id_selection))) {
					for (size_t i = 0; i < KS_es.size(); i++) {
						if (KS_es[i].id == id_selection) {
							correct_check = true;
							cout << "�� ������ �������� ��� ��������� ���� �� ��� ������ ���������� ���������� �����? " 
								<< endl <<"��� - 1, ���-�� ����� - 2"<<endl;
							while (true) {
								cin >> temp_string;
								if (temp_string == "1") {
									KS_es[i].vvod();
									KS_es[i].vivod();
									break;
								}
								else if (temp_string == "2") {
									KS_es[i].number_working();
									KS_es[i].vivod();
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
				else {
					cout << "������� ���� �� id c����������� �� (����� ���������� �������� 3)" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
				break;

			case 6: {
				ofstream fout;
				//������� �����
				fout.open("save.txt");
				fout << "";
				fout.close();
				//���������� ���� � ����
				fout.open("save.txt", std::ios::app);

				for (auto i : pipes) {
					i.save(fout);
				}

				for (auto i : KS_es) {
					i.save(fout);
				}

				fout.close();
			}
				break;

			case 7: {
				ifstream fin;//�������� ������ ������ �� �����
				
							 //�������� �� �����

				fin.open("save.txt");
				
				if (fin.is_open() == false) {
					cout << endl << "���� 'save.txt' �� ������!!!!" << endl;
					break;
				}

				//�������� �� ������ �� ���� (����������� �� ���� ��� ��)
				size_t p_siz, k_siz;
				p_siz = pipes.size();
				k_siz = KS_es.size();
				
				while(std::getline(fin, temp_string)){
						
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

				if(p_siz == pipes.size() && k_siz == KS_es.size()){
					cout << endl << "���� 'save.txt' ����!!!!" << endl;
				}
			
				fin.close();



			}
				break;
			
			case 0: {
				return 0;
			}
				break;

			default: {
				cout << "������� ����� �� 0 �� 7 ��� ������ ��������" << endl;
			}

			}
		}
		else {
			cout << "������� ����� �� 0 �� 7 ��� ������ ��������" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
		system("pause");
		system("cls");
	}
	return 0;
}