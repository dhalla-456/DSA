#include <bits/stdc++.h> 
#include<queue>
using namespace std;

void reverse(queue < int > & q) {
    stack<int> s;
    while(!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty())
    {
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
}

//Approach 2 by recursion

void reverse(queue < int > & q) {
    if (q.empty()) {

        // If the queue is empty, return.
        return;
    }

    // Store the front element in a variable.
    int element = q.front();
    q.pop();

    // Recursively call for the rest of the queue.
    reverse(q);

    // Push back the stored element.
    q.push(element);
}