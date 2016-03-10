#include <iostream> 
#include <clocale>
using std::cout;
using std::cin;
int main() {
	//Вычисление цифр числа до первого встречного нуля
	setlocale(LC_ALL, "Russian");
	int number = 0, m = 0, k = 0, kk = 0, p = 0, t = 0;
	cout << "Введите число: "; cin >> number; m = number;
	while (m > 0){
		k = m % 10;
		if (k == 0){
			while (m > 0){
				kk = m % 10;
				if (kk == 0){
					p = 0; kk = 0;
				}
				p = p + kk;
				m = m / 10;
			}
		}
		else{
		}
		m = m / 10;
	}
	cout << "Сумма цифр числа до нуля: " << p << "\n";
	return 0;
}
