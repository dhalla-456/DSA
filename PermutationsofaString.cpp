#include <algorithm>

void generatePermutationsHelper(string &str, int l, int r, vector<string> &ans)
{
    // base case
    if (l == r)
    {
        ans.push_back(str);
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(str[l], str[i]);
        generatePermutationsHelper(str, l + 1, r, ans);
        // backtrack
        swap(str[l], str[i]);
    }
}

vector<string> generatePermutations(string &str)
{
    // stores the permutations of the string
    vector<string> ans;

    int l = 0;
    int r = str.size() - 1;

    // call the recursive function
    generatePermutationsHelper(str, l, r, ans);

    // lexicographically increasing order
    sort(ans.begin(), ans.end());

    return ans;
}