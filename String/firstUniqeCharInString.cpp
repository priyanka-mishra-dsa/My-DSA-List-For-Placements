class Solution {
public:
    int firstUniqChar(string s) {
        //count the freq of each char of string
        vector<int>countFreq(26,0);
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            countFreq[ch-'a']++;
        }
        //itereate on original string and jiski first char ki freq 1 hai return uska index
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(countFreq[ch-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
};
