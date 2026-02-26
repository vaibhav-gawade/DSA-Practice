#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Problem : Grumpy Bookstore Owner
// Approach : slidding window
// first add all the minutes when shopkepper is not grumpy
// Then we store in window the time where customers are more and shopkeeper is grumpy
// Then we use shopkeeper technique to not be grumpy at that time to satisfy more customers

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base=0;

        // when shopkepper is not grumpy
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0) base+=customers[i];
        }

        // for using technique of not remaining grumpy
        int extra=0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1) extra+=customers[i];
        }

        int maxextra=extra;
        
        for(int i=minutes;i<customers.size();i++){
            if(grumpy[i]==1) extra+=customers[i];
            if(grumpy[i-minutes]==1) extra-=customers[i-minutes];

            maxextra=max(extra,maxextra);
        }
        return base+maxextra;
    }

int main(){
    vector<int>customers={1,0,1,2,1,1,7,5};
    vector<int>grumpy={0,1,0,1,0,1,0,1};
    int minutes=3;

    int n=maxSatisfied(customers,grumpy,minutes);

    cout<<"The maximum customers that shopkeeper can satisfy are "<<n;

    return 0;
}