#include <iostream>
#include "truba_type.h"
#include "KS_type.h"
#include <string>
using namespace std;


int main() {

	setlocale(LC_ALL, "Russian");

	//��������� ���������� ��� ������ �����
	int temp_int;
	double temp_double;
	string temp_string;
	
	//���������� ���������� ���������������� �����
	truba_type pipe_1;
	KS_type KS_1;

	//���� ���������� �����
	pipe_1.vvod();

	//����� ��������� ���������� �����
	pipe_1.vivod();

	//��������� ��������� ����� � �������/ �� � �������
	pipe_1.servise();


	//���� ���������� ��
	KS_1.vvod();

	//����� ��������� ���������� ��
	KS_1.vivod();

	//��������� ����� ���������� �����
	KS_1.number_working();

	

	

	







	





	
	
	system("Pause");
	return 0;
}