//Ввести целое число,вывести наибольшую цифру и на какой оно позиции
#include <iostream>
#include <clocale>
using std::cin;
using std::cout;
int main(){
	setlocale(LC_ALL, "Russian");
	int number = 0, n = 0, m = 0, max = 0, i = 0, ten = 0;
	cout << "Введите число: "; cin >> number; n = number;
	while (n > 0){
		m = n % 10;
		if (m > max){
			max = m;
		}
		n = n / 10;
		ten++;
	}
	n = number; m = 0;
	while (m != max){
		m = n % 10;
		n = n / 10;
		i++;
	}
	cout << "Максимальная цифра: " << max << ", находящаяеся на позиции " << ten - i + 1 << "\n";
	return 0;
}