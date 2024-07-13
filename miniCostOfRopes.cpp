//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class heap{

    public:
        int arr[100];
        int size = 0;
};

long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        long long cost = 0;

        while (pq.size() > 1)
        {
            long long a = pq.top();
            pq.pop();

            long long b = pq.top();
            pq.pop();

            long long sum = a + b;
            cost = cost + sum;

            pq.push(sum);
        }
        return cost;
    }