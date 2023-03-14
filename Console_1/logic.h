#pragma once

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Logic {
private:
	const int numOfValues = 512;
	vector <unsigned char> gpsc;
	vector <int> voMappings;
	vector <int> myStat;
public:
	void start(); //������ ���������
	void print(vector <unsigned char> gpsc); //������� ������ ������� �������� �� ������� ASCII
	void recovery(vector <unsigned char> gpsc, vector <int> voMappings); //������� �������������� ������� ��������

	vector <int> getMyStat();
	vector <unsigned char> initializer(); //������� ���������� ������ ���� ���� �� ������� ASCII
	vector <int> vecVO(vector <unsigned char> gpsc); //������� ���������� ������ �������������� �����������
};