class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<int>ans;
        vector<int>freqP(26,0);
        vector<int>freqS(26,0);
        //store freq of p string
        for(int i=0;i<m;i++)
        {
            char ch=p[i];
            freqP[ch-'a']++;
        }
        //apply sliding window and count freq of s 
        //and at the end compare freq of both the string
        int i=0;
        for(int j=0;j<n;j++)
        {
            freqS[s[j]-'a']++;
            //maintain window size to m leng
            if(j-i+1>m)
            {
                //window ki size choti karo
                freqS[s[i]-'a']--;
                i++;
            }
            //compare freq
            if(freqP==freqS)
            {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};
