//https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0

#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int getKthLargest(vector<int> &arr,int k)
{
    //Approach  1: sare subarray ek vector m store kiye or sort krke n-k element jo ki kth largest element ke
    //equal h return kr diya
    vector<int> sumStore;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(),sumStore.end());

    return sumStore[sumStore.size() - k];

    //Approach 2 : use min heap jaise kth smallest element wala ques kiya tha uska ulta hi krna h 

    priority_queue<int,vector<int>,greater<int>> mini;

    for (int i = 0; i < n; i++)
    {
        int sum = 0 ;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if(mini.size() < k){
                mini.push(sum);
            }
            else
            {
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}