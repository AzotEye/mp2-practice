#include "RingHeadList.h"
#include <gtest.h>

TEST(RingHeadList, can_create_list)
{
    ASSERT_NO_THROW(RingHeadList<int> list);
}

TEST(RingHeadList, can_copy_list)
{
    RingHeadList<int> list;
    ASSERT_NO_THROW(RingHeadList<int> list1(list));
}

TEST(RingHeadList, copied_lists_are_equal)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    RingHeadList<int> list1(list);
    EXPECT_TRUE(list == list1);
}

TEST(RingHeadList, copied_lists_have_different_memory)
{
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    RingHeadList<int> list;
    list.push_front(Node);
    RingHeadList<int> list1(list);
    list1.push_front(Node1);
    EXPECT_FALSE(list == list1);
}

TEST(RingHeadList, can_find_existing_key)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    EXPECT_NE(list.search(1), nullptr);
}

TEST(RingHeadList, cant_find_non_existing_key)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    EXPECT_EQ(list.search(10), nullptr);
}

TEST(RingHeadList, can_push_front)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    ASSERT_NO_THROW(list.push_front(Node));
}

TEST(RingHeadList, pushed_front_node_is_present)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    EXPECT_NE(list.search(1), nullptr);
}

TEST(RingHeadList, cant_push_back_empty_node)
{
    RingHeadList<int> list;
    TNode<int>* node = nullptr;
    ASSERT_ANY_THROW(list.push_back(node));
}

TEST(RingHeadList, can_push_back)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    ASSERT_NO_THROW(list.push_back(Node));
}

TEST(RingHeadList, pushed_back_node_is_present)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_back(Node);
    EXPECT_NE(list.search(1), nullptr);
}

TEST(RingHeadList, can_push_after)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_NO_THROW(list.push_after(Node1, 1));
}

TEST(RingHeadList, cant_push_after_non_existind_key)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.push_after(Node1, 100));
}

TEST(RingHeadList, pushed_after_node_is_present)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.push_after(Node1, 1);
    EXPECT_NE(list.search(10), nullptr);
}

TEST(RingHeadList, can_push_before)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_NO_THROW(list.push_before(Node1, 1));
}

TEST(RingHeadList, cant_push_before_non_existind_key)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.push_after(Node1, 100));
}

TEST(RingHeadList, pushed_before_node_is_present)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.push_after(Node1, 1);
    EXPECT_NE(list.search(10), nullptr);
}

TEST(RingHeadList, can_remove_existing_key)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    ASSERT_NO_THROW(list.remove(1));
}

TEST(RingHeadList, cant_remove_non_existing_key)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.remove(10));
}

TEST(RingHeadList, removed_key_is_not_present)
{
    RingHeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    list.remove(1);
    EXPECT_EQ(list.search(1), nullptr);
}

TEST(RingHeadList, can_assign_lists)
{
    RingHeadList<int> list;
    RingHeadList<int> list1;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list1.push_front(Node1);
    ASSERT_NO_THROW(list = list1);
}

TEST(RingHeadList, assigned_lists_are_equal)
{
    RingHeadList<int> list;
    RingHeadList<int> list1;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list1.push_front(Node1);
    list = list1;
    EXPECT_TRUE(list == list1);
}