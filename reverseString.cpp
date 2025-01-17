//Reverse a String Using Stack
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string str = "overflow";
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }
    
    string ans = "";

    while (!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    
    cout<<ans;

    return 0;
}
