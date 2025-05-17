#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <random>





// Merge Sort
void merge(std::vector<int>& a, int first, int last, int mid) {
    int n = last - first + 1;
    int a1first = first, a1last = mid - 1;
    int a2first = mid, a2last = last;

    std::vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        if (a1first <= a1last) {
            if (a2first <= a2last) {
                if (a[a1first] <= a[a2first]) temp[i] = a[a1first++];
                else temp[i] = a[a2first++];
            } else {
                temp[i] = a[a1first++];
            }
        } else {
            temp[i] = a[a2first++];
        }
    }
    for (int i = 0; i < n; ++i) {
        a[first + i] = temp[i];
    }
}

void mergeSort(std::vector<int>& a, int first, int last) {
    if (first < last) {
        int mid = (first + last + 1) / 2;
        mergeSort(a, first, mid - 1);
        mergeSort(a, mid, last);
        merge(a, first, last, mid);
    }
}



// QuickSort
void swap(std::vector<int>& arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int preparePartition(std::vector<int>& a, int first, int last) {
    int pivotElement = a[last]; 
    int i = first - 1;
    for (int j = first; j < last; ++j) {
        if (a[j] <= pivotElement) {
            ++i;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, last);
    return i + 1;
}

void quickSort(std::vector<int>& a, int first, int last) {
    if (first < last) {
        int part = preparePartition(a, first, last);
        quickSort(a, first, part - 1);
        quickSort(a, part + 1, last);
    }
}

// Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization for O(n) that we stop if its already sorted
    }
}


int main() {

    const int TIME_LIMIT_MS = 60000; // 60 seconds

    using namespace std::chrono;

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1'000'000);

    std::vector<int> array;
    bool mergeSort_active = true;
    bool bubbleSort_active = true;
    bool quickSort_active = true;

    for (int arraySize = 100; arraySize < 1'000'000; arraySize += 100) {
        array.resize(arraySize);
        for (int& val : array) {
            val = dist(rng);
        }

        // Only copy if needed
        std::vector<int> mergeArray, bubbleArray, quickArray;
        if (mergeSort_active) mergeArray = array;
        if (bubbleSort_active) bubbleArray = array;
        if (quickSort_active) quickArray = array;


        if (mergeSort_active) {
            auto start = high_resolution_clock::now();
            mergeSort(mergeArray, 0, static_cast<int>(mergeArray.size()) - 1);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            if (duration.count() > TIME_LIMIT_MS) {
                std::cout << "Merge Sort managed to sort " << arraySize << " elements\n";
                mergeSort_active = false;
            }
        }

        if (bubbleSort_active) {
            auto start = high_resolution_clock::now();
            bubbleSort(bubbleArray);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            if (duration.count() > TIME_LIMIT_MS) {
                std::cout << "Bubble Sort managed to sort " << arraySize << " elements\n";
                bubbleSort_active = false;
            }
        }

        if (quickSort_active) {
            auto start = high_resolution_clock::now();
            quickSort(quickArray, 0, static_cast<int>(quickArray.size()) - 1);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            if (duration.count() > TIME_LIMIT_MS) {
                std::cout << "Quick Sort managed to sort " << arraySize << " elements\n";
                quickSort_active = false;
            }
        }

        // Exit if all algorithms are done
        if (!mergeSort_active && !bubbleSort_active && !quickSort_active) break;
    }

    return 0;
}
