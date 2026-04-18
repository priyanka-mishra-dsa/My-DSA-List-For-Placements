class Solution {
public:
    bool checkIfPangram(string sentence) {
        //count freq of each 26 letter
        vector<bool>alpha(26,0);
        for(int i=0;i<sentence.size();i++)
        {
            char ch=sentence[i];
            alpha[ch-'a']=1;
        }
        for(int i=0;i<26;i++)
        {
            if(alpha[i]==0)
            return false;
        }
        return true;
    }
};
