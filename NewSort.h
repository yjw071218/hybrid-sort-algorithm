#pragma once
class NewSort {
private:
	static void Sorting(int* arr, int start, int end, int max_depth);
	static void HeapSort(int* arr, int start, int end);
	static void Heapify(int* arr, int range_start, int start, int end);
	static inline int Partition(int* arr, int start, int end);
	static inline void InsertionSort(int* arr, int low, int high);

public:
	static void Sort(int* arr, unsigned int size);
};

