#include <iostream>
#include <vector>

using namespace std;

/*
Merge Sort
Time Complexity: O(nlogn)
Space Complexity: O(n)
Stable: Yes
Parallel: Yes
*/

// merge
void merge(vector<int> &arr, int l, int r) {
    int mid = (l + r) / 2;
    int i = l, j = mid + 1;
    vector<int> tmp;
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            tmp.push_back(arr[i++]);
        } else {
            tmp.push_back(arr[j++]);
        }
    }
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);
    for (int i = l; i <= r; i++) {
        arr[i] = tmp[i - l];
    }
}

// merge sort
void mergeSort(vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, r);
}


// Count inversions
int countMerge(vector<int> &arr, int l, int r) {
    int mid = (l + r) / 2;
    int i = l, j = mid + 1;
    int cnt = 0;
    vector<int> tmp;
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            tmp.push_back(arr[i++]);
        } else {
            tmp.push_back(arr[j++]);
            cnt += mid - i + 1;
        }
    }
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);
    for (int i = l; i <= r; i++) {
        arr[i] = tmp[i - l];
    }
    return cnt;
}

// Count inversions
int countMergeSrt(vector<int> &arr, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    int cnt = 0;
    cnt += countMergeSrt(arr, l, mid);
    cnt += countMergeSrt(arr, mid + 1, r);
    cnt += countMerge(arr, l, r);
    return cnt;
}

// print array
void printArray(vector<int> &arr) {
    for (auto &i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n = 10;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    printArray(arr);

    mergeSort(arr, 0, n - 1);

    printArray(arr);

    return 0;
}