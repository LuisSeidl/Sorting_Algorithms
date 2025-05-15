#include <iostream>
#include <vector>

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
        for (int x : a) std::cout << x << " ";
        std::cout << "\n";
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
        for (int x : a) std::cout << x << " ";
        std::cout << "\n";
    }
}

int main() {
    std::vector<int> testArray = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};

    // Make copies to sort independently
    std::vector<int> mergeSorted = testArray;
    std::vector<int> quickSorted = testArray;

    mergeSort(mergeSorted, 0, mergeSorted.size() - 1);
    std::cout << "\nMerge Sorted: ";
    for (int x : mergeSorted) std::cout << x << " ";
    std::cout << "\n \n";


    quickSort(quickSorted, 0, quickSorted.size() - 1);
    std::cout << "\nQuick Sorted: ";
    for (int x : quickSorted) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
