#ifndef HEAPSORT_H
#define HEAPSORT_H

#include<vector>

using namespace std;

int left(int i)
{
  return 2 * i + 1;
}

int right(int i)
{
  return (2 * i) + 2;
}

template <typename T>
void heapfy(vector<T> *arr, int n, int i)
{
  int l = left(i);
  int r = right(i);
  int largest = i;

  if (l < n && (*arr)[l] > (*arr)[largest])
    largest = l;
  if (r < n && (*arr)[r] > (*arr)[largest])
    largest = r;

  if (largest != i)
  {
    swap((*arr)[i], (*arr)[largest]);
    heapfy(arr, n, largest);
  }
}

template <typename T>
void buildHeap(vector<T> *arr)
{
  for (int i = ((*arr).size() / 2) - 1; i >= 0; i--)
    heapfy(arr, (*arr).size(), i);
}

template <typename T>
void heapSort(vector<T> *arr)
{
  buildHeap(arr);

  for (int i = (*arr).size() - 1; i > 0; i--)
  {
    swap((*arr)[0], (*arr)[i]);
    heapfy(arr, i, 0);
  }
}

#endif