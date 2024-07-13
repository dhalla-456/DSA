#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

string reArrangeString(string &s)
{
    string res = "";
    unordered_map<char, int> m;
    priority_queue<pair<int, char>> q;
    int n = s.length();

    // Count the frequency of each character
    for (char c : s) {
        m[c]++;
    }

    // Insert each character and its frequency into a priority queue
    for (auto it : m) {
        q.push({it.second, it.first});
    }

    // Repeatedly add the most frequent character that is different from the last one added
    while (!q.empty()) {
        char c = q.top().second;
        q.pop();
        if (res.length() == 0 || c != res.back()) {
            res += c;
            m[c]--;
            if (m[c] > 0) {
                q.push({m[c], c});
            }
        } else {
            if (q.empty()) {
                return "not possible";
            }
            char next = q.top().second;
            q.pop();
            res += next;
            m[next]--;
            if (m[next] > 0) {
                q.push({m[next], next});
            }
            q.push({m[c], c});
        }
    }
    
    // Check if the result is valid
    for (int i = 1; i < res.length(); i++) {
        if (res[i] == res[i-1]) {
            return "not possible";
        }
    }

    return res;
}

int main()
{
    string s = "huijahsj";
    cout << reArrangeString(s) << endl;
    
    s = "opiijakdf";
    cout << reArrangeString(s) << endl;
    
    s = "vvvio";
    cout << reArrangeString(s) << endl;
    
    s = "aaaaaaaaaa";
    cout << reArrangeString(s) << endl;
    
    s = "codechefvscodeforces";
    cout << reArrangeString(s) << endl;
    
    s = "internship";
    cout << reArrangeString(s) << endl;
    
    s = "zooo";
    cout << reArrangeString(s) << endl;

    return 0;
}
