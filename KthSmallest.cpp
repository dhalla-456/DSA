//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include<iostream>
#include<queue>
using namespace std;

class heap{

    public:
    int arr[100];
    int size = 0;
};

//maxheap ka use krke humne smallest element nikal liya
//aise hi min heap ka use krke maximum element nikal skte h 

int kthSmallest(int arr[], int l, int r, int k) 
{        
    priority_queue<int> pq;

    for(int i = 0;i<k;i++)
    {
        pq.push(arr[i]); //first k element ko ek max heap m dala
    }

    for (int i = k; i <= r; i++)
    {
        if(arr[i] < pq.top()){  //agr apka element (arr[i]), max heap ke top [pq.top] se chota h 
            pq.pop();           
            pq.push(arr[i]);
        }
    }
    int ans = pq.top();  
    return ans;
}