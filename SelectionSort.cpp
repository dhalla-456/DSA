#include<vector>
#include<algorithm>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0 ;  i < n ; i++)
    {
        int minindex = i ;
        
        for(int j = i + 1 ; j < n ; j++)
        {
            if(arr[j] < arr[minindex])
            {
                minindex = j ;
            }
        }
       swap(arr[minindex],arr[i]);
    }
}