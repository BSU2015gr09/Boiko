#include <iostream>
#include <clocale>
using std::cin;
using std::cout;
int main() {
	setlocale(LC_ALL, "Russian");
	int number1 = 0, number2 = 0, nc = 0, mc = 0, kc = 0, tc = 0, sum1 = 0, sum2 = 0;
	cout << "Натуральное число: ";
	cin >> number1;
	nc = number2 = kc = number1;
	while (nc > 0){
		mc = nc % 10;
		sum1 += mc;
		nc = nc / 10;
	}
	while (sum1 != sum2){//да, так сработаеты, и это не говнокод, но все еще быдлокод т.к. идёт полный перебор. Прикинь если я введу число 100000000 сколько чисел до следующего придется проверять??????
		sum2 = 0;
		number2++;
		kc = number2;
		while (kc > 0){
			tc = kc % 10;
			sum2 += tc;
			kc = kc / 10;
		}
	}
	cout << number2 << "\n";
	return 0;
}
