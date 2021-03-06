#include <iostream>
#include <clocale>
#include <ctime>
using namespace std;
int init_a = false;

// 65. *(8-9 баллов)\nЗадача: В массиве А(N) найти наименьшее количество элементов, которые надо удалить из данного массива, чтобы осталась возрастающая последовательность.

int arr_init(int *a, int *n, int *b){
	int rn = 0;
	for (int i = 0; i < *n; i++){
		rn = rand() % 150;
		*(a + i) = rn;
		*(b + i) = rn;
	}
	init_a = true;
	return 1;
}

int arr_out(int *a, int *n){
	for (int i = 0; i < *n; i++){
		cout << *(a + i) << " ";
	}
	cout << endl;
	return 1;
}

int restore(int *a, int *b, int *n){
	for (int i = 0; i < *n; i++){
		*(a + i) = *(b + i);
	}
	return 1;
}

int incr_a(int *a, int *n, int *b){
	int count = 0, min = 0, tmp = 0, m = *n, t = 0;
	for (t = 0; t < m; t++){
		count = 0;
		for (int i = t; i <= *n - 1; i++){

			if (*(a + i) > *(a + i + 1)){
				for (int j = i+1; j < *n - 1; j++){
					*(a + j) = *(a + j + 1);
				}
				arr_out(a, n);
				(*n)--;
				i--;
				count++;
			}
		}
		count += t;
		if (!t) min = count; // присваиваем min значение первого счётчика
		*n = m;
		
		if (count < min)
			min = count;
		restore(a, b, n);
	}
	
	cout << "Нужно удалить минимум " << min << " элементов, чтобы последовательность стала возрастающей\n";

	return 1;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int *n = new int(0);

	int cmd = -1;
	char hr[12] = "---------\n";
	cout << "65. *(8-9 баллов)\nЗадача: В массиве А(N) найти наименьшее количество элементов, которые надо удалить из данного массива, чтобы осталась возрастающая последовательность.\n\n";
	cout << "Введите размер создаваемого массива: ";
	cin >> *n;
	int *a = new int[*n], *b = new int[*n];
	while (cmd){
		cout << hr;
		cout << "0 - выход\n";
		if (!init_a) cout << "1 - построить массив из " << *n << " элементов\n";
		if (init_a) cout << "2 - удалить элементы согласно задачи\n";
		cout << hr;
		cout << "Команда: ";
		cin >> cmd;
		cout << hr;

		switch (cmd) {
		case 0: return 1;
		case 1: arr_init(a, n, b); arr_out(a, n); break;
		case 2: incr_a(a, n, b); break;
		}

	}

	cout << endl;
	system("pause");
}