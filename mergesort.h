#ifndef MERGESORT_H
#define MERGESORT_H

#include<vector>
#include <limits>

template <typename T>
const T INF = std::numeric_limits<T>::infinity();

using namespace std;

template <typename T>
vector<T> LEFT(vector<T>* arr, T left, T mid)
{
  vector<T> L;
  T end = mid - left + 1;
  for (int i = 0; i < end; ++i)
    L.push_back((*arr)[left + i]);
  return L;
}

template <typename T>
vector<T> RIGHT(vector<T>* arr, T mid, T right)
{
  vector<T> R;
  T end = right - mid;
  for (int i = 0; i < end; ++i)
    R.push_back((*arr)[mid + 1 + i]);
  return R;
}

template <typename T>
void merge(vector<T> *arr, T left, T mid, T right)
{
  vector<T> L = LEFT(arr, left, mid);
  vector<T> R = RIGHT(arr, mid, right);
  
  int i = 0, j = 0;
  // mergiar vetores temporarios de volta arr[left..right]
  for (int k = left; k <= right; ++k)
  {
    if (i < L.size() && (j >= R.size() || L[i] <= R[j]))
    {
      (*arr)[k] = L[i];
      ++i;
    } else {
      (*arr)[k] = R[j];
      ++j;
    }
  }
}

template <typename T>
void mergeSort(vector<T> *arr, T left, T right)
{
  if (left < right)
  {
    T mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  } 
}

#endif