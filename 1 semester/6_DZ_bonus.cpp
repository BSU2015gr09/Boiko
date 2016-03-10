#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;
const int maxsize = 10;

// программа, которая реализует очередь 5 целых чисел на массиве

bool push(int a[], int &t, int elem){
	a[t++] = elem;
	if (t >= maxsize) return 0;// нет, так не сработает... Объяснение было на практике!!!!
	else return 1;
}

int pop(int a[], int &t){
	if (maxsize == 0) return 0;
	else {
		for (int i = 0; i < t; i++){
			a[i] = a[i + 1];
		}
		t--;
		return 1;
	}
}

int print(int a[]){
	for (int i = maxsize - 1; i >= 0; i--){
		cout << setfill(' ') << setw(3) << a[i] << " ";
	}
	cout << endl;
	return 0;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int a[maxsize] = { 0 };
	int top = 0, element = 0;

	cout << "Пустая очередь:\t\t"; print(a);

	for (int i = 0; i < 5; i++){
		element = rand() % 50 + 1;
		push(a, top, element);
		cout << "Добавили элемент:\t"; print(a);
	}

	pop(a, top);
	cout << "Обработали элемент:\t"; print(a);
	pop(a, top);
	cout << "Обработали элемент:\t"; print(a);

	for (int i = 0; i < 3; i++){
		element = rand() % 50 + 1;
		push(a, top, element);
		cout << "Добавили элемент:\t"; print(a);
	}

	cout << endl;
	system("pause");
}
