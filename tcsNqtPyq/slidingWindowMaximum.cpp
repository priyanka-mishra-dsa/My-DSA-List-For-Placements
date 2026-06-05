#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int k;
        cin>>k;
        //main logic
        vector<int>ans;
        priority_queue<pair<int,int>>p;
        int i=0;
        for(int j=0;j<n;j++)
        {
                //push current element in the heap
                p.push({arr[j],j});
                if(j-i+1>k)
                {
                        i++;
                }
                while(!p.empty() && p.top().second<i)
                {
                        p.pop();
                }
                if(j-i+1==k)
                {
                        int maxEle=p.top().first;
                        ans.push_back(maxEle);
                }
        }
        //print max element of every subarray which is present at ans vector
        for(int i=0;i<ans.size();i++)
        {
                cout<<ans[i]<<" ";
        }
}
