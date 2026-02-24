#include<iostream>
#include<vector>
using namespace std;

// Problem : Max consecutive Ones
// Approach : Slidding Window
// We maintain a window where number of 0's are less than k
// If we find the window containing 0's more than k times we shrink

int LongestOnes(vector<int>&nums,int k){
    int maxcount=0;
    int left=0;
    int count=0;
    int n=nums.size();
    
    for(int right=0;right<n;right++){
        if(nums[right]==0) count++;
        while(count>k){
            if(nums[left]==0) count--;
            left++;
        }

        maxcount=max(maxcount,right-left+1);
    }

    return maxcount;
}

int main(){
    vector<int>nums={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k=3;

    int n=LongestOnes(nums,k);

    cout<<"The max consecutive ones after replacing 0's "<<k<<" times are "<<n;

    return 0;
}