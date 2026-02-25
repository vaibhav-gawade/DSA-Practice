#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// problem : subarray with k different intergers
// approach : slidding window
// we find the number of subarray with atmost k and atmost k-1
// the exactly(k)=atmost(k)-atmost(k-1)

int distinctk(vector<int>&nums,int k){
    int left=0,distcount=0;
    int count=0;
    int n=nums.size();
    unordered_map<int,int>freq;
        
    for(int i=0;i<n;i++){
        freq[nums[i]]++;
        if(freq[nums[i]]==1) distcount++;

        while(distcount>k){
            freq[nums[left]]--;
            if(freq[nums[left]]==0) distcount--;
            left++;
        }
        // count gives the unique subarray as the right index is always different
        count+=(i-left+1);
    }

    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    if(k==0) return 0;
    int windowk=distinctk(nums,k);
    int windowk1=distinctk(nums,k-1);

    return windowk-windowk1;
}

int main(){
    vector<int>nums={1,2,1,2,3};
    int k=2;

    int n=subarraysWithKDistinct(nums,k);

    cout<<"The number of subarray with different intergers exactly "<<k<<" are "<<n;

    return 0;
}