#include "../sort.h"
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

TEST(Sort, SelectionSort)
{
  //void selection_sort(int *vet, int tam);
  int input_array[3]    = {2,1,3};
  int output_array[3] = {1,2,3};

  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, 3, SELECTION), 3, "Test ? failed.");
}

TEST(Sort, InsertionSort)
{
  //void insertion_sort(int *array, int size);
  int input_array[3]    = {2,1,3};
  int output_array[3] = {1,2,3};

  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, 3, INSERTION), 3, "Test ? failed.");
}

TEST(Sort, ShellSort)
{
  //void shell_sort(int *vet, int size);
  int input_array[3]    = {2,1,3};
  int output_array[3] = {1,2,3};

  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, 3, SHELL), 3, "Test ? failed.");
}

TEST(Sort, QuickSort)
{
  //void shell_sort(int *vet, int size);
  int input_array[7]    = {2,1,3,5,4,6,2};
  int output_array[7] = {1,2,2,3,4,5,6};

  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, 7, QUICK), 7, "Test ? failed.");
}

TEST(Sort, HeapSort)
{
  //void heap_sort(int vet[], int n);
  int input_array[3]    = {2,1,3};
  int output_array[3] = {1,2,3};
  
  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, 3, HEAP), 3, "Test ? failed.");
}

TEST(Sort, MergeSort)
{
  //void merge_sort(int* vet, int n);
  int input_array[3]    = {2,1,3};
  int output_array[3] = {1,2,3};
  
  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(output_array, sort_array(input_array, 3, MERGE), 3, "Test ? failed.");
}

TEST(Sort, Aditional)
{
  //void merge_sort(int* vet, int n);
  int input_array[3]    = {2,1,3};
  //int output_array[3] = {1,2,3};
  
  // Test algorithm ID that doesnt exists. In this case, the output array should be
  //equal to the input array.
  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(input_array, sort_array(input_array, 3, -1), 3, "Test ? failed.");
  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(input_array, sort_array(input_array, 3, 7), 3, "Test ? failed.");

  //TEST_FOR_ALL(input_array, output_array, 3);

}

// runs the same input through all algorithms
//TEST_FOR_ALL(int *input, int *output, int size)
//{
//
//
//  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(input, sort_array(output, size, 0), size, "Test ? failed.");
//  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(input, sort_array(output, size, 1), size, "Test ? failed.");
//  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(input, sort_array(output, size, 2), size, "Test ? failed.");
//  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(input, sort_array(output, size, 3), size, "Test ? failed.");
//  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(input, sort_array(output, size, 4), size, "Test ? failed.");
//  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(input, sort_array(output, size, 5), size, "Test ? failed.");
//}