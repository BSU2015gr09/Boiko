#include <iostream>
using std::cout;
int xor_random(int x){ // Генератора псевдослучайных чисел с помощью XOR
	long int tmp = 0;
	tmp ^= x << 13;
	tmp ^= tmp >> 15;
	x ^= tmp << 5;
	return x;
}
int main(){
	return 0;
}
