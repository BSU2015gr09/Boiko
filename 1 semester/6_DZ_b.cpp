#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;

// Удаляем n-й элемент из массива и смещаем остальные

int init_a(int a[], int const n){
	cout << "Числа через пробел: ";
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	return 1;
}

int print(int a[], int const n){
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 1;
}

int delete_elem(int a[], int const n){
	int del = 0;
	cout << "Номер элемента, который нужно удалить (0-10): ";// хоть бы выводил от 0 до n, а не до 10 
	cin >> del;
	for (int i = del; i < n-1; i++){
		a[i] = a[i + 1];
	}
	a[n - 1] = 0;
	return 1;
}

int main(){
	setlocale(LC_ALL, "Russian");
	const int n = 10;
	int a[n] = { 0 };

	init_a(a, n);
	print(a, n);
	delete_elem(a, n);
	print(a, n);

	cout << endl;
	system("pause");
}
