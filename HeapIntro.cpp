#include <iostream>
#include <vector>
#include<queue>
using namespace std;

// heap - complete binary tree matlb ek parent node ya node sirf uske dono child honge ya ek bhi ni
// head m every parent ->data is greater than both child data
class heap
{

public:
    int arr[100];
    int size = 0;

    void insert(int data) // done in O(logN)
    {
        size = size + 1;

        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap() // TC - O(logN)
    {
        if (size == 0)
        {
            cout << "Heap is EMPTY!!" << endl;
            return;
        }

        // Step 1 : put last element into first index
        arr[1] = arr[size];

        // step 2 : remove  last elemet from heap
        size--;

        // step 3 : take root node (first element) to its correct position

        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
            }
            if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
            }
            else
            {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i) // TC - O(logN) m shi jgh pucha deti h ye algo
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
        largest = left;

    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[],int n)
{
    int size = n-1;
    while (size > 1)
    {
        //step 1 : swap
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

int main()
{
    // for heapify
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 6;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Print the Heap : " << endl;
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr,n);
    cout << "Print the Sorted Heap : " << endl;
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout<<"Using Priority Queue For Heap"<<endl;

    //MAXHEAP
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    pq.push(1);

    cout<<"Element at Top of pq : "<<pq.top()<<endl; //maximum element will be stored on top
    pq.pop();
    cout<<"Element at Top of pq : "<<pq.top()<<endl;
    cout<<"Size of pq : "<<pq.size()<<endl;
    if( pq.empty()){
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }

    //MINHEAP
    priority_queue<int,vector<int> ,greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    minHeap.push(1);

    cout<<"Element at Top of minHeap : "<<minHeap.top()<<endl; //minimum element will be stored on top
    minHeap.pop();
    cout<<"Element at Top of minHeap : "<<minHeap.top()<<endl;
    cout<<"Size of minHeap : "<<minHeap.size()<<endl;
    if( minHeap.empty()){
        cout<<"minHeap is empty"<<endl;
    }
    else{
        cout<<"minHeap is not empty"<<endl;
    }
}