class Solution {
  public:
    bool isPalindrome(string& s) {
        int first=0;
        int second=s.size()-1;
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
};
