#include <iostream>
#include <clocale>
#include <ctime>
#include <iomanip>
using std::cin;
using std::cout;
int main(){
	// Игра в кости в 3 раунда! После 3 раунда показывает победителя по кол-ву выигранных раундов.
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	char play = 0; int i = 1, round = 1, my_result = 0, opponent_result = 0, player1 = 0, player2 = 0;
	cout << "Начать игру (y/n)?\n";
	cin >> play;
	while ((play == 'y') && (round <= 4)){
		cout << "-----------------\n|   Раунд " << round << "!    |\n-----------------\n";
		while (i <= 4){
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
			if (i == 4){
				cout << "Очки соперника: " << opponent_result;
				if (my_result > opponent_result){ cout << "\n\nВы победили в раунде!\n\n"; player1++; }
				else if (my_result < opponent_result) { cout << "\n\nВы проиграли раунд.\n\n"; player2++; }
				else { cout << "\n\nНичья в раунде.\n\n"; }
				my_result = opponent_result = 0;
			}
			i++; // Счётчик кол-ва бросков
		}
		if (round != 3){ // Если идёт завершающий 3-й раунд - игра окончена
			cout << "Продолжить (y/n)?\n";
			cin >> play;
		}
		else {
			if (player1 > player2){ cout << "\n-----------------\nВы выиграли игру!\n\n"; player1++; }
			else if (player1 < player2) { cout << "\n-----------------\nВы проиграли битву...\n\n"; player2++; }
			else { cout << "\n-----------------\nНичья в игре.\n\n"; }
			player1 = player2 = round = 0;
			cout << "Начать заново (y/n)?\n";
			cin >> play;
		}
		round++;
		i = 1;
	}
	return 0;
}