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
        //main logic of the problem
        sort(nums.begin(),nums.end());
        int maxProduct=nums[0]*nums[1]*nums[n-1];
        cout<<maxProduct;
}
