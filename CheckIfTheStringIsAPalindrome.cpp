#include <bits/stdc++.h> 
#include<iostream>
#include<string>
using namespace std;

char tolower(char ch)
{
   if (ch >= 'a' && ch <= 'z')
       return ch;
   else 
   {
       char temp = ch - 'A' + 'a';
       return temp;
   }
}
bool checkPalindrome(string st)
{
   int s = 0, e = st.length() - 1;
   while (s <= e)
   {
       if (isalnum(st[s])==0)
           s++;
       else if (isalnum(st[e])==0)
           e--;
       else if (tolower(st[s]) != tolower(st[e]))
           return false;
       else
       {
           s++; e--;
       }
   }
   return true;
}


//simple approch

// #include <bits/stdc++.h> 
// bool checkPalindrome(string s)
// {
//     string filteredStr;
//     for (char c : s) {
//         if (isalnum(c)) {
//             filteredStr += tolower(c);
//         }
//     }

//     // Check if the filtered string is a palindrome
//     int left = 0;
//     int right = filteredStr.length() - 1;

//     while (left < right) {
//         if (filteredStr[left] != filteredStr[right]) {
//             return false;
//         }
//         left++;
//         right--;
//     }

//     return true;
// }