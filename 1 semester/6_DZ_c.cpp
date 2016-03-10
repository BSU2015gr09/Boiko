#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

//  Какая буква встречается в массиве чаще всего

int init_a(char a[], int const n){
	cout << "20 бкув латинского алфавита через пробел: ";// так уж через пробел обязательно?????
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	return 1;
}

int print(char a[], int const n){
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 1;
}

int max_elem(char a[], int const n, int b[]){
	int max = 0;
	for (int i = 0; i < n; i++){
		for (int l = 0; l < n; l++){
			if (a[i] == a[l]) {
				b[l]++;
			}
			if (b[l] > max) max = l;
		}
	}
	cout << "Наиболее часто встречается буква " << a[max];
	return 1;
}

int main(){
	setlocale(LC_ALL, "Russian");
	const int n = 20;
	int b[n] = { 0 };
	char a[n] = { 0 };
	char max_l = 0;

	init_a(a, n);
	print(a, n);
	max_elem(a, n, b);

	cout << endl;
	system("pause");
}
