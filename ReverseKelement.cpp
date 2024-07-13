#include <bits/stdc++.h> 
#include<queue>
using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> s;

    for(int i = 0;i<k;i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    for(int i = 0;i<k;i++)
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    int r = q.size() - k;
    while(r)
    {
        int val = q.front();
        q.pop();
        q.push(val);
        r--;
    }
    return q;
}
