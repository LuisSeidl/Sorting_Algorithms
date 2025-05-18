#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int first, int mid, int last) {
    int n = last - first + 1;
    int a1first = first, a1last = mid - 1;
    int a2first = mid, a2last = last;

    vector<int> temp(n);
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

void mergeSort(vector<int>& a, int first, int last) {
    if (first < last) {
        int mid = (first + last + 1) / 2;
        mergeSort(a, first, mid - 1);
        mergeSort(a, mid, last);
        merge(a, first, last, mid);
    }
}


void iterativeMerge(vector<int>& a){ //shoutout to Abdul Bari on Youtube
    int n = a.size();

    for(int currsize = 1; currsize<= n-1; currsize=currsize*2){
        for (int leftStart = 0; leftStart < n-1 ; leftStart += 2*currsize){
            
            int mid = min(leftStart+ currsize -1, n-1);
            int rightEnd = min(leftStart+ 2*currsize -1, n-1);
            merge(a, leftStart, mid, rightEnd);
        }
    }
}


int main() {
    vector<int> arr = {4, 1, 3, 9, 7};
    
    iterativeMerge(arr);
    for (auto val: arr) 
        cout << val << " ";

}