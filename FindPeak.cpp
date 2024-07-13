#include<iostream>
#include<vector>
using namespace std;

int findPeak(int arr[], int n) {

    int s =0, e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {
        //cout<<" s " << s <<" e " << e << endl;
        if(arr[mid] < arr[mid+1]){
            s = mid+1; 
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s+(e-s)/2;
        
        while(s<e){
            if(nums[mid]<nums[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid = s+(e-s)/2;
        }
        return s;
    }
};