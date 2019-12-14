#ifndef TMONOM_H
#define TMONOM_H
#include <string>
using namespace std;


class TMonom
{
	double coeff; // �����������
	int pow; // �������
public:
	TMonom();// �����������
	TMonom(double coeff, int pow);// ����������� � �����������
	double getCoeff() const;// ����������� ������������
	int getPow() const;// ����������� �������
	void setCoeff(double coeff);//���������� �����������
	void setPow(int pow);//���������� �������
	// ���������� ���������� ���������
	friend bool operator<(const TMonom& m1, const TMonom& m2);
	friend bool operator>(const TMonom& m1, const TMonom& m2);
	friend bool operator==(const TMonom& m1, const TMonom& m2);
	// ���������� ��������� ���������� ������
	friend ostream& operator<<(ostream& os, const TMonom& m);
};

#endif