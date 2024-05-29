#include "linkedlist.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <cstdlib>
#include <gtest/gtest.h>

class DoublyLinkedListTest : public ::testing::Test
{
protected:
  DoublyLinkedList<int> list;

  void SetUp() override
  {
    // Initial setup before each test (if needed)
  }

  void TearDown() override
  {
    // Clean up after each test (if needed)
  }
};

TEST_F(DoublyLinkedListTest, PushBack)
{
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  EXPECT_EQ(list.length(), 3);
  EXPECT_EQ(list.to_string(), "[1]->[2]->[3]");
}

TEST_F(DoublyLinkedListTest, PushFront)
{
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  EXPECT_EQ(list.length(), 3);
  EXPECT_EQ(list.to_string(), "[3]->[2]->[1]");
}

TEST_F(DoublyLinkedListTest, PopFront)
{
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  EXPECT_EQ(list.length(), 3);
  EXPECT_EQ(list.pop_front(), 1);
  EXPECT_EQ(list.length(), 2);
  EXPECT_EQ(list.pop_front(), 2);
  EXPECT_EQ(list.length(), 1);
  EXPECT_EQ(list.pop_front(), 3);
  EXPECT_EQ(list.length(), 0);
  EXPECT_THROW(list.pop_front(), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, PopBack)
{
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  EXPECT_EQ(list.length(), 3);
  EXPECT_EQ(list.pop_back(), 3);
  EXPECT_EQ(list.length(), 2);
  EXPECT_EQ(list.pop_back(), 2);
  EXPECT_EQ(list.length(), 1);
  EXPECT_EQ(list.pop_back(), 1);
  EXPECT_EQ(list.length(), 0);
  EXPECT_THROW(list.pop_back(), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, Remove)
{
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.remove(2);
  EXPECT_EQ(list.length(), 2);
  EXPECT_EQ(list.to_string(), "[1]->[3]");
  EXPECT_THROW(list.remove(4), std::out_of_range);
  list.remove(1);
  list.remove(3);
  EXPECT_EQ(list.length(), 0);
  EXPECT_THROW(list.remove(1), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, Find)
{
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  EXPECT_TRUE(list.find(1));
  EXPECT_TRUE(list.find(2));
  EXPECT_TRUE(list.find(3));
  EXPECT_FALSE(list.find(4));
}

TEST_F(DoublyLinkedListTest, Clear)
{
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.clear();
  EXPECT_EQ(list.length(), 0);
  EXPECT_TRUE(list.empty());
  EXPECT_EQ(list.to_string(), "[]");
}

TEST_F(DoublyLinkedListTest, Empty)
{
  EXPECT_TRUE(list.empty());
  list.push_back(1);
  EXPECT_FALSE(list.empty());
  list.pop_back();
  EXPECT_TRUE(list.empty());
}

TEST_F(DoublyLinkedListTest, Length)
{
  EXPECT_EQ(list.length(), 0);
  list.push_back(1);
  EXPECT_EQ(list.length(), 1);
  list.push_back(2);
  EXPECT_EQ(list.length(), 2);
  list.pop_front();
  EXPECT_EQ(list.length(), 1);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}