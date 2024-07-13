class Solution {
private:
    void solve(string digits,string output,int index , string mapping[],vector<string> &ans)
    {
        if(index >= digits.length())
        {
            ans.push_back(output);
            return;
        }

        int num = digits[index] - '0';
        string val = mapping[num];

        for(int i = 0 ; i<val.length() ; i++ )
        {
            output.push_back(val[i]);
            solve(digits,output,index+1,mapping,ans);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
        {
            return ans;
        }
        int index = 0;
        string output = "";
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,mapping,ans);
        return ans; 
    }
};