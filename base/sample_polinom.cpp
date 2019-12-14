#include "TPolinom.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	cout << "������ ����� ��������:" << endl;;
	cout << "2 * x ^ 3 * y ^ 2 * z ������ ����� 2;321" << endl;;
	cout << "x*y*z + y*z ^ 5 ������ ����� 1;111; 1;15" << endl;
	cout << "������ ����� - �����������, ����� ����� � �������, ����� ���������� - ����� �� 0 �� 999" << endl;;
	cout << "�����������, ������ ������� ������� �� �����" << endl;;
	cout << "105 = x ^ 1 y ^ 0 z ^ 5" << endl;
	cout << "8 = z ^ 8" << endl;
	cout << "60 = y ^ 6" << endl;
	cout << "200 = x ^ 2" << endl;
	
	cout << "������� ������� P: ";
	string s1;
	cin >> s1;
	TPolinom P = TPolinom(s1);
	cout << "������� P: " << P << endl;
	cout << "������� ������� Q: ";
	string s2;
	cin >> s2;
	TPolinom Q = TPolinom(s2);
	cout << "������� Q: " << Q << endl;
    cout << "��������� ���������: " << "P-Q = " << P - Q << endl;
	cout << "�������� ���������: " << "P+Q = " << P + Q << endl;
	cout << "������������ ���������: " << "P*Q = " << P * Q << endl;
	cout << "��������� �� ���������: " << endl;
	cout << "������� ���������: " << endl;
	double c;
	cin >> c;
	cout << "P*" << c << " = " << P * c << endl;
	cout << "Q*" << c << " = " << Q * c << endl;
	cout << "������� ����� ��� ���������� �������� ��������: " << endl;
	double x, y, z;
	cin >> x >> y >> z;
	cout << "P(" << x << "," << y << "," << z << ") = " << P.Value(x, y, z) << endl;
	cout << "Q(" << x << "," << y << "," << z << ") = " << Q.Value(x, y, z) << endl;
	cout << "������������ ���������: " << "P=Q" << endl;
	P = Q;
	cout << "P = " << P <<"; Q= "<<Q<< endl;
}

