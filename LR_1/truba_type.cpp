#include "truba_type.h"

using namespace std;

void truba_type::vvod() {
	cout << "������� ��������� ��� �����:" << endl;

	cout << "������� id �����" << endl;
	cin >> this->id;

	cout << "������� ����� �����" << endl;
	cin >> this->length;

	cout << "������� ������� �����" << endl;
	cin >> this->diameter;

	string temp_string; //��������� ������
	
	cout << "� ������� �� ����� (yes/no)" << endl;
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
			cout << "������� 'yes' ��� 'no' (��������� �������)";
		}
		cout << endl;
		cin >> temp_string;
	}

	cout << "���� ���������� ��������"<<endl;

}

void truba_type::vivod() {
	cout << endl <<"��������� ��������������� �����:" << endl;

	cout << "Id ����� : "<< this->id << endl;

	cout << "����� �����: "<< this->length << endl;

	cout << "������� �����: "<< this->diameter << endl;

	string temp_string; //��������� ������

	if (this->in_servise == 1) temp_string = "yes";
	else temp_string = "no";

	cout << "� ������� �� ����� (yes/no) : "<< temp_string << endl;


}