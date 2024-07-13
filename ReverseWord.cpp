#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

void reverseWords(string& s) {
    reverse(s.begin(), s.end()); // Reverse the entire string

    int start = 0;
    int len = s.length();
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
}

int main() {
    string s = "the sky is blue";
    reverseWords(s);
    cout << s << endl;
    return 0;
}
