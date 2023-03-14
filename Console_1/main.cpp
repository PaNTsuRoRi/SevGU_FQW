#include "windows.h"
#include "logic.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа

	Logic logic;
	vector <int> myStat;
	int min = INT16_MAX, max = 0, sum = 0;
	double average = 0;

	cout << "Тесты:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "\nТест №" << i+1 << endl;
		logic.start();
		cout << "---------------------------------------------" << endl;
	}
	
	cout << "\nСтатистика:\n" << endl;
	myStat = logic.getMyStat();
	for (int i = 0; i < myStat.size(); i++) {
		if (myStat[i] < min) { min = myStat[i]; }
		if (myStat[i] > max) { max = myStat[i]; }
		sum += myStat[i];
		average = sum / myStat.size();
	}
	cout << "Мин: " << min << "\nМакс: " << max << "\nСреднее: " << average << endl;
	cout << "\nУчитываются только тесты где значение восстановлено" << endl;
	cin.get();
}