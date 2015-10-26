#include <iostream>
#include <clocale>
using std::cin;
using std::cout;
int main() {
	// Линейный генератор псевдослучайных чисел
	setlocale(LC_ALL, "Russian");
	int a[10];//совсем неудачно!!!! Достаточно ведь одной переменной - для ТЕКУЩЕГО случ.числа
	int n1 = 4096, n2 = 150889, n3 = 714025, i = 1;
	a[0] = 1;
	cout << "1: " << a[0] << "\n";
	while (i < 10){
		a[i] = (n1 * a[i - 1] + n2) % n3;
		cout << i + 1 << ": " << a[i] << "\n";
		i++;
	}
	return 0;
}
