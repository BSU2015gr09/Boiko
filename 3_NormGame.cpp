#include <iostream>
#include <clocale>
#include <ctime>
using std::cin;
using std::cout;
int main(){
	// Игра в кости, выводит победителя.
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	char play = 0;
	int i = 1, my_result = 0, opponent_result = 0;
	cout << "Начать игру (y/n)?\n";
	cin >> play;
	while ((i <= 4) && (play == 'y')){
		int throw_d = rand() % 6 + 1;
		switch (throw_d){
		case 1:
			cout << "    ---------\n    |       |\n    |   o   |\n    |       |\n    ---------\n";
			break;
		case 2:
			cout << "    ---------\n    | o     |\n    |       |\n    |     o |\n    ---------\n";
			break;
		case 3:
			cout << "    ---------\n    | o     |\n    |   o   |\n    |     o |\n    ---------\n";
			break;
		case 4:
			cout << "    ---------\n    | o   o |\n    |       |\n    | o   o |\n    ---------\n";
			break;
		case 5:
			cout << "    ---------\n    | o   o |\n    |   o   |\n    | o   o |\n    ---------\n";
			break;
		case 6:
			cout << "    ---------\n    | o   o |\n    | o   o |\n    | o   o |\n    ---------\n";
			break;
		}
		if (i <= 2) my_result += throw_d;
		else opponent_result += throw_d;
		if (i == 2){
			cout << "Ваши очки: " << my_result << "\n";
		}
		else if (i == 4){
			cout << "Очки соперника: " << opponent_result;
			if (my_result > opponent_result) { cout << "\n\nВы победили в раунде!\n\n"; }
			else if (my_result < opponent_result) { cout << "\n\nВы проиграли рунд.\n\n"; }
			else if (my_result == opponent_result) { cout << "\n\nНичья.\n\n"; }
			cout << "Продолжить (y/n)?\n";
			cin >> play;
			i = my_result = opponent_result = 0;
		}
		i++;
	}
	return 0;
}