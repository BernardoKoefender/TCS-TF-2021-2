#include "../sort.h"
#include "../array.c"
#include "unity.h"
#include "unity_fixture.h"

#define SELECTION  0
#define INSERTION  1
#define SHELL      2
#define QUICK      3
#define HEAP       4
#define MERGE      5

TEST_GROUP(Sort);

TEST_SETUP(Sort)
{
}

TEST_TEAR_DOWN(Sort)
{
}

TEST(Sort, TestCase_0)
{
  int i;
  char error_msg[64];

  // Run this test for all the 6 algorithms
  for(i=0; i<=5; i++)
  {
    int size = 1;
    int input_array[1] = {5};
    int output_array[1] = {5};
    sprintf(error_msg, "TestCase_0 failed at iteration %d.",i);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, size, i), size, error_msg);
  }
}

TEST(Sort, TestCase_1)
{
  char error_msg[64];

  int size = 4;
  int input_array[4] = {5,2,6,1};
  int output_array[4] = {5,2,6,1};
  sprintf(error_msg, "TestCase_1 failed.");
  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, size, -1), size, error_msg);
}

TEST(Sort, TestCase_2)
{
  char error_msg[64];
  
  int size = 4;
  int input_array[4] = {3,7,1,1};
  int output_array[4] = {3,7,1,1};
  sprintf(error_msg, "Testcase_2 failed.");
  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, size, 6), size, error_msg);
}

TEST(Sort, TestCase_3)
{
  int i;
  char error_msg[64];

  // Run this test for all the 6 algorithms
  for(i=0; i<=5; i++)
  {
    int size = 6;
    int input_array[6] = {1,4,4,7,10,13};
    int output_array[6] = {1,4,4,7,10,13};
    sprintf(error_msg, "TestCase_3 failed at iteration %d.",i);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, size, i), size, error_msg);
  }
}

TEST(Sort, TestCase_4)
{
  int i;
  char error_msg[64];

  // Run this test for all the 6 algorithms
  for(i=0; i<=5; i++)
  {
    int size = 8;
    int input_array[8] = {3,3,3,3,3,2,3,3};
    int output_array[8] = {2,3,3,3,3,3,3,3};
    sprintf(error_msg, "TestCase_4 failed at iteration %d.",i);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, size, i), size, error_msg);
  }
}

TEST(Sort, TestCase_5)
{
  int i;
  char error_msg[64];

  // Run this test for all the 6 algorithms
  for(i=0; i<=5; i++)
  {
    int size = 4;
    int input_array[5] = {5,4,3,2,1};
    int output_array[4] = {2,3,4,5};
    sprintf(error_msg, "TestCase_5 failed at iteration %d.",i);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array,4, i), size, error_msg);
  }
}

TEST(Sort, TestCase_6)
{
  int i;
  char error_msg[64];

  // Run this test for all the 6 algorithms
  for(i=0; i<=5; i++)
  {
    int size = 5;
    int input_array[5] = {'a','4','b','3','1'};
    int output_array[5] = {'1','3','4','a','b'};
    sprintf(error_msg, "TestCase_6 failed at iteration %d.",i);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, size, i), size, error_msg);
  }
}

TEST(Sort, TestCase_7)
{
  int i;
  char error_msg[64];

  // Run this test for all the 6 algorithms
  for(i=0; i<=5; i++)
  {
    int size = 8;
    int input_array[8] = {0,-5,3,-60,60,13,5,-1};
    int output_array[8] = {-60,-5,-1,0,3,5,13,60};
    sprintf(error_msg, "TestCase_7 failed at iteration %d.",i);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, size, i), size, error_msg);
  }
}