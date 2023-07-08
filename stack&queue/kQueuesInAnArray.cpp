#include <iostream>

using namespace std;

class kQueue{
public:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int n,k;
    int freeSpot;

    // constructor
    kQueue(int n, int k) {
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++) {
            front[i] = rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n-1; i++) {
            next[i] = i+1;
        }
        next[n-1] = -1;

        arr = new int[n];
        freeSpot = 0;
    }

    void enqueue(int data, int q) {
        q--;        // for zero based indexing

        // check overflow
        if (freeSpot == -1) {
            cout << "Overflow" << endl;
            return;
        }

        int idx = freeSpot;     // get the free spot
        freeSpot = next[idx];   // update free spot

        // if queue is empty
        if (front[q] == -1) {
            front[q] = idx;
        } else {
            next[rear[q]] = idx;
        }

        next[idx] = -1;     // update next
        rear[q] = idx;      // update rear

        arr[idx] = data;    // insert data
    }

    int dequeue(int q) {
        q--;        // for zero based indexing

        // check underflow
        if (front[q] == -1) {
            // cout << "Underflow" << endl;
            return -1;
        }

        int idx = front[q];     // get the front
        front[q] = next[idx];   // update front

        next[idx] = freeSpot;   // update next
        freeSpot = idx;         // update free spot

        return arr[idx];        // return data
    }
};

int main() {

    kQueue q(10, 3);

    q.enqueue(1, 1);
    q.enqueue(2, 1);
    q.enqueue(3, 1);
    q.enqueue(4, 2);
    q.enqueue(5, 2);
    q.enqueue(6, 3);
    q.enqueue(7, 3);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(3) << endl;

    return 0;
}