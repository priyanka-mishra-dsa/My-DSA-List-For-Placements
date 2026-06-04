#include<iostream>
using namespace std;
int main()
{
        int n;
        cin>>n;
        int m;
        cin>>m;
        int sum=0;
        for(int i=n;i<=m;i++)
        {
            int cube=i*i*i;
            sum=sum+cube;
        }
        cout<<sum;
}
