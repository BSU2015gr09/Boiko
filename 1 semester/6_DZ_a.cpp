#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;
const int maxsize = 100;
int tmp = 0; // не понял смысла этой глобальной переменой!!! Ведь у Вас pop ВОЗВРАЩАЕТ значение элемента.

bool push(int a[], int &t, int elem){
	a[t++] = elem;
	if (t >= maxsize) return 0;
	else return 1;
}

int pop(int a[], int &t){
	if (t == 0) return 0;
	else {
		tmp = a[t-1];
		a[t--] = 0;//зачем???? почему не просто t-- зачем еще обнулять?
		return a[t]; // НЕ ТО, что рассказывалось на практике!!! Классика - это возвращать ТО ЧТО В ВЕРШИНЕ и менять кол-во элементов в стеке
	}
}

int print(int a[]){
	for (int i = maxsize-1; i >= 0; i--){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

int view(int a[], int t){
	cout << "Вершина стека: " << a[t-1] << endl;
	return 0;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int a[maxsize] = { 0 };
	int top = 0, element = 0;
	// FIFO и LIFO
	print(a);
	for (int i = 0; i < 3; i++){
		cout << "Помстить число в стек: ";
		cin >> element;
		push(a, top, element); // вставить в конец массива
	}
	view(a, top);
	cout << "Количество элементов в стеке: " << top << endl << "Изъятие..." << endl;
	pop(a, top);
	cout << "Количество элементов в стеке: " << top << endl;
	pop(a, top);
	cout << "Достали элемент: " << tmp << endl << "_______" << endl << "Изъятие..." << endl;
	cout << "Количество элементов в стеке: " << top << endl;
	pop(a, top);
	cout << "Достали элемент: " << tmp << endl << "_______" << endl << "Изъятие..." << endl;
	cout << "Количество элементов в стеке: " << top << endl;
	cout << "Достали элемент: " << tmp << endl;
	cout << "Попытка изъятия..." << endl;
	if (!pop(a, top)) {
		cout << "Ошибка..";
	}
	cout << "Помстить число в стек: ";
	cin >> element;
	push(a, top, element);
	cout << "Количество элементов в стеке: " << top << endl;
	print(a);

	cout << endl;
	system("pause");
}
