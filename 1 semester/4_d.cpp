#include <iostream>
#include <clocale>
using std::cin;
using std::cout;

int main(){
	setlocale(LC_ALL, "Russian");
	const int n = 6;
	int a[n][n];
	int num = 1;

	// построчно слева-направо:
	cout << "\nПострочно слева-направо:\n\n";
	for (int h = 0; h < n; h++){	
		for (int w = 0; w < n; w++){
			a[h][w] = num;
			cout << a[h][w] << "\t";
			num++;
		}
		cout << "\n";
	}
	cout << "\nПострочно справа-налево:\n\n";

	// построчно справа-налево:
	num = 1;
	for (int h = 0; h < n; h++){	
		for (int w = n - 1; w >= 0; w--){
			a[h][w] = num;
			num++;
		}
	}								
	for (int h = 0; h < n; h++){	
		for (int w = 0; w < n; w++){
			cout << a[h][w] << "\t";
		}
		cout << "\n";
	}

	// змейка:
	num = 1;
	cout << "\nЗмейкой:\n\n";
	for (int w = 0; w < n; w++){
		if (w % 2 != 0){
			for (int h = n - 1; h >= 0; h--){
				a[h][w] = num;
				num++;
			}
		}
		else{
			for (int h = 0; h < n; h++){
				a[h][w] = num;
				num++;
			}
		}
	}								
	for (int h = 0; h < n; h++){	
		for (int w = 0; w < n; w++){
			cout << a[h][w] << "\t";
		}
		cout << "\n";
	}

	// плуговым письмом:
	num = 1;
	cout << "\nПлуговым письмом:\n\n";
	for (int h = 0; h < n; h++){
		if (h % 2 != 0){
			for (int w = n - 1; w >= 0; w--){
				a[h][w] = num;
				num++;
			}
		}
		else{
			for (int w = 0; w < n; w++){
				a[h][w] = num;
				num++;
			}
		}
	}
	for (int h = 0; h < n; h++){
		for (int w = 0; w < n; w++){
			cout << a[h][w] << "\t";
		}
		cout << "\n";
	}

	// по спирали :(

	cout << "\n";
	return 0;
}