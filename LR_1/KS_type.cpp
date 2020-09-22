#include "KS_type.h"
using namespace std;

KS_type::KS_type()
{

}

KS_type::~KS_type()
{

}

void KS_type::vvod() {
	string temp_string;//��������� ������
	
	cout << endl << "������� ��������� ��� ��:" << endl;

	cout << "������� id ��" << endl;
	
	while (true) {
		cin >> temp_string;

		if (is_int(temp_string) == true) {
			this->id = stoi(temp_string);
			break;
		}
		else {
			cout << "������� ����� �����" << endl;
		}

	}

	cout << "������� �������� ��" << endl;
	cin >> this->name;

	cout << "������� ����� ����� ��" << endl;
	
	while (true) {
		cin >> temp_string;

		if (is_int(temp_string) == true) {
			this->workshop_number = stoi(temp_string);
			break;
		}
		else {
			cout << "������� ����� �����" << endl;
		}

	}

	int temp_int; //��������� ������������ ����������
	
	cout << "������� ����� ���������� ����� �� (<= ����� �����)" << endl;

	while (true) {
		cin >> temp_string;

		if (is_int(temp_string) == true) {
			temp_int = stoi(temp_string);
		}
		else {
			cout << "������� ����� �����" << endl;
			continue;
		}

		if (temp_int <= this->workshop_number) {
			this->working_workshops = temp_int;
			break;
		}
		else {
			cout << "������� ����� <= ����� �����" << endl;
			continue;
		}
	}
	
	while (true) {
		if (temp_int <= this->workshop_number) {
			this->working_workshops = temp_int;
			break;
		}
		else cout << "������� ����� <= ����� �����"<<endl;
		cin >> temp_int;
	}

	cout << "������� ������������� ��" << endl;
	
	while (true) {
		cin >> temp_string;

		if (is_double(temp_string) == true) {
			this->effectiveness = stod(temp_string);
			break;
		}
		else {
			cout << "������� ������������ �����" << endl;
		}

	}
	
	this->is_loaded = true;
	cout << "���� ���������� ��������" << endl;

}

void KS_type::vivod() {
	if (this->is_loaded == true) {
		cout << endl << "��������� ��������������� ��:" << endl;

		cout << "Id �� : " << this->id << endl;

		cout << "�������� ��: " << this->name << endl;

		cout << "����� ����� ��: " << this->workshop_number << endl;

		cout << "����� ���������� ����� ��: " << this->working_workshops << endl;

		cout << "������������� ��: " << this->effectiveness << endl;
	}
	else {
		cout << endl << "��������� �� �����!" << endl;
	}

}
//��������� ���-�� ������� �����
void KS_type::number_working() {

	string temp_string; //��������� ������

	cout << endl << "������ �� �� ���������/�������� ��� ��? (yes/no)" << endl;
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




	while (true) {
		cout << endl << "�� ������ ���������, �������� ��� ��� �����? (on/off/quit)" << endl;
		cin >> temp_string;
		
		if (temp_string == "on") {
			if((this->working_workshops+1)<=this->workshop_number) this->working_workshops++;
			else {
				cout << "���������� ������������ ����� ���������� �����";
				continue;
			}
			break;
		}
		else if (temp_string == "off") {
			if ((this->working_workshops - 1) >= 0) this->working_workshops--;
			else {
				cout << "���������� ����� ��� ���";
				continue;
			}
			break;
		}
		
		else if (temp_string == "quit") {
			break;
		}
		
		else {
			cout << "������� 'on', 'off' ��� 'quit' (��������� �������)";
		}
		cout << endl;
	}

	cout << "����� ���������� ����� �� ������ ������ :" << this->working_workshops << endl;





}
//���������� � ����
void KS_type::save() {

	ofstream fout("KS.txt"); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������ truba.txt
	// ������ ����� � ����
	fout << this->id << "|" << this->name << "|" <<
		this->workshop_number << "|" << this->working_workshops <<"|"<< this->effectiveness << "|" << ";";
	fout.close(); // ��������� ����
}
//�������� �� �����
void KS_type::load() {

	string load_string; //������ � ������ ������� ������ �� �����
	string temp_string; //��������� ������
	ifstream fin("KS.txt"); // ������� ���� ��� ������
	//�������� �� ������� �����
	if (fin.is_open() == false) {
		cout << endl << "���� 'KS.txt' �� ������!!!!!" << endl;
		return;
	}
	
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
				this->name = temp_string;
				break;
			case 2:
				this->workshop_number = stoi(temp_string);
				break;

			case 3:
				this->working_workshops = stoi(temp_string);
				break;

			case 4:
				for (int k = 0; k < temp_string.length(); k++) {
					if (temp_string[k] == '.') temp_string[k] = ',';
				}
				this->effectiveness = stod(temp_string);
				cout << endl << "�� ������� ��������� �� �����!" << endl;
				this->is_loaded = true;
				break;
			}

			temp_string = "";
			j++;
		}
		if (i + 1 <= load_string.length())i++;
		else return;

	}

}