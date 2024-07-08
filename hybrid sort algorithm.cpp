#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Insertion Sort
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[(left + right) / 2];
    int i = left - 1, j = right + 1;
    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        quickSort(arr, left, p);
        quickSort(arr, p + 1, right);
    }
}

// Smooth Sort
void siftDown(vector<int>& arr, int i, int n) {
    int child;
    while (2 * i + 1 < n) {
        child = 2 * i + 1;
        if (child + 1 < n && arr[child] < arr[child + 1])
            child++;
        if (arr[i] < arr[child])
            swap(arr[i], arr[child]);
        else
            return;
        i = child;
    }
}

void smoothSort(vector<int>& arr) {
    int n = arr.size();
    int len = 0;
    while (len < n) {
        int p = (1 << ((int)log2(len + 1) + 1)) - 1 - len;
        len += p;
        for (int i = n - len; i < n; i++)
            siftDown(arr, i - p, n);
        for (int i = n - len; i < n; i++)
            swap(arr[i - p], arr[i]);
    }
}

// Hybrid Algorithm
void hybridSort(vector<int>& arr) {
    if (arr.size() <= 16) {
        insertionSort(arr, 0, arr.size() - 1);
    }
    else {
        quickSort(arr, 0, arr.size() - 1);
        smoothSort(arr);
    }
}

int main() {

    vector<int> arr;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    hybridSort(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
