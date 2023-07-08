/*
https://www.codingninjas.com/studio/problems/build-min-heap_1171167
*/

// Solution 1
// Time Complexity: O(nlogn), Space Complexity: O(1)
void heapify(vector<int> &arr, int n, int index) {
    int left = 2*index + 1;
    int right = 2*index + 2;

    int smallest = index;
    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(arr[smallest], arr[index]);
        heapify(arr, n, smallest);
    }

}

vector<int> buildMinHeap(vector<int> &arr)
{   
    int n = arr.size(),i;
    for (i=n/2-1;i>=0;i--) {
        heapify(arr, n , i);
    }
    return arr;
}