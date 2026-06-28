#include<bits/stdc++.h>
using namespace std;
int main()
{
        int N;
        cin>>N;
        vector<int>nums(N-1);
        for(int i=0;i<N-1;i++)
        {
                cin>>nums[i];
        }
        //main logic
        //find sum of 1toN(1+2+3+4...+N)
        int expectedSum=N*(N+1)/2;
        //one no is missing
        //calcualte actual sum
        int acutalSum=0;
        for(int i=0;i<N-1;i++)
        {
                acutalSum=acutalSum+nums[i];
        }
        int missingValue=expectedSum-acutalSum;
        cout<<missingValue;
}
