class Solution {
public:
bool isPalindrome(string &s,int first,int second)
{
    while(first<second)
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
        //use 2 pointer
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                //move pointers
                i++;
                j--;
            }
            else if(s[i]!=s[j])
            {
                //delete one char when i and j wali value not equal
                //after deleting one char string should be palindrome
               return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
            }
        }
        return true;
    }
};
