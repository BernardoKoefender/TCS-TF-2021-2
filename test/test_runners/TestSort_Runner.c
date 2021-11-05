#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sort)
{
  RUN_TEST_CASE(Sort, SelectionSort);
  RUN_TEST_CASE(Sort, InsertionSort);
  RUN_TEST_CASE(Sort, ShellSort);
  RUN_TEST_CASE(Sort, QuickSort);
  RUN_TEST_CASE(Sort, HeapSort);
  RUN_TEST_CASE(Sort, MergeSort);
  RUN_TEST_CASE(Sort, Aditional);
}
