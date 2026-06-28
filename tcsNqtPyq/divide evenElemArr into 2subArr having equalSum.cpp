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
        //find total sum
        int totalSum=0;
        for(int i=0;i<n;i++)
        {
                totalSum=totalSum+nums[i];
        }
        //cal leftsum and rightsum
        int leftsum=0,rightsum=0;
        for(int i=0;i<n-1;i++)
        {
                rightsum=totalSum-leftsum;
                if(leftsum==rightsum)
                {
                        cout<<"true";
                        return 0;//for stoping the bottom code 
                }
                 //for next i update leftsum value
                leftsum=leftsum+nums[i];
        }
        cout<<"false";
}
