#include <iostream> // задание b)
#include <clocale>
using std::cin;
using std::cout;

// псевдорандомный генератор: 
int xor_random(int x){ 
	int tmp = 0;
	tmp ^= x << 13;
	tmp ^= tmp >> 15;
	x ^= tmp << 5;
	return x;
}

// инициализация массива (-50;50): 
int init_array(int a[], const int n){ 
	for (int i = 0; i < n; i++){
		a[i] = xor_random(i % 5000) % 101 - 50;
		cout << i << ": " << a[i] << "\n";
	}
	return 0;
}

// вывод массива в обратном порядке:
int reverse_out_array(int a[], const int n){ 
	for (int i = n - 1; i >= 0; i--){
		cout << i << ": " << a[i] << "\n";
	}
	return 0;
}

// вывод элементов нечётных позиций, затем чётных:
int oe_out_array(int a[], const int n){ 
	for (int i = 0; i < n; i += 2){
		cout << i << ": " << a[i] << "\n";
	}
	for (int i = 1; i < n; i += 2){
		cout << i << ": " << a[i] << "\n";
	}
	return 0;
}

// нахождение кол-ва положительных и отрицательных элементов массива:
int np_out_array(int a[], const int n, int &count_pos, int &count_neg){ 
	for (int i = 0; i < n; i++){
		if (a[i] > 0)
		count_pos++;
		else
		count_neg++;
	}
	cout << "Кол-во положительных: " << count_pos << "\nКол-во отрицательных: " << count_neg << "\n";
	return 0;
}

// нахождение максимума и минимума, max и min использую в следующей функции:
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

// нахождение кол-ва максимальных и минимальных элементов, корректно работает с {2,3,4,4,4,5,5,2,5}:
int count_max_min(int a[], const int n){ 
	int count_max = 0, count_min = 0, max = 0, min = 0;
	max_min_out_array(a, n, max, min);
	for (int i = 0; i < n; i++){
		if (a[i] == max)
			count_max++;
		else if (a[i] == min)
			count_min++;
	}
	cout << "Максимум: " << max << "\nМинимум: " << min << "\n";
	cout << "Кол-во максимальных: " << count_max << "\nКол-во минимальных: " << count_min << "\n";
	return 0;
}

// положительные элементы заполняются в начало массива b[], отрицателные - в конец:
int interchange(int a[], int b[], const int n){ 
	int pos = 0, neg = 0, i = 0, count_neg = 0, count_pos = 0;

	// 1 вариант с использованием функции np_out_array()
	np_out_array(a, n, count_pos, count_neg); // нахожу кол-во положительных и отрицательных
	for (i = 0; pos < count_pos; i++){
		if (a[i] > 0) {
			b[pos] = a[i];
			pos++;
		}
	}
	for (i = 0; pos < count_pos + count_neg; i++){
		if (a[i] < 0) {
			b[pos] = a[i];
			pos++;
		}
	}

	// 2 вариант без использования функции np_out_array()
	/*
	for (i = 0; i < n; i++){
		if (a[i] > 0) {
			b[pos] = a[i];
			pos++;
		}
		else if (a[i] < 0){
			b[n - neg - 1] = a[i]; // присваиваю отрицательные числа, начиная с конца массива
			neg++;
		}
	}
	*/
	return 0;
}

int interchange2(int a[], const int n){ 
	for (int i = 0; i < n; i++){
		if (a[i] < 0){
			for (int i_end = n/2; i_end < n; i_end++){
				if (a[i_end] > 0){
					a[i_end] = a[i_end] - a[i]; // перестановка. не делаю проверку на максимум, т.к. a[pos2] всегда > a[pos1]
					a[i] = a[i] + a[i_end];
					a[i_end] = -a[i_end] + a[i];
					break;
				}
			}
		}
	}
	return 0;
}

int main(){
	setlocale(LC_ALL, "Russian");
	const int n = 30000;
	int a[n], b[n];
	int max = 0, min = 0, count_pos = 0, count_neg = 0;
	init_array(a, n);
	reverse_out_array(a, n);
	oe_out_array(a, n);
	np_out_array(a, n, count_pos, count_neg);
	max_min_out_array(a, n, max, min);
	count_max_min(a, n);
	interchange(a, b, n);
	interchange2(a, n);
	return 0;
}