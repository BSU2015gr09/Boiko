#include <iostream>
#include <locale>
using std::cout;
using std::cin;
int main(){
	// Сумма чисел до первого введённого отрицательного
	setlocale(LC_ALL, "Russian");
	int number = 1, summ = -1;//прикольненько!!!!!
	while (number >= 0){
		summ = summ + number;
		cout << "Введите число: "; cin >> number;
	}
	cout << "Сумма чисел: " << summ << "\n";
	return 0;
}
