#include <iostream> 
#include <clocale> 
using std::cout;
using std::cin;
int main() {
	setlocale(LC_ALL, "Russian");
	int n = 0, p = 0, m = 0, k = 0, i = 0;
	cout << "Введите число: "; cin >> n; p = n;
	while (p > 0){
		m = p % 10;
		k = k * 10 + m;
		p = p / 10;
	}
	if (n == k) {
		cout << "Число " << n << " симметричное\n";
	}
	else {
		cout << "Число " << n << " несимметричное\n";
	}
	return 0;
}