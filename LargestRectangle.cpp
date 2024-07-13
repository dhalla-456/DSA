#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> nextSmaller(vector < int > arr,int n)
{
    stack<int> s;
    s.push(-1); // stack m phela element -1 daal diya compare krne keliye 
    vector<int> ans(n);
    for (int i = n-1; i >=0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        //ans stack ka top hoga
        ans[i] = s.top();
        s.push(i); 
    }
    
    return ans;
}

vector<int> prevSmaller(vector < int > arr,int n)
{
    stack<int> s;
    s.push(-1); // stack m phela element -1 daal diya compare krne keliye 
    vector<int> ans(n);
    for (int i = 0;i<n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        //ans stack ka top hoga
        ans[i] = s.top();
        s.push(i); 
    }
    
    return ans;
} 
 
int largestRectangle(vector<int>& heights) {
   int n = heights.size();

   vector<int> next(n);
   next = nextSmaller(heights,n);
   vector<int> prev(n);
   prev = prevSmaller(heights,n);

   int area = -256;

   for(int i = 0;i<n;i++)
   {
     int l = heights[i];
     if(next[i] == -1)
     {
       next[i] = n ;
     }

     int b = next[i] - prev[i] - 1;
     int newArea = l*b;
     area = max(area,newArea); 
   }
   return area;
 
    }
