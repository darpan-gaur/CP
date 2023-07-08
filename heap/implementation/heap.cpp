#include <iostream>
#include <vector>
using namespace std;

class heap {
    public:
        int arr[100];
        int size;
        int capacity;

    heap() {
        arr[0] = -1;
        size = 0;
        capacity = 100;
    }

    void insert(int data) {
        // Time Complexity: O(logn)
        size = size + 1;
        int index = size;
        arr[index] = data;

        while(index > 1) {
            int parent = index/2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteFromHeap() {
        // Time Complexity: O(logn)
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[1] = arr[size];
        size = size - 1;

        int index = 1;
        while(index < size) {
            int left = 2*index;
            int right = 2*index + 1;

            if (left < size && arr[left] > arr[index]) {
                swap(arr[left], arr[index]);
                index = left;
            } 
            else if (right < size && arr[right] > arr[index]) {
                swap(arr[right], arr[index]);
                index = right;
            } 
            else {
                return;
            }
        }
    }

    void print() {
        for(int i=1; i<=size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

// Time :- O(nlogn)
void heapify(vector<int> &arr, int n, int index) {
    // 1 based indexing :- left = 2*index, right = 2*index + 1
    // 0 based indexing :- left = 2*index + 1, right = 2*index + 2
    int left = 2*index;
    int right = 2*index + 1;

    int largest = index;
    // 1 based indexing :- left <= n, right <= n
    // 0 based indexing :- left < n, right < n
    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n) {
    int size = n;

    while (size>1) {
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, size, 1);
    }
}

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteFromHeap();
    h.print();

    h.deleteFromHeap();
    h.print();

    // random array
    vector<int> arr = {-1, 54, 53, 55, 52, 50};

    for (int i=(arr.size()-1)/2; i>=1; i--) {
        heapify(arr, arr.size(), i);
    }

    cout << "Heapified array: ";
    for (int i=1; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // heap sort
    heapSort(arr, arr.size());

    cout << "Sorted array: ";
    for (int i=1; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}