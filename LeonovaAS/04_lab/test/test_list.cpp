#include "list.h"
#include <gtest.h>
TEST(TNode, can_create_node)
{
    ASSERT_NO_THROW(TNode<int> Node);
}

TEST(TNode, can_create_node_with_key)
{
    TNode<int> Node(7);
    EXPECT_EQ(Node.key, 7);
}

TEST(TNode, can_assign_nodes)
{
    TNode<int> Node(7);
    TNode<int> Node1(9);
    ASSERT_NO_THROW(Node = Node1);
}

TEST(TNode, assigned_nodes_have_same_keys)
{
    TNode<int> Node(7);
    TNode<int> Node1(9);
    Node1 = Node;
    EXPECT_EQ(Node.key, Node1.key);
}

TEST(TList, can_create_list)
{
    ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_copy_list)
{
    TList<int> list;
    ASSERT_NO_THROW(TList<int> list1(list));
}

TEST(TList, copied_lists_are_equal)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    TList<int> list1(list);
    EXPECT_TRUE(list == list1);
}

TEST(TList, copied_lists_have_different_memory)
{
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    TList<int> list;
    list.push_front(Node);
    TList<int> list1(list);
    list1.push_front(Node1);
    EXPECT_FALSE(list == list1);
}

TEST(TList, can_find_existing_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    EXPECT_NE(list.search(1), nullptr);
}

TEST(TList, cant_find_non_existing_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    EXPECT_EQ(list.search(10), nullptr);
}

TEST(TList, can_push_front)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    ASSERT_NO_THROW(list.push_front(Node));
}

TEST(TList, pushed_front_node_is_present)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    EXPECT_NE(list.search(1), nullptr);
}

TEST(TList, cant_push_back_empty_node)
{
    TList<int> list;
    TNode<int>* node = nullptr;
    ASSERT_ANY_THROW(list.push_back(node));
}

TEST(TList, can_push_back)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    ASSERT_NO_THROW(list.push_back(Node));
}

TEST(TList, pushed_back_node_is_present)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_back(Node);
    EXPECT_NE(list.search(1), nullptr);
}

TEST(TList, can_push_after)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_NO_THROW(list.push_after(Node1, 1));
}

TEST(TList, cant_push_after_non_existind_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.push_after(Node1, 100));
}

TEST(TList, pushed_after_node_is_present)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.push_after(Node1, 1);
    EXPECT_NE(list.search(10), nullptr);
}

TEST(TList, can_push_before)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_NO_THROW(list.push_before(Node1, 1));
}

TEST(TList, cant_push_before_non_existind_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.push_after(Node1, 100));
}

TEST(TList, pushed_before_node_is_present)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list.push_after(Node1, 1);
    EXPECT_NE(list.search(10), nullptr);
}

TEST(TList, can_remove_existing_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    ASSERT_NO_THROW(list.remove(1));
}

TEST(TList, cant_remove_non_existing_key)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    ASSERT_ANY_THROW(list.remove(10));
}

TEST(TList, removed_key_is_not_present)
{
    TList<int> list;
    TNode<int>* Node = new TNode<int>(1);
    list.push_front(Node);
    list.remove(1);
    EXPECT_EQ(list.search(1), nullptr);
}

TEST(TList, can_assign_lists)
{
    TList<int> list;
    TList<int> list1;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list1.push_front(Node1);
    ASSERT_NO_THROW(list = list1);
}

TEST(TList, assigned_lists_are_equal)
{
    TList<int> list;
    TList<int> list1;
    TNode<int>* Node = new TNode<int>(1), * Node1 = new TNode<int>(10);
    list.push_front(Node);
    list1.push_front(Node1);
    list = list1;
    EXPECT_TRUE(list == list1);
}