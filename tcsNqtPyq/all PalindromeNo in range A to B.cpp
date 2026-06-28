#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{
        int start=0,end=s.size()-1;
        while(start<end)
        {
                if(s[start]==s[end])
                {
                        start++;
                        end--;
                }
                else
                return false;
        }
        return true;
}
int main()
{
        int A,B;
        cin>>A>>B;
        //main logic
        //find Palindrome no b/w range [A,B]
        for(int i=A;i<=B;i++)
        {
                int no=i;
                //convert into the string
                string s=to_string(no);
                //pass s into palindrome function
                bool palindromeNo=isPalindrome(s);
                if(palindromeNo==true)
                {
                        cout<<no<<" ";
                }
        }
        
}
