#ifndef TPOLINOM_H
#define TPOLINOM_H
#include "TList.h"
#include "TMonom.h"
#include <string>
using namespace std;

class TPolinom
{

	TList<TMonom>* monom; // —писок мономов
	void  right_order(); // упор€дочивание полинома
	void unit_same_terms(); // ѕриведение подобных слагаемых

public:
	TPolinom();//  онструктор по умолчанию
	TPolinom(string s);//  онструктор (параметр - строка)
	TList<TMonom>* getMonom()const;//получить списка мономов
	void addMonom(const TMonom& m);// ƒобавить моном
	string Polinom_to_string(); //полином в виде строки
	double Value(double x, double y, double z); //значение полинома в точке
	//bool operator==(const TPolinom& p); //равенство полиномов
	TPolinom& operator=(const TPolinom& p);//присваивание
	// ѕерегрузка арифметических операций
	friend TPolinom operator+(const TPolinom& p1, const TPolinom& p2);
	friend TPolinom operator-(const TPolinom& p1, const TPolinom& p2);
	friend TPolinom operator*(const TPolinom& p1, const TPolinom& p2);
	friend TPolinom operator*(const TPolinom& p, double c);
	// ѕерегрузка оператора потокового вывода
	friend ostream& operator<<(ostream& os, const TPolinom& p);
};

#endif
