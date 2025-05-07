#include <iostream>
#include <vector>
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"

using namespace std;

typedef unsigned int uint;

int main()
{
	vector<uint> nums = {3, 1, 4, 2, 8, 5, 7, 6};

  heapSort<uint>(&nums);

  for (uint &n : nums)
  {
    cout << n << " ";
  }
}
