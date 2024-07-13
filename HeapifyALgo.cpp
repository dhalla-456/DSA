#include<iostream>
#include<vector>
using namespace std;


//heap - complete binary tree matlb ek parent node ya node sirf uske dono child honge ya ek bhi ni 
//head m every parent ->data is greater than both child data
//heapify algorithm given node ko uski sho jhg pe puchata h 
class heap{

    public:
    int arr[100];
    int size = 0;

    heap(){
        arr[0] = -1;
        size = 0;
    }
};    

void heapify(vector<int> &arr, int n, int i) 
{
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;
        if(left < n && arr[largest] < arr[left])
            largest = left;
    
        if(right < n && arr[largest] < arr[right])
            largest = right;
        
        if(largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
}