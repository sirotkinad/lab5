#include <string>
#include <vector>
using namespace std;

// Проверка, могут ли быть числа a и b умножены без переполнения
bool Mult_overflow(int a, int b);

// Извлечение из строки s ненулевых значений коэффициентов (до символа delim)
vector<double> splitAndRemoveNullCoeffs(const string& s, char delim);
/*#include <gtest.h>
#include "TList.h"



TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> L());
}


TEST(TList, can_get_head)
{
	TList<int>* L = new TList<int>;
	L->add_end(10);
	EXPECT_EQ(L->getHead()->data, 10);
	L->add_end(20);
	EXPECT_EQ(L->getHead()->data, 10);
}

TEST(TList, can_get_tail)
{
	TList<int>* L = new TList<int>;
	L->add_end(10);
	EXPECT_EQ(L->getTail()->data, 10);
	L->add_end(20);
	EXPECT_EQ(L->getTail()->data, 20);
}

TEST(TList, cant_get_head_from_empty_list)
{
	TList<int>* L = new TList<int>;
	ASSERT_ANY_THROW(L->getHead()->data);
}

TEST(TList, can_add_element_in_the_end_of_list)
{
	TList<int>* L = new TList<int>;
	ASSERT_NO_THROW(L->add_end(10));
	EXPECT_EQ(L->getTail()->data, 10);
}

TEST(TList, can_sort_list)
{
	TList<int>* L = new TList<int>;
	L->add_end(10);
	L->add_end(20);
	L->add_end(30);
	EXPECT_EQ(L->getHead()->data, 30);
	EXPECT_EQ(L->getHead()->next->data, 20);
	EXPECT_EQ(L->getTail()->data, 10);
}


TEST(Queue, queues_have_different_memory)
{
	TList<int> L1(), L2();
	EXPECT_NE(&L1, &L2);
}*/
/*#include <gtest.h>

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}*/


/*#include <gtest.h>
#include "TMonom.h"
#include "TMonom.cpp"


TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom M());
}

TEST(TMonom, can_create_monom_with_coef_and_deg)
{
	ASSERT_NO_THROW(TMonom M(5, 3));
}

TEST(TMonom, cant_create_monom_with_too_big_deg)
{
	ASSERT_ANY_THROW(TMonom M(5, 1500));
}

TEST(TMonom, cant_create_monom_with_negative_deg)
{
	ASSERT_ANY_THROW(TMonom M(5, -5));
}



TEST(TMonom, can_get_coeffecient)
{
	TMonom M(2.5, 200);
	EXPECT_EQ(M.getCoeff(), 2.5);
}

TEST(TMonom, can_get_pow)
{
	TMonom M = TMonom(2.5, 200);
	EXPECT_EQ(M.getPow(), 200);
}

TEST(TMonom, can_set_coeffecient)
{
	TMonom M(2, 200);
	EXPECT_EQ(M.getCoeff(), 2);
	M.setCoeff(5);
	EXPECT_EQ(M.getCoeff(), 5);
}

TEST(TMonom, can_set_pow)
{
	TMonom M(2, 200);
	EXPECT_EQ(M.getPow(), 200);
	M.setPow(511);
	EXPECT_EQ(M.getPow(), 511);
}

TEST(TMonom, can_compare_monoms_1)
{
	TMonom M1(2, 211);
	TMonom M2(5, 211);
	EXPECT_EQ(M1 < M2, true);
	EXPECT_EQ(M2 > M1, true);
}

TEST(TMonom, can_compare_monoms_2)
{
	TMonom M1(2, 321);
	TMonom M2(2, 421);
	EXPECT_EQ(M1 < M2, true);
	EXPECT_EQ(M2 > M1, true);
}

TEST(TMonom, can_compare_monoms_3)
{
	TMonom M1(2, 321);
	TMonom M2(2, 321);
	EXPECT_EQ(M1 == M2, true);
}

TEST(TMonom, monoms_have_different_memory)
{
	TMonom M1(5, 555), M2(6, 666);
	EXPECT_NE(&M1, &M2);
}*/




