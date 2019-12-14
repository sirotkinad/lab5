#include <gtest.h>
#include "TPolinom.h"


TEST(TPolinom, can_create_polinom_1)
{
	ASSERT_NO_THROW(TPolinom P());
}

TEST(TPolinom, can_create_polinom_2)
{
	ASSERT_NO_THROW(TPolinom P("1;123"));
}

TEST(TPolinom, check_unit_like_terms)
{
	TPolinom p("5;111;-8;111");
	EXPECT_EQ(p.Polinom_to_string(), "-3xyz");
}


TEST(TPolinom, can_count_value_point)
{
	TPolinom P1("2;123"), P2("1;111");
	EXPECT_EQ(P1.Value(1, 1, 2), 16);
	EXPECT_EQ(P2.Value(0, 0, 0), 0);
}

TEST(TPolinom, can_sum_polinoms)
{
	TPolinom p1("1;111"), p2("5;111");
	TPolinom sum1 = p1 + p2;
	EXPECT_EQ(sum1.Polinom_to_string(), "6xyz");
}

TEST(TPolinom, can_sub_polinoms)
{
	TPolinom p1("1;111"), p2("5;111"),p3("1;111;4;123");
	TPolinom sub1 = p1 - p2;
	EXPECT_EQ(sub1.Polinom_to_string(), "-4xyz");
	TPolinom sub2 = p1 - p3;
	EXPECT_EQ(sub2.Polinom_to_string(), "-4xy^2z^3");
}

TEST(TPolinom, can_mult_polinoms)
{
	TPolinom p1("1;111"), p2("5;111");
	TPolinom mult1 = p1*p2;
	EXPECT_EQ(mult1.Polinom_to_string(), "5x^2y^2z^2");
}

TEST(TPolinom, can_mult_polinom_on_constant)
{
	TPolinom p1("1;111");
	double c=5;
	TPolinom mult1 = p1*c;
	EXPECT_EQ(mult1.Polinom_to_string(), "5xyz");
}

