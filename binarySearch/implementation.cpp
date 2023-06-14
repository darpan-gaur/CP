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

int main() {
    // Even size array
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Odd size array
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    // Test cases
    cout << binarySearch(arr, n, 20) << endl;
    
    cout << binarySearch(arr2, n2, 3) << endl;

    return 0;
}