#include "vector.h"
#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>

#define FILL_VECTOR(N)        \
  for (int i = 0; i < N; i++) \
    v.push_back(i + 1);

class VectorTest : public ::testing::Test
{
protected:
  Vector<int> v;

  void SetUp() override
  {
    // Initial setup before each test (if needed)
  }

  void TearDown() override
  {
    // Clean up after each test (if needed)
  }
};

TEST_F(VectorTest, PushBack)
{
  FILL_VECTOR(3);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.to_string(), "[1, 2, 3]");
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);
  EXPECT_EQ(v.size(), 6);
  EXPECT_EQ(v.to_string(), "[1, 2, 3, 4, 5, 6]");
}

TEST_F(VectorTest, PopBack)
{
  FILL_VECTOR(3);
  v.pop_back();
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.to_string(), "[1, 2]");
  v.pop_back();
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.to_string(), "[1]");
  v.pop_back();
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.to_string(), "[]");
  EXPECT_EQ(v.empty(), 1);
}

TEST_F(VectorTest, Insert)
{
  FILL_VECTOR(5);
  v.insert(0, 0);
  v.insert(6, 6);
  v.insert(2, -3);
  EXPECT_EQ(v.size(), 8);
  EXPECT_EQ(v.to_string(), "[0, 1, -3, 2, 3, 4, 5, 6]");
}

TEST_F(VectorTest, Access)
{
  FILL_VECTOR(100);
  for (int i = 0; i < 100; ++i)
  {
    EXPECT_EQ(v.at(i), i + 1);
    EXPECT_EQ(v[i], i + 1);
  }
  EXPECT_EQ(v.front(), 1);
  EXPECT_EQ(v.back(), 100);
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}