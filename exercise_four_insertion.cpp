#include <vector>


void insertionSort(std::vector<int>& arr){
    int i,j,key;
    int n = arr.size();

    for(j=1; j<n; ++j){
        recursiveInsertion(arr,i,j, key);
    }
}

void recursiveInsertion(std::vector<int>& arr,int index1,int index2,int key){
    key = arr[index2];
    index1 = index2-1;
    while (index1 >= 0 && arr[index1] > key){
        arr[index1+1] = arr[index1];
        --index1;
    }
    arr[index1+1] = key;
}


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


void iterativeMerge(std::vector<int>& a, int first, int last){
    while (first < last){
        int mid = (first + last + 1) / 2;

    //MergeSort 1    
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
}