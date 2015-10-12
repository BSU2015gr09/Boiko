#include <iostream> 
#include <clocale>
using std::cout;
using std::cin;
int main()
{
	setlocale(LC_ALL, "Russian");
	int m = 1, i = 1, x = 0;
	float k = 1, e = 0;
	cout << "Введите x: ";
	cin >> x;
	while (k > 0.00001)
	{
		m = m*i;
		k = pow(x, i - 1) / m;
		e = e + k;
		i++;
	}
	cout << "Результат: " << e << "\n";
	return 0;
}