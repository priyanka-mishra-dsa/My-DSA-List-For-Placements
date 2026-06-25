#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin>>n;
        //1.count no of digits in given number
        int temp=abs(n);
        int digit=0;
        int sum=0,rem=0;
        while(temp>0)
        {
                digit++;
                rem=temp%10;
                sum=sum+rem;
                temp=temp/10;
        }
        if(digit==3)
        {
                cout<<n<<"three digit number";
        }
        //2.check that 3 digit no is divisible by 
        if(sum%9==0)
        {
                cout<<"3 digit no is divisible by 9";
        }
        else
        cout<<"but not divisible by 9";
        
}
