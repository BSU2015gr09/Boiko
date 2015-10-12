#include <iostream> 
#include <clocale>
using std::cout;
using std::cin;
int main() {
	setlocale(LC_ALL, "Russian");
	int number = 0, m = 0, k = 0, kk = 0, p = 0, t = 0;
	cout << "¬ведите число "; cin >> number; m = number;
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
	cout << "—умма цифр до первого нул€ (даже если число имеет несколько нулей): " << p << "\n";
	return 0;
}