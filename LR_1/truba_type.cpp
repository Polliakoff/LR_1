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