#include <gtest.h>
#include "TMonom.h"


TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom M());
}

TEST(TMonom, can_create_monom_with_coef_and_deg)
{
	ASSERT_NO_THROW(TMonom M(5, 3));
}



TEST(TMonom, can_get_coeffecient)
{
	TMonom M = TMonom(1, 2);
	EXPECT_EQ(M.getCoeff(), 1);
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
	TMonom M1(2, 321);
	TMonom M2(2, 421);
	EXPECT_EQ(M1 < M2, true);
	EXPECT_EQ(M2 > M1, true);
}

TEST(TMonom, can_compare_monoms_2)
{
	TMonom M1(2, 321);
	TMonom M2(2, 321);
	EXPECT_EQ(M1 == M2, true);
}

TEST(TMonom, monoms_have_different_memory)
{
	TMonom M1(5, 555), M2(6, 666);
	EXPECT_NE(&M1, &M2);
}