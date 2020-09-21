#include "truba_type.h"

using namespace std;


truba_type::truba_type()
{

}

truba_type::~truba_type()
{

}

void truba_type::vvod() {
	
	string temp_string;//��������� ������

	cout << endl << "������� ��������� ��� �����:" << endl;

	cout << "������� id �����" << endl;

	while (true) {
		cin >> temp_string;

		if (is_int(temp_string) == true) {
			this->id = stoi(temp_string);
			break;
		}
		else {
			cout << "������� ����� �����"<<endl;
		}

	}

	cout << "������� ����� �����" << endl;

	while (true) {
		cin >> temp_string;

		if (is_double(temp_string) == true) {
			this->length = stod(temp_string);
			break;
		}
		else {
			cout << "������� ������������ �����" << endl;
		}

	}

	cout << "������� ������� �����" << endl;
	
	while (true) {
		cin >> temp_string;

		if (is_double(temp_string) == true) {
			this->diameter = stod(temp_string);
			break;
		}
		else {
			cout << "������� ������������ �����" << endl;
		}

	}

	
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
	cout << endl <<"��������� ��������������� �����: " << endl;

	cout << "Id ����� : "<< this->id << endl;

	cout << "����� �����: "<< this->length << endl;

	cout << "������� �����: "<< this->diameter << endl;

	string temp_string; //��������� ������

	if (this->in_servise == 1) temp_string = "yes";
	else temp_string = "no";

	cout << "� ������� �� ����� (yes/no) : \t "<< temp_string << endl;


}

void truba_type::servise() {
	
	string temp_string; //��������� ������
	
		cout << endl << "������ �� �� �������� ������ ������� �����? (yes/no)" << endl;
		cin >> temp_string;
		
		while (true) {

			if (temp_string == "yes") {
				break;
			}
			else if (temp_string == "no") {
				return;
			}
			else {
				cout << "������� 'yes' ��� 'no' (��������� �������)";
			}
			cout << endl;
			cin >> temp_string;
		}



		cout << endl << "� ������� �� ����� (yes/no)" << endl;
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

		if (this->in_servise == 1) temp_string = "yes";
		else temp_string = "no";

		cout << "� ������� �� ����� ������ (yes/no) : " << temp_string << endl;
	
}


void truba_type::save() {
	
	ofstream fout("truba.txt"); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������ truba.txt
	// ������ ����� � ����
	fout << this->id<<"|"<< this->length << "|" <<
		this->diameter << "|" <<this->in_servise << "|" << ";";
	fout.close(); // ��������� ����
}

void truba_type::load() {

	string load_string; //������ � ������ ������� ������ �� �����
	string temp_string; //��������� ������
	ifstream fin("truba.txt"); // ������� ���� ��� ������
	getline(fin, load_string, ';'); // �������� ������ ������
	fin.close(); // ��������� ����
	//�������� ��� �����
	int i = 0;
	int j = 0;
	temp_string = "";//�������������� ��������� ������
	while (true) {
		if (load_string[i] != '|') {
			temp_string += load_string[i];
		}
		else {
			switch (j) {
			case 0:
				this->id = stoi(temp_string);
					break;
			case 1:
				for (int k=0;k< temp_string.length();k++) {
					if (temp_string[k] == '.') temp_string[k] = ',';
				}
				this->length = stod(temp_string);
					break;
			case 2:
				for (int k = 0; k < temp_string.length(); k++) {
					if (temp_string[k] == '.') temp_string[k] = ',';
				}
				this->diameter = stod(temp_string);
				break;

			case 3:
				this->in_servise = stoi(temp_string);
				cout << endl << "����� ������� ��������� �� �����!"<<endl;
				break;
			}
			
			temp_string = "";
			j++;
		}
		if (i + 1 < load_string.length())i++;
		else return;
		
	}


}

