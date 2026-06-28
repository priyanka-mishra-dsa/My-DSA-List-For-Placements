#include<bits/stdc++.h>
using namespace std;
int main()
{
        int N;
        cin>>N;
        //main logic
        //store all the divisors of N in vector
        //check in range [1,N-1]
        vector<int>divi;
        for(int i=1;i<N;i++)
        {
                if(N%i==0)
                {
                        divi.push_back(i);
                }
        }
        //calculate sum of all divisors of N
        int sum=0;
        for(int i=0;i<divi.size();i++)
        {
                sum=sum+divi[i];
        }
        //compare karo
        if(sum==N)
        cout<<"true";
        else
        cout<<"false";
}
