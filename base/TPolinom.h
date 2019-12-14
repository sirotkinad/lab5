#ifndef TPOLINOM_H
#define TPOLINOM_H
#include "TList.h"
#include "TMonom.h"
#include <string>
using namespace std;

class TPolinom
{

	TList<TMonom>* monom; // ������ �������
	void  right_order(); // �������������� ��������
	void unit_same_terms(); // ���������� �������� ���������

public:
	TPolinom();// ����������� �� ���������
	TPolinom(string s);// ����������� (�������� - ������)
	TList<TMonom>* getMonom()const;//�������� ������ �������
	void addMonom(const TMonom& m);// �������� �����
	string Polinom_to_string(); //������� � ���� ������
	double Value(double x, double y, double z); //�������� �������� � �����
	//bool operator==(const TPolinom& p); //��������� ���������
	TPolinom& operator=(const TPolinom& p);//������������
	// ���������� �������������� ��������
	friend TPolinom operator+(const TPolinom& p1, const TPolinom& p2);
	friend TPolinom operator-(const TPolinom& p1, const TPolinom& p2);
	friend TPolinom operator*(const TPolinom& p1, const TPolinom& p2);
	friend TPolinom operator*(const TPolinom& p, double c);
	// ���������� ��������� ���������� ������
	friend ostream& operator<<(ostream& os, const TPolinom& p);
};

#endif
