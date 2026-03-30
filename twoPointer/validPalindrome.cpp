class Solution {
public:
bool isAlphaNumeric(char &ch)
{
    if(ch>='0'&&ch<='9' ||tolower(ch)>='a'&&tolower(ch)<='z')
    return true;
    return false;
}
    bool isPalindrome(string s) {
        int n=s.size();
        //take 2 pointer
        int i=0,j=n-1;
        while(i<j)
        {
            //check that each char is an alphanumeric char or not
            //convert uppercase letter into lowercase letter
            if(!isAlphaNumeric(s[i]))
            {
                //if i pointer is not pointing alphanumeric char then move i pointer
                i++;
                continue;
            }
            if(!isAlphaNumeric(s[j]))
            {
                //if j pointer is not pointing alphanumeric char then move j pointer
                j--;
                continue;
            }
            //if both pointer points same char
            if(tolower(s[i])==tolower(s[j]))
            {
                i++;
                j--;
            }
            else
            return false;
        }
        return true;
        
    }
};
