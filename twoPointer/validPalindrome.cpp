class Solution {
public:
bool isAlphaNumeric(char ch)
{
    if(ch>='0'&& ch<='9' ||tolower(ch)>='a'&& tolower(ch)<='z')
    return true;
    else
    return false;
}
    bool isPalindrome(string s) {
        int n=s.size();
        int first=0;
        int second=n-1;
        while(first<second) 
        {
            if(!isAlphaNumeric(s[first]))
            {
                first++;
            }
            else if(!isAlphaNumeric(s[second]))
            {
                second--;
            }
            else if(tolower(s[first])==tolower(s[second]))
            {
                first++;
                second--;
            }
            else
            {
                return false;
            }
        }
        return true;  
    }
};
