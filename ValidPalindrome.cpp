#include <bits/stdc++.h> 
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filteredStr;
    for (char c : s) {
        if (isalnum(c)) {
            filteredStr += tolower(c);
        }
    }

    // Check if the filtered string is a palindrome
    int left = 0;
    int right = filteredStr.length() - 1;

    while (left < right) {
        if (filteredStr[left] != filteredStr[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
    }
};