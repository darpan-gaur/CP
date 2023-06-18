#include <iostream>
#include <vector>

using namespace std;

/*
Quick Sort
Time Complexity: O(nlogn), Worst: O(n^2)
Space Complexity: O(1)
Stable: No
Parallel: No
*/

int partition(vector<int>& arr, int a, int b){
    int pivot = arr[a];
    int count = 0;
    for (int i = a+1; i <= b; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }
    int pivotIndex = a + count;
    swap(arr[a], arr[pivotIndex]);

    int i = a, j = b;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;

}

void quickSort(vector<int>& arr, int a, int b) {
    if (a>=b) return;
    
    // partion the array
    int p = partition(arr, a, b);

    // sort the left part
    quickSort(arr, a, p-1);

    // sort the right part
    quickSort(arr, p+1, b);

}

// print
void print(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }cout << "\n";
}

int main() {
    int n = 10;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // print
    print(arr);

    // sort
    quickSort(arr, 0, n-1);

    // print
    print(arr);

    return 0;
}