#include "TMonom.h"
#include <sstream>
#include <string>


TMonom::TMonom()
{
	coeff = 0;
	pow = 0;
}


TMonom::TMonom(double _coeff, int _pow)
{
	coeff = _coeff;
	pow = _pow;
}


double TMonom::getCoeff() const
{
	return coeff;
}


int TMonom::getPow() const
{
	return pow;
}


void TMonom::setCoeff(double _coeff)
{
	coeff = _coeff;
}


void TMonom::setPow(int _pow)
{
	pow = _pow;
}

bool operator<(const TMonom& M1, const TMonom& M2)
{
	return M1.pow < M2.pow;
}


bool operator>(const TMonom& M1, const TMonom& M2)
{
	return M1.pow > M2.pow;
}


bool operator==(const TMonom& M1, const TMonom& M2)
{
	return M1.pow == M2.pow;
}


ostream& operator<<(ostream& os, const TMonom& M)
{
	// Вывод коэффициента
	if (M.getCoeff() != 1)
	{
		if (M.getCoeff() == -1)
		{
			os << "-";
		}
		else
			os << M.getCoeff();
	}

	if (M.getPow() != 0)//(если все степени нулевые, выводится только коэффициент)
	{
		//os << " * ";

		// Получение степеней x, y, z
		int pow = M.getPow();  //MaxIndex=10
		int x = pow / 100;
		int y = (pow / 10) % 10;
		int z = pow % 10;

		// Вывод степеней x, y, z 
		if (x == 1)
			os << "x";
		else if (x > 1)
			os << "x^" << x;

		//if (x > 0 && (y > 0 || z > 0))
			//os << "*";

		if (y == 1)
			os << "y";
		else if (y > 1)
			os << "y^" << y;

		//if (y > 0 && z > 0)
			//os << "*";

		if (z == 1)
			os << "z";
		else if (z > 1)
			os << "z^" << z;
	}

	return os;
}