#include "TPolinom.h"
#include "Functions.h"
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define EPS 1E-15


void TPolinom::right_order()
{
	monom->list_sort();
}


void TPolinom::unit_same_terms()
{
	right_order();
	Node<TMonom>* p1 = monom->getHead();
	if (p1 != nullptr)
		while (p1->next != nullptr)
		{
			Node<TMonom>* p2 = p1->next;
			if (p1->data.getPow() == p2->data.getPow()) // Если степени  равны
			{
				p1->data.setCoeff(p1->data.getCoeff() + p2->data.getCoeff());// Коэффициент 1го - сумма коэффициентов
				// Удаление 2го 
				if (p2 == this->getMonom()->getTail())
				{
					p2 = p2->prev;
					p2->next = nullptr;
				}
				else
				{
					p2->prev->next = p2->next;
					p2->next->prev = p2->prev;
				}
			}
			p1 = p2;
		}

	p1 = monom->getHead();
	// Удаление возникших нулей 
	while (p1 != nullptr)
	{
		if (abs(p1->data.getCoeff()) < EPS)
		{
			if (p1 == this->getMonom()->getHead())
			{
				if (p1->next == nullptr)
					break;
				p1 = p1->next;
				p1->prev = nullptr;
			}
			else if (p1 == this->getMonom()->getTail())
			{
				p1 = p1->prev;
				p1->next = nullptr;
			}
			else
			{
				p1->prev->next = p1->next;
				p1->next->prev = p1->prev;
			}
		}
		p1 = p1->next;
	}
}


TPolinom::TPolinom()
{
	monom = new TList<TMonom>();
}



TPolinom::TPolinom(string s)
{
	monom = new TList<TMonom>();
	auto v = splitAndRemoveNullCoeffs(s, ';');
	if (v.size() % 2 == 1)
	{
		throw "ERROR";
	}
	else
		for (int i = 0; i < v.size(); i += 2)
		{
			double j = 0;
			double tmp = modf(v[i + 1], &j); //целая часть
			if (j < 0 || j > 999) //значение нужно 0-999
				throw "error";
			this->addMonom(TMonom(v[i], (int)j));
		}
	unit_same_terms();
}


TList<TMonom>* TPolinom::getMonom() const
{
	return monom;
}


void TPolinom::addMonom(const TMonom& m)
{
	monom->add_end(m);
}

double TPolinom::Value(double a, double b, double c)
{
	double value = 0;
	Node<TMonom>* p = this->getMonom()->getHead();
	while (p != nullptr)
	{
		double tmp = 1;
		int deg = (p->data).getPow();
		int z = deg % 10;
		deg = deg / 10;
		int y = deg % 10;
		deg = deg / 10;
		int x = deg;
		tmp *= (p->data).getCoeff();
		tmp *= pow(a, x);
		tmp *= pow(b, y);
		tmp *= pow(c, z);
		value += tmp;
		p = p->next;
	}
	return value;
}

/*bool TPolinom::operator==(const TPolinom& p)
{
	return (monom == p.monom);
}*/


TPolinom& TPolinom::operator=(const TPolinom& p)
{
	monom = p.monom;
	return (*this);
}


TPolinom operator+(const TPolinom& P1, const TPolinom& P2)
{
	Node<TMonom>* M1 = P1.getMonom()->getHead();
	Node<TMonom>* M2 = P2.getMonom()->getHead();
	TPolinom Sum;

	//проходим по полиномам
	while (M1 != nullptr && M2 != nullptr)
	{
		if (M1->data > M2->data) // Если степень 1го монома больше
		{
			Sum.addMonom(M1->data); //добавляем моном
			M1 = M1->next; // Движение по 1му многочлену
		}
		else if (M1->data < M2->data) // Если степень 2го монома больше
		{
			Sum.addMonom(M2->data); //добавляем моном
			M2 = M2->next; // Движение по 2му многочлену
		}
		else
		{
			double cCoeff = M1->data.getCoeff() + M2->data.getCoeff();
			if (cCoeff != 0) // Если получившийся коэффициент не ноль
				Sum.addMonom(TMonom(cCoeff, M1->data.getPow())); // Добавляем моном
			M1 = M1->next;
			M2 = M2->next;
		}
	}
	//оставшиеся мономы
	while (M1 != nullptr)
	{
		Sum.addMonom(M1->data);
		M1 = M1->next;
	}

	while (M2 != nullptr)
	{
		Sum.addMonom(M2->data);
		M2 = M2->next;
	}
	Sum.unit_same_terms();
	return Sum;
}


TPolinom operator-(const TPolinom& P1, const TPolinom& P2)
{
	TPolinom P3 = P2 * -1.0;
	TPolinom Sub = P1 + P3;
	Sub.unit_same_terms();
	return Sub;
}

TPolinom operator*(const TPolinom& P1, const TPolinom& P2)
{
	Node<TMonom>* q = P1.getMonom()->getHead();
	TPolinom Mult;
	while (q != nullptr)
	{
		Node<TMonom>* f = P2.getMonom()->getHead();
		while (f != nullptr)
		{
			// Если переполнение
			if (!Mult_overflow(q->data.getPow(), f->data.getPow()))
				throw "переполнение!";
			Mult.addMonom(TMonom(q->data.getCoeff() * f->data.getCoeff(),
				q->data.getPow() + f->data.getPow()));
			f = f->next;
		}
		q = q->next;
	}
	Mult.unit_same_terms();
	return Mult;
}


TPolinom operator*(const TPolinom& p, double c)
{
	Node<TMonom>* q = p.getMonom()->getHead();
	TPolinom res;
	if (c != 0)
	{
		while (q != nullptr)
		{
			res.addMonom(TMonom(q->data.getCoeff() * c, q->data.getPow()));
			q = q->next;
		}
		res.unit_same_terms();
		return res;
	}
	else
		return TPolinom();
}



ostream& operator<<(ostream& os, const TPolinom& P)
{
	Node<TMonom>* q = P.getMonom()->getHead();
	if (q != nullptr)
		while (q->next != nullptr) // Пока следующий элемент не конец списка
		{
			os << q->data << " + "; // Записать моном, разделяем +
			q = q->next;
		}
	else
		os << 0; //пустой многочлен
	if (q != nullptr) {// Записать моном хвоста
		os << q->data;
	}
	return os;
}

string TPolinom::Polinom_to_string()
{
	string result;// Записать в строковый поток
	stringstream stream(result);
	stream << *this;
	return stream.str();// Получить строку из потока
}

