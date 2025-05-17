#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>
#include <fstream>

#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"

#define B10k 10000
#define MAX_VAL 65535
#define AMOUNT_VECTORS 50

using namespace std;
typedef unsigned int uint;

struct Time {
  float mean;
  float DP;
};

// const vector<long int> bases = {10000, 100000, 1000000, 10000000, 100000000};
// const vector<long int> bases = {10000, 100000};
const vector<long int> bases = {10000, 100000, 1000000};

float calc_mean(const vector<float> &times)
{
  float sum = 0.0;
  for (float t : times) sum += t;
  return sum / times.size();
}

float calc_DP(const vector<float> &times, float mean)
{
  float sum = 0.0;
  for (float t : times)
  {
    sum += (t - mean) * (t - mean);
  }
  return sqrt(sum / times.size());
}

void  saveToCsv(vector<Time> &mergeResults, vector<Time> &quickResults, vector<Time> &heapResults, const vector<long int> &bases)
{
  // variaveis que irei usar:
  // mean e DP de cada algoritmo + bases
  std::ofstream file("resultados.csv");
  if (!file.is_open())
  {
    std::cerr << "Error while opening the file!" << std::endl;
    return;
  }

  file << "Base,MergeSort_mean,MergeSortDP,QuickSort_mean,QuickSortDP,HeapSort_mean,HeapSortDP\n";

  for (int i = 0; i < bases.size(); ++i)
  {
    file << bases[i] << ","
    << mergeResults[i].mean << "," << mergeResults[i].DP << ","
    << quickResults[i].mean << "," << quickResults[i].DP << ","
    << heapResults[i].mean << "," << heapResults[i].DP << "\n";
  }  

  file.close();
  cout << "Data saved with success" << endl;
}

int main()
{
  vector<Time> mergeResults(bases.size());
  vector<Time> quickResults(bases.size());
  vector<Time> heapResults(bases.size());

  // para cada uma das bases:
  for (int b = 0; b < bases.size(); ++b) {
    long int size = bases[b];
    // para cada vetor (max: 50), 
    vector<float> mergeTimes, quickTimes, heapTimes;
    cout << "\nBase: " << size << endl;

    vector<uint> base(size);
    vector<uint> buffer(size);

    auto baseStart = chrono::high_resolution_clock::now();

    for (int v = 0; v < AMOUNT_VECTORS; ++v)
    {
      auto vectorStart = chrono::high_resolution_clock::now();
      cout << "vetor: " << v;
      // GENERATE VECTOR
      std::random_device rd;
      std::mt19937 generator(rd());
      std::uniform_int_distribution<uint> dist(0, MAX_VAL);
      for (uint &n : base) n = dist(generator);

      // Quick
      buffer = base;
      auto start = chrono::high_resolution_clock::now();
      quickSort<uint>(&buffer, 0, buffer.size() - 1);
      auto end = chrono::high_resolution_clock::now();
      auto time = chrono::duration<float, milli>(end - start).count();
      quickTimes.push_back(time);

      // Merge
      buffer = base;
      start = chrono::high_resolution_clock::now();
      mergeSort<uint>(&buffer, 0, buffer.size() - 1);
      end = chrono::high_resolution_clock::now();
      time = chrono::duration<float, milli>(end - start).count();
      mergeTimes.push_back(time);

      // Heap
      buffer = base;
      start = chrono::high_resolution_clock::now();
      heapSort<uint>(&buffer);
      end = chrono::high_resolution_clock::now();
      time = chrono::duration<float, milli>(end - start).count();
      heapTimes.push_back(time);

      auto vectorEnd = chrono::high_resolution_clock::now();
      auto vectorTime = chrono::duration<float, milli>(vectorEnd - vectorStart).count();
      cout << " | tempo (s): " << vectorTime / 1000 << endl;
    }

    auto baseEnd = chrono::high_resolution_clock::now();
    auto baseTime = chrono::duration<float, milli>(baseEnd - baseStart).count();

    // Quick
    float quickMean = calc_mean(quickTimes);
    float quickDP = calc_DP(quickTimes, quickMean);
    quickResults[b] = {quickMean, quickDP};
    // Merge
    float mergeMean = calc_mean(mergeTimes);
    float mergeDP = calc_DP(mergeTimes, mergeMean);
    mergeResults[b] = {mergeMean, mergeDP};
    // Heap
    float heapMean = calc_mean(heapTimes);
    float heapDP = calc_DP(heapTimes, heapMean);
    heapResults[b] = {heapMean, heapDP};

    cout << "\nTotal time (s) for base " << size << " = " << baseTime / 1000;
    cout << "\nQuick: Mean = " << quickMean << " ms | DP = " << quickDP;
    cout << "\nMerge: Mean = " << mergeMean << " ms | DP = " << mergeDP;
    cout << "\nHeap:  Mean = " << quickMean << " ms | DP = " << quickDP << "\n"; 

    base.clear();
    buffer.clear(); 
  }

  saveToCsv(mergeResults, quickResults, heapResults, bases);

  return 0;
}
