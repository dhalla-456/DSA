//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isSafe(int x,int y,vector<vector<bool>> &visited,vector<vector<int> > &arr, int n)
{
  if( (x >= 0 && x < n) && (y >= 0 && y < n ) && (visited[x][y] != 1 ) && (arr[x][y] == 1) )
    return true;
  
  else{
    return false;
  }
}

void solve(int x,int y,vector < vector < int >> & arr,int n,vector<string>& ans,vector<vector<bool>> &visited,string path)
{
    //base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    //Down
    if(isSafe(x+1,y,visited,arr,n)){
        solve(x+1,y,arr,n,ans,visited,path + 'D');
    }
    //Left
    if(isSafe(x,y-1,visited,arr,n)){
        solve(x,y-1,arr,n,ans,visited,path + 'L');
    }
    //Right
    if(isSafe(x,y+1,visited,arr,n)){
        solve(x,y+1,arr,n,ans,visited,path + 'R');
    }
    //Up
    if(isSafe(x-1,y,visited,arr,n)){
        solve(x-1,y,arr,n,ans,visited,path + 'U');
    }
    visited[x][y] = 0;
}
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> visited(n,vector<bool> (n,0));

        string path = "";
        if(m[0][0] == 0){
            return ans;
        }
        solve(0,0,m,n,ans,visited,path);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends