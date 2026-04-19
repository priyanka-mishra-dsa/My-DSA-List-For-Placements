class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //check krna pdega kis char of magazine uske kr liye hai one time and which char is still available
        vector<int>countCharFreq(26,0);
        for(int i=0;i<magazine.size();i++)
        {
            char ch=magazine[i];
            countCharFreq[ch-'a']++;
        }
        //now use all available letter to make(build) ransomNote
        for(int i=0;i<ransomNote.size();i++)
        {
            char ch=ransomNote[i];
            //check that ch of ransome is present on magazine or not
            if(countCharFreq[ch-'a']!=0)
            {
                //present hai
                //dec freq of ch of magazine by 1
                //because we used it one time
                countCharFreq[ch-'a']--;
            }
            else if(countCharFreq[ch-'a']==0)
            {
                //char is not present in magazine
                return false;
            }
        }
        return true;
    }
};
