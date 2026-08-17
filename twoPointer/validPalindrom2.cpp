class Solution {
public:
bool isPalindrome(string &s,int first,int second)
{
    while(first<=second)
    {
        if(s[first]==s[second])
        {
            first++;
            second--;
        }
        else if(s[first]!=s[second])
        {
            return false;
        }
    }
    return true;
}
    bool validPalindrome(string s) {
        int n=s.size();
        int first=0;
        int second=n-1;
        while(first<second)
        {
            if(s[first]==s[second])
            {
                first++;
                second--;
            }
            else if(s[first]!=s[second])
            {
                //possible 2 chars to delete 
                //"abca"->bc
                //delete b
                return(isPalindrome(s,first+1,second)||isPalindrome(s,first,second-1));
            }
        } 
        return true;  
    }
};
