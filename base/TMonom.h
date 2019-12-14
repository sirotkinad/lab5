#ifndef TMONOM_H
#define TMONOM_H
#include <string>
using namespace std;


class TMonom
{
	double coeff; // Коэффициент
	int pow; // степень
public:
	TMonom();// Конструктор
	TMonom(double coeff, int pow);// Конструктор с параметрами
	double getCoeff() const;// возвращение коэффициента
	int getPow() const;// возвращение степени
	void setCoeff(double coeff);//установить коэффициент
	void setPow(int pow);//установить степень
	// Перегрузка операторов сравнения
	friend bool operator<(const TMonom& m1, const TMonom& m2);
	friend bool operator>(const TMonom& m1, const TMonom& m2);
	friend bool operator==(const TMonom& m1, const TMonom& m2);
	// Перегрузка оператора потокового вывода
	friend ostream& operator<<(ostream& os, const TMonom& m);
};

#endif