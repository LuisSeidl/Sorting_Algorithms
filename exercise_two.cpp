#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

// merge function
void merge(std::vector<int>& a, int first, int last, int mid) {
    int n = last - first + 1;
    int a1first = first, a1last = mid - 1;
    int a2first = mid, a2last = last;

    std::vector<int> temp(n);

    for (int i = 0; i < n; i++) {
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

    for (int i = 0; i < n; i++) {
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

// quicksort helpers
void swap(std::vector<int>& arr, int a, int b) {
    int h = arr[a];
    arr[a] = arr[b];
    arr[b] = h;
}

int preparePartition(std::vector<int>& a, int first, int last) {
    int pivotElement = a[first];
    int p = first - 1;
    for (int i = first; i <= last; i++) {
        if (a[i] <= pivotElement) {
            p++;
            swap(a, p, i);
        }
    }
    swap(a, p, first);
    return p;
}

void quickSort(std::vector<int>& a, int first, int last) {
    if (first < last) {
        int part = preparePartition(a, first, last);
        quickSort(a, first, part - 1);
        quickSort(a, part + 1, last);
    }
}


void bubbleSort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}









int main() {

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    std::vector<int> array;
    
    for(int arraySize = 100; arraySize < 1000000; arraySize+=100){

        array.resize(arraySize);

        for (int elementAt = 0; elementAt < arraySize; ++elementAt){
            array[elementAt] = rand();
        }

        auto Start = high_resolution_clock::now();

        mergeSort(array, 0, array.size() - 1);

        auto End = high_resolution_clock::now();

        auto Duration = duration_cast<milliseconds>(End-Start);

        if (Duration.count() > 60000){
            std::cout << "Merge Sort managed to Sort " << arraySize << " Elements";
            return 0;
        }
    }
}



