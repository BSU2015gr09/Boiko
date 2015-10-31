#include <iostream>
using std::cout;
int xor_random(long int x){ // Генератора псевдослучайных чисел с помощью XOR
	long int tmp = 0;
	tmp ^= x << 13;
	tmp ^= tmp >> 15;
	x ^= tmp << 5;
	return x;
}
int main(){
	cout << xor_random(5) % 100 - 50 << "\n"; // в промежутке от -50 до 50
	return 0;
}