#include<vector>
using namespace std;

#include <bits/stdc++.h> 
int firstCircularTour(vector<int>& petrol, vector<int>& distance, int N)
{
	   int deficit = 0;
       int balance = 0;
       int start = 0;
       
       for(int i = 0 ;i<N;i++)
       {
           balance = balance + petrol[i] - distance[i];
           if(balance<0)
           {
               deficit = deficit + balance;
               start = i+1;
               balance = 0;
           }
       }
       if(deficit+balance >= 0)
       {
           return start;
       }
       else{
           return -1;
       }
}
