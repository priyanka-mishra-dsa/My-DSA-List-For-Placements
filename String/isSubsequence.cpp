class Solution {
public:
    bool isSubsequence(string s, string t) {
        //take one pointer on the oth index of both the string
        int i=0;
        int j=0;
        while(i<s.size()&&j<t.size())
        {
            if(s[i]==t[j])
            {
                //move pointers
                i++;
                j++;
            }
            else if(s[i]!=t[j])
            {
                //move j pointer
                j++;
            }
        }
        if(i==s.size())
        return true;
        else
        return false;
    }
};
