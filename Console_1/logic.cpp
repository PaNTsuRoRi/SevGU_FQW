#include "logic.h"

//Запуск программы
void Logic::start() {
	gpsc = initializer(); //генерация значений
	print(gpsc); //вывод сгенерированных значений
	voMappings = vecVO(gpsc); //вероятносто отображаем значения
	recovery(gpsc, voMappings); //восстанавливаем значения
}

//Функция возвращает вектор случ знач из таблицы ASCII
vector <unsigned char> Logic::initializer() {
	vector <unsigned char> gpsc;
	for (int i = 0; i < numOfValues; i++) {
		unsigned char x = rand() % 255;
		gpsc.push_back(x);
	}
	return gpsc;
}

//Функция печати вектора значений из таблицы ASCII
void Logic::print(vector <unsigned char> gpsc) {
	cout << "\nСгенерированный вектор символов:\n";
	for (int i = 0; i < gpsc.size(); i++) {
		cout << (gpsc[i]) << " ";
	}
	cout << endl;
}

//Функция возвращает вектор вероятностного отображения
vector <int> Logic::vecVO(vector <unsigned char> gpsc) {
	vector <int> voMappings;
	int counter_ones = 0; //количество единиц в векторе
	unsigned char x = rand() % 255;
	cout << "\nСимвол для ВО: " << x << endl;
	cout << "\nВектор вероятностного отображения:" << endl;
	for (int i = 0; i < gpsc.size(); i++) { //заполняем вектор вероятностного отображения 0 или 1
		if ((int)x >= (int)gpsc[i]) {
			voMappings.push_back(1);
			counter_ones += 1;
		}
		else
			voMappings.push_back(0);
		cout << voMappings[i] << " ";
	}
	cout << "\n\nЕдиниц в векторе: " << counter_ones << "; ";
	return voMappings;
}

//Функция восстановления вектора значений
void Logic::recovery(vector <unsigned char> gpsc, vector <int> voMappings) {
	int min = 0, max = 255, diff = 0;
	for (int i = 0; i < voMappings.size(); i++) { //проходим по вектору вероятностного отображения
		if (voMappings[i] == 1 && (int) gpsc[i] > min) { min = gpsc[i]; }
		if (voMappings[i] == 0 && (int) gpsc[i] < max) { max = gpsc[i]; }
		if (max - min == 1) {
			cout << " Восстановленное значение: " << (unsigned char)min << " - на " << i + 1 << " итерации\n";
			myStat.push_back(i + 1);
			break;
		}
	}
	diff = max - min;
	if (diff != 1) {
		if (diff % 2 == 0) diff /= 2;
		else diff = (diff + 1) / 2;
		cout << " Восстановленное значение: " << (unsigned char) (min + diff) << "; Возможная погрешность: " << diff << " символ(а/ов)" << endl;
	}
}

vector <int> Logic::getMyStat() {
	return this->myStat;
}