#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int target) {
    int a = 0, b = n - 1;
    while (a<=b) {
        int mid = a + (b - a) / 2;  // To avoid overflow
        if (arr[mid] == target) return mid;
        
        if (arr[mid] < target) a = mid + 1;
        else b = mid - 1;  
    }
    return -1;
}

// lower bound using binary search
int lowerBound(int arr[], int n,int target) {
    int a = 0, b = n - 1;
    int lowerBoundIdx = -1;
    while (a<=b) {
        int mid = a + (b - a) / 2;  // To avoid overflow
        if (arr[mid] >= target) {
            lowerBoundIdx = mid;
            b = mid - 1;
        }
        else a = mid + 1;
    }
    return lowerBoundIdx;
}

// upper bound using binary search
int upperBound(int arr[], int n,int target) {
    int a = 0, b = n - 1;
    int upperBoundIdx = -1;
    while (a<=b) {
        int mid = a + (b - a) / 2;  // To avoid overflow
        if (arr[mid] <= target) {
            upperBoundIdx = mid;
            a = mid + 1;
        }
        else b = mid - 1;
    }
    return upperBoundIdx;
}

int main() {
    // Even size array
    int arr[] = {10, 20, 30, 30, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Odd size array
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    // Test cases
    cout << lowerBound(arr, n, 30) << endl;
    
    cout << upperBound(arr, n, 30) << endl;

    return 0;
}