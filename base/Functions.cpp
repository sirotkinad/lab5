#include "Functions.h"
#include <sstream>


bool Mult_overflow(int a, int b)
{
	if (a < 0 || a > 999)
		throw ("�������� ���������� a ������ ���� �� 0 �� 999");

	if (b < 0 || b > 999)
		throw ("�������� ���������� b ������ ���� �� 0 �� 999");

	if (a > 9 && a < 99)
		b = b % 100;
	else if (a < 9)
		b = b % 10;

	while (a > 0)
	{
		if (a % 10 + b % 10 > 9) // ���� ������������, ����� �� �������
			return false;
		a = a / 10;
		b = b / 10;
	}
	return true;
}


vector<double> splitAndRemoveNullCoeffs(const string& s, char delim)
{
	stringstream ss(s); // ����� �����
	string item; // �������� ������������ ��������
	vector<double> elems; // �������������� ������

	int i = 1;
	while (getline(ss, item, delim)) // ���� ������ �� ���������
	{
		double a = atof(item.c_str()); // ������� ������ � ������������ �����
		if (a || i % 2 == 0)
		{
			elems.push_back(a);
			i++;
		}
		else
		{
			if (!getline(ss, item, delim))
				break;
		}
	}
	// ���� ������ �������� �� ����� ������ ��������, �� ������ ������� ��������
	if (elems.size() < 2)
	{
		elems.clear();
		elems.push_back(0);
		elems.push_back(0);
	}
	return elems;
}