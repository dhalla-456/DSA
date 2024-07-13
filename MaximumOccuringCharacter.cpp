#include<iostream>
#include<string>
using namespace std;

char getMaxOccChar(string str)
{
    int arr[26] = {0} ;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        int number = 0 ;
        if(ch >= 'a' && ch <= 'z'){
            number = ch - 'a';
        }
        else
        {
            number = ch - 'A';
        }
        arr[number]++;
    }
    
    int maxi = -1;
    int ans = 0;

    for (int i = 0; i < 26; i++)
    {
        if(maxi < arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    
    char FinalAns = 'a' + ans;
    return FinalAns;
}