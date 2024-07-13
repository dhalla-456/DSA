#include<vector>
using namespace std;

bool isPossible(vector<int> &boards, int k, int n, int mid) {
    int painter = 1;
    int unit = 0;
    
    for(int i = 0; i<n; i++) {
        if(unit + boards[i] <= mid) {
            unit += boards[i];
        }
        else
        {
            painter++;
            if(painter > k || boards[i] > mid ) {
            return false;
        }
            unit = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    int n = boards.size();
    for(int i = 0; i<n; i++) {
        sum += boards[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(boards,k,n,mid)) {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}