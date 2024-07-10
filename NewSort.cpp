#include "NewSort.h"
#include <cmath>
#include <iostream>
#include <map>
using namespace std;

#define INSERTION_MIN_SIZE 16

void inline swap(int& a, int& b) {
	register int t = a;
	a = b;
	b = t;
}

map<int, int> leonardo_numbers;

int inline leonardo(int k) {
	if (leonardo_numbers.empty()) {
		leonardo_numbers[0] = 1;
		leonardo_numbers[1] = 1;
	}
	if (leonardo_numbers.find(k) == leonardo_numbers.end()) {
		leonardo_numbers[k] = leonardo(k - 1) + leonardo(k - 2) + 1;
	}
	return leonardo_numbers[k];
}

inline void NewSort::InsertionSort(int* arr, int low, int high) {
	for (register int i = low + 1; i <= high; ++i) {
		register int e = arr[i];
		register int j = i;
		while (e < arr[--j] && j >= low) arr[j + 1] = arr[j];
		arr[j + 1] = e;
	}
}

void NewSort::Sorting(int* arr, int start, int end, int max_depth) {
	if (end - start <= 1) return;
	if (end - start <= INSERTION_MIN_SIZE) {
		InsertionSort(arr, start, end - 1);
		return;
	}
	if (max_depth) {
		int pivot = Partition(arr, start, end);
		Sorting(arr, start, pivot, --max_depth);
		Sorting(arr, pivot + 1, end, max_depth);
	}
	else HeapSort(arr, start, end);
}

void NewSort::HeapSort(int* arr, register int start, register int end) {
	register int p = end - start - 1;
	register int q = p;
	register int r = 0;
	while (p > start) {
		if ((r & 0x03) == 0) Heapify(arr, start, r, q);
		if (leonardo(r) != p) {
			--r;
			q = q - leonardo(r);
			Heapify(arr, start, r, q);
			q = r - 1;
		}
		++r;
		swap(arr[start], arr[p + start]);
		--p;
	}
	register int j;
	for (register int i = start; i < end - 1;) {
		j = ++i;
		while (j > start && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j = j - 1;
		}
	}
}

void NewSort::Heapify(int* arr, register int range_start, register int start, register int end) {
	register int i = start;
	register int j = 0;
	register int k = 0;
	while (k < end - start + 1) {
		if (k & 0xAAAAAAAA) {
			j += i;
			i = i >> 1;
		}
		else {
			i += j;
			j = j >> 1;
		}
		++k;
	}
	while (i > 0) {
		j = j >> 1;
		k = i + j;
		while (k < end) {
			if (arr[k + range_start] > arr[k - i + range_start]) break;
			swap(arr[k + range_start], arr[k - i + range_start]);
			k += i;
		}
		i = j;
	}
}

inline int NewSort::Partition(int* arr, int start, int end) {
	register int pivot = arr[start];
	register int left = start + 1;
	register int right = end - 1;
	while (true) {
		while (left <= right && arr[left] <= pivot) ++left;
		while (arr[right] >= pivot && right >= left) --right;
		if (right < left) break;
		swap(arr[left], arr[right]);
	}
	swap(arr[start], arr[right]);
	return right;
}

void NewSort::Sort(int* arr, unsigned int size) {
	Sorting(arr, 0, size, (int)log2(size) << 1);
	//HeapSort(arr, size/2, size);
}
