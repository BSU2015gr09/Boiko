#include <iostream> 
#include <clocale>
using std::cout;
using std::cin;
int main() {
	setlocale(LC_ALL, "Russian");
	int a = 0, a1 = 0, a2 = 0, n1 = 0, n2 = 0;
	cout << "Введите число: ";
	cin >> a;
	a1 = a; a2 = a;
	while (a1 > 0){
		n1 = n1 + a1 % 10;
		a1 = a1 / 100;
	}
	a2 = a2 / 10;
	while (a2 > 0){
		n2 = n2 + a2 % 10;
		a2 = a2 / 100;
	}
	cout << "Сумма цифр чётных позиций " << n2 - n1 << "\n";
	cout << "Сумма цифр нечётных позиций " << n1 - n2 << "\n";
	if ((n2 == n1) || (n1 - n2 == 11) || (n2 - n1 == 11)){
		cout << "Число делится на 11\n";
	}
	else{
		cout << "Число не делится на 11\n";
	}
	return 0;
}