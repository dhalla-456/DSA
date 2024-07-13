#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int findMinimumCost(string str) {
  //if the length of string is odd then return -1
  if(str.length()%2 == 1)
  {
    return -1;
  }

  stack<char> s;
  for(int i = 0; i < str.length() ; i++)
  {
    char ch = str[i];

    if(ch == '{')
    {
      s.push(ch);
    }     
    else{
      if(!s.empty() && s.top() == '{')
      {
        s.pop(); // found valid {} and removed it  
      }
      else{
        s.push(ch); //adding similar kind of Bracket
      }
    }
  }

  //now we have stack of invalid string
  int a = 0; int b = 0;
  while(!s.empty())
  {
    if(s.top() == '{')
    {
      a++;
    }
    else{
      b++;
    }
    s.pop();
  }
  int ans = (a+1)/2 + (b+1)/2;
  return ans;


}