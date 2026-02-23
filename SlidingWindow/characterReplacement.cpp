#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Problem: Longest Repeating Character Replacement
// Approach: Sliding Window
// We maintain a window where (window size - max frequency) <= k.
// If it exceeds k, we shrink the window from the left.

int characterReplacement(string s,int k){
    int maxWindow=0,maxFreq=0,left=0;
    int freq[26]={0};
    int n=s.length();

    for(int right=0;right<n;right++){
        freq[s[right]-'A']++;
        maxFreq=max(maxFreq,freq[s[right]-'A']);
        // WindowSize=right-left+1

        while(((right-left+1)-maxFreq)>k){
            freq[s[left]-'A']--;
            left++;
        }

        maxWindow=max(right-left+1,maxWindow);
    }

    return maxWindow;
}

int main(){
    string s="AABABBABAAABB";
    int k=4;

    int longrepeated=characterReplacement(s,k);

    cout<<"The longest valid substring is "<<longrepeated;

    return 0;
}