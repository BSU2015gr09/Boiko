#include <iostream>
#include <cmath>
#include <clocale>
using std::cin;
using std::cout;
int main(){
	// Решение квадратного уравнения
	setlocale(LC_ALL, "Russian");
	int a = 0, b = 0, c = 0;
	double D = 0, x1 = 0, x2 = 0;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	if (a == 0)  {
		if ((a == 0) && (b == 0)){
			if ((a == 0) && (b == 0) && (c == 0)){
				cout << "х - любое число";
			}
			else {
				cout << "Уравнение не имеет корней";
			}
		}
		if ((a == 0) && (b != 0)){
			x1 = b*(-1);//Это странное выражение я уже встречал. Списано??????
			x1 = c / x1;
			cout << "x = " << x1 << "\n";
		}
	}
	else{
		D = b*b - (a*c * 4);
		if (D > 0){
			D = sqrt(D);
			x1 = (0 - b + D) / (2 * a);
			x2 = (0 - b - D) / (2 * a);
			cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";
		}
		if (D == 0){
			x1=(0 - b) / ( 2 * a);
			cout << "x1 = " << x1 << "\n";
		}
		if (D < 0){
			if (b == 0){
				D = D*(-1);
				D = sqrt(D);
				D = D / (2 * a);
				cout << "x = " << D << "*i" << "\n";
			}
			else{
				D = D*(-1);
				D = sqrt(D);
				D = D / (2 * a);
				x1=(0 - b) / (2 * a);
				cout << "x1 = " << x1 << "+" << D << "*i" << "\n";
				cout << "x1 = " << x1 << "-" << D << "*i" << "\n";
			}
		}
	}
	return 0;
}
