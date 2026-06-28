#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
        //base case
        if(n<=1)
        return false;
        //fo pn->check in range[2,n-1] that n is divisible or not
        for(int i=2;i<=n-1;i++)
        {
                if(n%i==0)
                return false;
        }
        return true;
}
int digitSum(int n)
{
        int sum=0,rem=0;
        while(n>0)
        {
             rem=n%10;
             sum=sum+rem;
             n=n/10;
        }
        return sum;
}
int main()
{
        int nn,mm;
        cin>>nn>>mm;
        //main logic
        //[nn,mm]range ke all no check krna hai ki prime hai ya nhi
        //make function for finding prime no
        for(int i=nn;i<=mm;i++)
        {
                int no=i;
                bool primeNo=isPrime(no);
                if(primeNo==true)
                {
                        //now try to find sum of digits of prime no
                        int sumDigit=digitSum(primeNo);
                        //check that sum of digit is a prime no or not
                        if(isPrime(sumDigit)==true)
                        {
                                cout<<no;
                        }
                        
                }
        }
}
