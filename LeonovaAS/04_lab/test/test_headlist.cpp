#include "HeadList.h"
#include <gtest.h>

TEST(HeadList, can_create_list)
{
    ASSERT_NO_THROW(HeadList<int> list);
}

TEST(HeadList, can_copy_list)
{
    HeadList<int> list;
    ASSERT_NO_THROW(HeadList<int> list1(list));
}

TEST(HeadList, copied_lists_are_equal)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    HeadList<int> list1(list);
    EXPECT_TRUE(list == list1);
}

TEST(HeadList, copied_lists_have_different_memory)
{
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    HeadList<int> list;
    list.push_front(Node);
    HeadList<int> list1(list);
    list1.push_front(Node1);
    EXPECT_FALSE(list == list1);
}

TEST(HeadList, can_push_front)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    ASSERT_NO_THROW(list.push_front(Node));
}

TEST(HeadList, pushed_front_node_is_present)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    EXPECT_NE(list.search(1), nullptr);
}

TEST(HeadList, cant_push_back_empty_node)
{
    HeadList<int> list;
    TNode<int>* node = nullptr;
    ASSERT_ANY_THROW(list.push_back(node));
}

TEST(HeadList, can_push_back)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    ASSERT_NO_THROW(list.push_back(Node));
}

TEST(HeadList, pushed_back_node_is_present)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_back(Node);
    EXPECT_NE(list.search(1), nullptr);
}

TEST(HeadList, can_push_after)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_NO_THROW(list.push_after(Node1, 1));
}

TEST(HeadList, cant_push_after_non_existind_key)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.push_after(Node1, 100));
}

TEST(HeadList, pushed_after_node_is_present)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.push_after(Node1, 1);
    EXPECT_NE(list.search(10), nullptr);
}

TEST(HeadList, can_push_before)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_NO_THROW(list.push_before(Node1, 1));
}

TEST(HeadList, cant_push_before_non_existind_key)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.push_after(Node1, 100));
}

TEST(HeadList, pushed_before_node_is_present)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.push_after(Node1, 1);
    EXPECT_NE(list.search(10), nullptr);
}

TEST(HeadList, can_remove_existing_key)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    ASSERT_NO_THROW(list.remove(1));
}

TEST(HeadList, cant_remove_non_existing_key)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.remove(10));
}

TEST(HeadList, removed_key_is_not_present)
{
    HeadList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    list.remove(1);
    EXPECT_EQ(list.search(1), nullptr);
}

TEST(HeadList, can_assign_lists)
{
    HeadList<int> list;
    HeadList<int> list1;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list1.push_front(Node1);
    ASSERT_NO_THROW(list = list1);
}

TEST(HeadList, assigned_lists_are_equal)
{
    HeadList<int> list;
    HeadList<int> list1;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list1.push_front(Node1);
    list = list1;
    EXPECT_TRUE(list == list1);
}