#include <iostream>
#include "truba_type.h"
#include "KS_type.h"
#include <string>
#include "func.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	
	//���������� ���������� ���������������� �����
	truba_type pipe_1;
	KS_type KS_1;
	
	string selection; //���������� ������ ������ ������

	cout << "�� ������ ������ ������ ��� ��������� �� �� �����?" <<
		endl << "1 - ������ � ���������, 2 - ���������" << endl;
	
	while (true) {

		cin >> selection;

		if (is_int(selection) == true) {

			if (stoi(selection) == 1) {



				//���� ���������� �����
				pipe_1.vvod();

				//����� ��������� ���������� �����
				pipe_1.vivod();

				//��������� ��������� ����� � �������/ �� � �������
				pipe_1.servise();

				//���������� � ���� ���������� �����
				pipe_1.save();

				//���� ���������� ��
				KS_1.vvod();

				//����� ��������� ���������� ��
				KS_1.vivod();

				//��������� ����� ���������� �����
				KS_1.number_working();

				//���������� � ���� ���������� ��
				KS_1.save();

				break;
			}

			else if (stoi(selection) == 2) {
				//�������� ������ �����
				pipe_1.load();
				//�������� ������ ��
				KS_1.load();
				//����� ������ �����
				pipe_1.vivod();
				//����� ������ ��
				KS_1.vivod();





				break;
			}

			else {
				cout << "������� ����� 1 ��� 2 ��� ������ ��������" << endl;
				continue;
			}
		}
		else {
			cout << "������� ����� 1 ��� 2 ��� ������ ��������" << endl;
		}
	}


	

	

	







	





	
	
	system("Pause");
	return 0;
}