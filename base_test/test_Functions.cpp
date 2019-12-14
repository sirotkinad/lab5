#include <gtest.h>
#include "Functions.h"
#include "Functions.cpp"

TEST(Functions, check_mult_overflow_1)
{
	ASSERT_ANY_THROW(Mult_overflow(1000, 1000));
	ASSERT_ANY_THROW(Mult_overflow(-47, 900));
}

TEST(Functions, check_mult_overflow_2)
{
	EXPECT_EQ(Mult_overflow(211, 310), true);
	EXPECT_EQ(Mult_overflow(44, 220), true);
}

TEST(Functions, check_split_and_remove_null_coeffs)
{
	EXPECT_EQ(splitAndRemoveNullCoeffs("w", ' ')[0], 0);
	auto v = splitAndRemoveNullCoeffs("1;;3;4;;", ';');
	EXPECT_EQ(v.size(),4);
	EXPECT_EQ(v[0],1);
	EXPECT_EQ(v[1],0);
	EXPECT_EQ(v[2],3);
	EXPECT_EQ(v[3],4);
}