#include <iostream>
#include <clocale>
using namespace std;

// инициализация массива
int init_array(int a[], const int n){
	for (int i = 0; i < n; i++){
		cout << "Число (" << i << "): ";
		cin >> a[i];
	}
	cout << endl;
	return 0;
}

// поиск числа в массиве
int search(int a[], const int n){
	int num = 0, i = 0;
	cout << "Введите число, которое нужно найти: ";
	cin >> num;
	for (i = n; i >= 0; i--){
		if (a[i] == num) break;
	}
	cout << num << " имеет индекс " << i << endl; // выведет -1, если число не найдено
	return 0;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int const n = 10;
	int a[n];

	init_array(a, n);
	search(a, n);

	system("pause");
}
