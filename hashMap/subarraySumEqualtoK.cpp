//tcs nqt
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
        int prefixSum=0;
        unordered_map<int,vector<int>>m;
        m[0].push_back(-1);
        for(int i=0;i<n;i++)
        {
                prefixSum=prefixSum+arr[i];
                //find prev prefix
                int prevPrefixSum=prefixSum-k;
                if(m.count(prevPrefixSum))
                {
                        vector<int>indexes=m[prevPrefixSum];
                        //print all subarray
                        for(int j=0;j<indexes.size();j++)
                        {
                                //start index of subarray in original subarray
                                int start=indexes[j]+1;
                                for(int x=start;x<=i;x++)
                                {
                                        cout<<arr[x]<<" ";
                                }
                                cout<<endl;
                        }
                }
                //all prefix ko insert into the unordered_map
                m[prefixSum].push_back(i);
                
        }
        
        
}
