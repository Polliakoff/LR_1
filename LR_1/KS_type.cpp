#include "KS_type.h"
using namespace std;

void KS_type::vvod() {
	cout << endl << "������� ��������� ��� ��:" << endl;

	cout << "������� id ��" << endl;
	cin >> this->id;

	cout << "������� �������� ��" << endl;
	cin >> this->name;

	cout << "������� ����� ����� ��" << endl;
	cin >> this->workshop_number;

	int temp_int; //��������� ������������ ����������
	
	cout << "������� ����� ���������� ����� �� (<= ����� �����)" << endl;
	cin >> temp_int;
	
	while (true) {
		if (temp_int <= this->workshop_number) {
			this->working_workshops = temp_int;
			break;
		}
		else cout << "������� ����� <= ����� �����"<<endl;
		cin >> temp_int;
	}

	cout << "���� ���������� ��������" << endl;

}

void KS_type::vivod() {
	cout << endl << "��������� ��������������� ��:" << endl;

	cout << "Id �� : " << this->id << endl;

	cout << "�������� ��: " << this->name << endl;

	cout << "����� ����� ��: " << this->workshop_number << endl;

	cout << "����� ���������� ����� ��: " << this->working_workshops << endl;

}