#include <iostream>
#include <clocale>
using std::cin;
using std::cout;
using namespace std;
int main(){
	setlocale(LC_ALL, "Russian");
	int number = 0, p = 0, k = 0, m = 0;
	cout << "������� ����� "; cin >> number; p = number;
	while (p > 0){
		k = p % 10;
		m = m * 10 + k;
		p = p / 10;
	}
	cout << "������ ����� " << number << " : " << m << "\n";
	return 0;
}