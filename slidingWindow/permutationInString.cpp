class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        //edge case
        if(n>m)
        {
            return false;
        }
        //make a vector to store both string frequency
        vector<int>freqS1(26,0);
        vector<int>freqS2(26,0);
        //count freq of s1
        for(int i=0;i<n;i++)
        {
            char ch=s1[i];
            freqS1[ch-'a']++;
        }
        //apply sliding window on s2
        int i=0;
        for(int j=0;j<m;j++)
        {
            freqS2[s2[j]-'a']++;
            if(j-i+1>n)
            {
                freqS2[s2[i]-'a']--;
                i++;
            }
            if(freqS1==freqS2)
            return true;
        }
        return false;
    }
};
