#include <iostream> 
#include <clocale> 
using std::cout;
using std::cin;
int main() {
	setlocale(LC_ALL, "Russian");
	int n = 0, p = 0, m = 0, k = 0, i = 0;
	cout << "������� �����: "; cin >> n; p = n;
	while (p > 0){
		m = p % 10;
		k = k * 10 + m;
		p = p / 10;
	}
	if (n == k) {
		cout << "����� " << n << " ������������\n";
	}
	else {
		cout << "����� " << n << " ��������������\n";
	}
	return 0;
}