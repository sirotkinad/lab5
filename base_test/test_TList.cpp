#include <gtest.h>
#include "TList.h"
//#include "TPolinom.h"
//#include "TPolinom.cpp"



TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> L());
}

TEST(TList, can_initialize_list_with_another_list)
{
	TList<int>* L2=new TList<int>;
	TList<int>* L1(L2);
	EXPECT_EQ(L1==L2, true);
}

TEST(TList, can_compare_two_lists)
{
	TList<int>* L1 = new TList<int>;
	L1->add_end(10);
	L1->add_end(15);
	TList<int>* L2 = new TList<int>;
	L2->add_end(10);
	L2->add_end(10);
	EXPECT_EQ(L1 == L2, false);
}

TEST(TList, can_copy_lists)
{
	TList<int>* L1 = new TList<int>;
	L1->add_end(15);
	TList<int>* L2 = new TList<int>;
	L2->add_end(10);
	L1 = L2;
	EXPECT_EQ(L1 == L2, true);
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
	L->list_sort();
	EXPECT_EQ(L->getHead()->data, 30);
	EXPECT_EQ(L->getHead()->next->data, 20);
	EXPECT_EQ(L->getTail()->data, 10);
}


