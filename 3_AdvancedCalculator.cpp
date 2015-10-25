#include <iostream>
#include <clocale>
#include <cmath>
using std::cout;
using std::cin;
int main(){ // Калькулятор. Обработка деления на 0, выход по нажатию клавиши 'e' вместо операции, бесконечное вычисление до операции '='
	// P.S. без всяких goto, корректный результат при работе с дробными числами, понятный код!!!
	char operation = 0;
	float result = 0, a = 0, b = 0;
	setlocale(LC_ALL, "Russian");
	cout << "Операция 'e' - выход, 'c' - обнуление\n\n";
	cout << "Значение: ";
	cin >> a;
	while (operation != '='){
			cout << "Операция: ";
			cin >> operation;
		if ((operation != '=') && (operation != 'e') && (operation != 'c')){ // Предусмотрены все повороты событий: если вводится '=', 'e' или 'c', программа не просит ввести второе значение и вообще всё идеально
			cout << "Значение: ";
			cin >> b;
		}
		switch (operation){
		case '+': result = a + b;
			break;
		case '-': result = a - b;
			break;
		case '*': result = a * b;
			break;
		case '/':
			if (b == 0) {
				cout << "Делить на 0 нельзя\n";
				cout << "Значение: ";
				cin >> a;}
			else
				(float)result = (float)a / b;
			break;
		case 'c': result = 0;
			cout << "Обнуление\n";
			cout << "Значение: ";
			cin >> a;
			break;
		case '=':
			break;
		case 'e': exit(0);
		default:
			break;
		}
		if ((operation != 'c') && (b != 0)){
			a = result;
		}
	}
	cout << "Полученное значение: " << result << "\n";
	return 0;
}