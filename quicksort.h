#ifndef QUICKSORT_H
#define QUICKSORT_H

#include<vector>

using namespace std;


template <typename T>
T partition(vector<T> *arr, T left, T right)
{
  T pivo = (*arr)[right];
  T i = left - 1;

  for (int j = left; j < right; ++j)
  {
    if ((*arr)[j] <= pivo)
    {
      i = i + 1;
      swap((*arr)[i], (*arr)[j]);
    }
  }

  swap((*arr)[i + 1], (*arr)[right]);
  return i + 1;
}

template <typename T>
void quickSort(vector<T> *arr, T left, T right)
{
  if (left < right)
  {
    T mid = partition(arr, left, right);
    quickSort(arr, left, mid - 1); 
    quickSort(arr, mid + 1, right); 
  }
}

#endif