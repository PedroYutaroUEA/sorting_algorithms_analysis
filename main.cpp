#include<iostream>
#include<vector>
#include "mergesort.h"
#include "quicksort.h"

using namespace std;

typedef unsigned int uint;

int main()
{
	vector<uint> nums = {3, 1, 4, 2, 8, 5, 7, 10, 6};

  quickSort<uint>(&nums, 0, nums.size() - 1);

  for (uint &n : nums)
  {
    cout << n << " ";
  }
}
