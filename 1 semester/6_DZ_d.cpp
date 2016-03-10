#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

// последнюю букву Z из массива заменяем на F

int init_a(char a[], int const n){
	cout << "20 бкув латинского алфавита через пробел: ";// опять пробел????
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

int replace_elem(char a[], int const n){
	for (int i = n-1; i >= 0; i--){
		if (a[i] == 'z'){
			a[i] = 'f';
			break;
		}
	}
	return 1;
}

int main(){
	setlocale(LC_ALL, "Russian");
	const int n = 20;
	char a[n] = { 0 };

	init_a(a, n);
	print(a, n);
	replace_elem(a, n);
	print(a, n);

	cout << endl;
	system("pause");
}
