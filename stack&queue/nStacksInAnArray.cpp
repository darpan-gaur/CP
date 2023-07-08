/*
https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271
*/

#include <bits/stdc++.h> 
class NStack
{
public:
    // Initialize your data structure.
    int *arr;
    int *top;
    int *next;
    int n,s;
    int freeSpot;
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        n = N, s=S;

        for (int i=0;i<n;i++) top[i]=-1;
        for (int i=0;i<s-1;i++) next[i] = i+1;
        next[s-1] = -1;

        freeSpot = 0;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if (freeSpot == -1) return false;

        int idx = freeSpot;

        // update freeSpot
        freeSpot = next[idx];

        arr[idx] = x;

        next[idx] = top[m-1];

        top[m-1] = idx;

        return true;


    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check for underflow
        if (top[m-1]==-1) return -1;

        int idx = top[m-1];
        top[m-1] = next[idx];
        next[idx] = freeSpot;
        freeSpot = idx;

        return arr[idx];
    }
};