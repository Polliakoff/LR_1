#include <iostream>
#include "truba_type.h"
#include "KS_type.h"
#include <string>
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	
	//���������� ���������� ���������������� �����
	truba_type pipe_1;
	KS_type KS_1;
	
	int selection;

	cout << "�� ������ ������ ������ ��� ��������� �� �� �����?" <<
		endl << "1 - ������ � ���������, 2 - ���������" << endl;
	
	while (true) {

		cin >> selection;
		if (selection == 1) {



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
		
		else if (selection == 2) {
			//�������� � ����������� ������ �����
			pipe_1.load();
			pipe_1.vivod();
			KS_1.load();
			KS_1.vivod();
			
			break;
		}

		else {
			cout << "������� ����� 1 ��� 2 ��� ������ ��������"<<endl;
			continue;
		}
	}


	

	

	







	





	
	
	system("Pause");
	return 0;
}