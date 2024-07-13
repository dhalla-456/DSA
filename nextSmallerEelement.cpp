#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement( vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1); // stack m phela element -1 daal diya compare krne keliye 
    vector<int> ans(n);
    for (int i = n-1; i >=0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }

        //ans stack ka top hoga
        ans[i] = s.top();
        s.push(curr); 
    }
    
    return ans;
}

//Approach 1:
//take two loops and compare with left array or bcha hua array
//
//Approach 2:
//use stack and store -1 in it and traverse array from n-1 index