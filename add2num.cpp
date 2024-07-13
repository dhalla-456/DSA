#include<bits/stdc++.h>
using namespace std;

void solve(string a,string b,string& ans,int i,int j,int carry){
    if(i < 0 && j < 0 && carry == 0){
        return;
    }

    int first = 0;
    int second = 0;
    if(i >= 0){
        first = a[i] - '0';
    }
    if(j >= 0){
        second = b[j] - '0';
    }

    int sum = first + second + carry;
    int last = sum % 10;
    carry = sum/10;
    ans.push_back(last + '0');

    solve(a,b,ans,i-1,j-1,carry);
}

int main()
{
    string a = "43";
    string b = "343";

    string ans = "";
    int carry = 0;
    solve(a,b,ans,a.length()-1,b.length()-1,carry);
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
