#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];   
        }
        //main logic
        int minElem=nums[0];
        int maxDiff=INT_MIN;
        for(int i=1;i<n;i++)
        {
                int diff=nums[i]-minElem;
                if(diff>maxDiff)
                maxDiff=diff;
                //update minEle for next i value
                minElem=min(minElem,nums[i]);
        }
        cout<<maxDiff;
}
