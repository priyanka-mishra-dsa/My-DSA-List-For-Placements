#include<bits/stdc++.h>
using namespace std;
int main()
{
        int N;
        cin>>N;
        vector<int>nums(N);
        for(int i=0;i<N;i++)
        {
                cin>>nums[i];
        }
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<N;i++)
        {
                m[nums[i]]++;
        }
        for(auto it:m)
        {
                if(it.second>=N/2)
                ans.push_back(it.first);
        }
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
        //if we have to maintain order in that case sort the array
}
