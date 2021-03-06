#include <iostream>
#include <clocale>
using std::cin;
using std::cout;

// псевдорандомный генератор
int xor_random(int x){ 
	int tmp = 0;
	tmp ^= x << 13;
	tmp ^= tmp >> 15;
	x ^= tmp << 5;
	return x;
}

// инициализация массива (-50;50)
int init_array(int a[], const int n){ 
	for (int i = 0; i < n; i++){
		a[i] = xor_random(i % 6663) % 100 - 50;
		cout << i << ": " << a[i] << "\n";
	}
	return 0;
}

// нахождение максимума и минимума, max и min использую в следующей функции
int max_min_out_array(int a[], const int n, int &max, int &min){ 
	max = a[0], min = a[0];
	for (int i = 0; i < n; i++){
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
			min = a[i];
	}
	return 0;
}

// следующий элемент массива после нулевого заменяется на 999, после первого минимального вставляется 111, перед первым максимальным - 222
int first_null(int a[], const int n){ 
	int max = 0, min = 0, k = 0, m = 0, p = 0;
	max_min_out_array(a, n, max, min);
	for (int i = 0; i < n; i++){
		if (!k){
			if (a[i] == 0){
				a[i + 1] = 999;
				k++;
			}
		}
		if (!m){
			if (a[i] == min){
				a[i + 1] = 111;
				m++;
			}
		}
		if (!p){
			if (a[i] == max){
				a[i - 1] = 222;
				p++;
			}
		}
		if (k && m && p){
			break;
		}
	}
	for (int i = 0; i < n; i++){
		cout << i << ": " << a[i] << "\n";
	}
	return 0;
}

int main(){
	setlocale(LC_ALL, "Russian");
	const int n = 30;
	int a[n];
	init_array(a, n);
	first_null(a, n);
	return 0;
}