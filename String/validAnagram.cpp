class Solution {
public:
    bool isAnagram(string s, string t) {
        //two string is anagram =>if both string contains same char whose freq is same in both string
        if(s.size()!=t.size())
        return false;
        //count freq of char
        //for string s increment freq of char
        //for string t decrement freq of char
        //if s and t contains same char then freq of char becomes 0
        //if all the freq of char =0 that means it is an anagram
        vector<int>countFreq(26,0);
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            countFreq[ch-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            char ch=t[i];
            countFreq[ch-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(countFreq[i]!=0)
            {
                return false;
            }
        }
        return true;     
    }
};
