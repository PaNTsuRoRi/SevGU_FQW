#include "logic.h"

//������ ���������
void Logic::start() {
	gpsc = initializer(); //��������� ��������
	print(gpsc); //����� ��������������� ��������
	voMappings = vecVO(gpsc); //����������� ���������� ��������
	recovery(gpsc, voMappings); //��������������� ��������
}

//������� ���������� ������ ���� ���� �� ������� ASCII
vector <unsigned char> Logic::initializer() {
	vector <unsigned char> gpsc;
	for (int i = 0; i < numOfValues; i++) {
		unsigned char x = rand() % 255;
		gpsc.push_back(x);
	}
	return gpsc;
}

//������� ������ ������� �������� �� ������� ASCII
void Logic::print(vector <unsigned char> gpsc) {
	cout << "\n��������������� ������ ��������:\n";
	for (int i = 0; i < gpsc.size(); i++) {
		cout << (gpsc[i]) << " ";
	}
	cout << endl;
}

//������� ���������� ������ �������������� �����������
vector <int> Logic::vecVO(vector <unsigned char> gpsc) {
	vector <int> voMappings;
	int counter_ones = 0; //���������� ������ � �������
	unsigned char x = rand() % 255;
	cout << "\n������ ��� ��: " << x << endl;
	cout << "\n������ �������������� �����������:" << endl;
	for (int i = 0; i < gpsc.size(); i++) { //��������� ������ �������������� ����������� 0 ��� 1
		if ((int)x >= (int)gpsc[i]) {
			voMappings.push_back(1);
			counter_ones += 1;
		}
		else
			voMappings.push_back(0);
		cout << voMappings[i] << " ";
	}
	cout << "\n\n������ � �������: " << counter_ones << "; ";
	return voMappings;
}

//������� �������������� ������� ��������
void Logic::recovery(vector <unsigned char> gpsc, vector <int> voMappings) {
	int min = 0, max = 255, diff = 0;
	for (int i = 0; i < voMappings.size(); i++) { //�������� �� ������� �������������� �����������
		if (voMappings[i] == 1 && (int) gpsc[i] > min) { min = gpsc[i]; }
		if (voMappings[i] == 0 && (int) gpsc[i] < max) { max = gpsc[i]; }
		if (max - min == 1) {
			cout << " ��������������� ��������: " << (unsigned char)min << " - �� " << i + 1 << " ��������\n";
			myStat.push_back(i + 1);
			break;
		}
	}
	diff = max - min;
	if (diff != 1) {
		if (diff % 2 == 0) diff /= 2;
		else diff = (diff + 1) / 2;
		cout << " ��������������� ��������: " << (unsigned char) (min + diff) << "; ��������� �����������: " << diff << " ������(�/��)" << endl;
	}
}

vector <int> Logic::getMyStat() {
	return this->myStat;
}