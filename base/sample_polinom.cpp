#include "TPolinom.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	cout << "Пример ввода полинома:" << endl;;
	cout << "2 * x ^ 3 * y ^ 2 * z ввести нужно 2;321" << endl;;
	cout << "x*y*z + y*z ^ 5 ввести нужно 1;111; 1;15" << endl;
	cout << "Первое число - коэффициент, затем точка с запятой, после показатели - числа от 0 до 999" << endl;;
	cout << "Коэффициент, равный единице вводить не нужно" << endl;;
	cout << "105 = x ^ 1 y ^ 0 z ^ 5" << endl;
	cout << "8 = z ^ 8" << endl;
	cout << "60 = y ^ 6" << endl;
	cout << "200 = x ^ 2" << endl;
	
	cout << "Введите полином P: ";
	string s1;
	cin >> s1;
	TPolinom P = TPolinom(s1);
	cout << "Полином P: " << P << endl;
	cout << "Введите полином Q: ";
	string s2;
	cin >> s2;
	TPolinom Q = TPolinom(s2);
	cout << "Полином Q: " << Q << endl;
    cout << "Вычитание полиномов: " << "P-Q = " << P - Q << endl;
	cout << "Сложение полиномов: " << "P+Q = " << P + Q << endl;
	cout << "Произведение полиномов: " << "P*Q = " << P * Q << endl;
	cout << "Умножение на константу: " << endl;
	cout << "Введите константу: " << endl;
	double c;
	cin >> c;
	cout << "P*" << c << " = " << P * c << endl;
	cout << "Q*" << c << " = " << Q * c << endl;
	cout << "Введите точку для вычисления значения полинома: " << endl;
	double x, y, z;
	cin >> x >> y >> z;
	cout << "P(" << x << "," << y << "," << z << ") = " << P.Value(x, y, z) << endl;
	cout << "Q(" << x << "," << y << "," << z << ") = " << Q.Value(x, y, z) << endl;
	cout << "Присваивание полиномов: " << "P=Q" << endl;
	P = Q;
	cout << "P = " << P <<"; Q= "<<Q<< endl;
}

