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
	void start(); //Запуск программы
	void print(vector <unsigned char> gpsc); //Функция печати вектора значений из таблицы ASCII
	void recovery(vector <unsigned char> gpsc, vector <int> voMappings); //Функция восстановления вектора значений

	vector <int> getMyStat();
	vector <unsigned char> initializer(); //Функция возвращает вектор случ знач из таблицы ASCII
	vector <int> vecVO(vector <unsigned char> gpsc); //Функция возвращает вектор вероятностного отображения
};